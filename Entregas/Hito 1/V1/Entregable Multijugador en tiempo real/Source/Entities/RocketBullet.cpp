#include <RocketBullet.h>
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Util.h>
#include <Cliente.h>


#include <list>

//Clase que representa un misil disparado por un rocketLauncher. Cuando colisiona con algun otro objeto,
//comprueba mediante un radio de explosion si ha impactado con algun jugador. Esta clase es responsable
//de liberar todos los recursos asignados a ella cuando colisiona con algun objeto o cuando termina su tiempo de vida.

RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(160), m_rotation(rotation), radioExplosion(45)
{

	m_lifetime = seconds(5);

}


RocketBullet::~RocketBullet()
{
}

void RocketBullet::inicializar()
{
}

void RocketBullet::update(Time elapsedTime)
{
	//TODO cuando pase mucho tiempo hay que destruir el rocketbullet

	btVector3 aux(m_direction.getX(), m_direction.getY(), m_direction.getZ());
	m_rigidBody->setLinearVelocity(aux*m_velocity);

	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));


	if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds()) {

		//Enviamos mensaje de borrado para no borrar la entity mientras iteramos el mapa de entities
		Message msg1(this, "BORRATE", NULL);
		MessageHandler::i().sendMessage(msg1);
	}
}

void RocketBullet::handleInput()
{
}

void RocketBullet::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(1, 1, 1), "", "../media/bullets/rocketbullet.obj");
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);
	m_renderState.setRenderRot(m_rotation);

	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1.f, 1.f, 1.f), 1, false);
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Rocket;
	proxy->m_collisionFilterMask = col::rocketCollidesWith;

	//Sin respuesta a la colision mejor asi porque es mas optimo
	m_rigidBody->setCollisionFlags(4);
}

void RocketBullet::borrarContenido()
{
}


void RocketBullet::handleMessage(const Message & message)
{

	float damage = 0;

	//Si llega un mensaje de colision o de borrado ejecutamos las comprobaciones necesarias
	if (message.mensaje == "COLLISION" || message.mensaje == "BORRATE") {

			std::list<Entity*>characters = EntityManager::i().getCharacters();
			///Explosion
			for (std::list<Entity*>::iterator it = characters.begin(); it != characters.end(); it++) {

				Entity* myentity = *it;

				damage = explosion(myentity, cons(m_rigidBody->getCenterOfMassPosition()), radioExplosion) / 3.f;

				if (Cliente::i().isConected()) {
					if (damage > 0) {

						if (myentity->getID() == PLAYER) {
							TImpactoRocket* selfImpact = new TImpactoRocket();
							selfImpact->damage = damage;
							selfImpact->guidDisparado = myentity->getGuid();
							selfImpact->guidImpactado = myentity->getGuid();
							
							Message msg(myentity, "COLISION_ROCKET", selfImpact);
							MessageHandler::i().sendMessage(msg);

						}
						else {
							TImpactoRocket* impact = new TImpactoRocket();
							impact->damage = damage;
							impact->guidDisparado = EntityManager::i().getEntity(PLAYER)->getGuid();
							impact->guidImpactado = myentity->getGuid();;
							Message msg(myentity, "COLISION_ROCKET", impact);
							MessageHandler::i().sendMessage(msg);

						}

					}
				}
				else {

					//TODO cuando haya IA habra que hacer una comprobacion extra
					static_cast<Player*>(myentity)->getLifeComponent().restaVida(damage);

					//TODO si estas jugando en un solo player aqui tendras que quitarle vida a la IA
				}

			}

			PhysicsEngine::i().removeRigidBody(m_rigidBody);

			GraphicEngine::i().removeNode(m_nodo);

			EntityManager::i().removeEntity(this);
	}



}

bool RocketBullet::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

std::string RocketBullet::getClassName()
{
	return "RocketBullet";
}

void RocketBullet::setPosition(const Vec3<float>& pos)
{
}

//Calcula la el daño que hace la explosion de un rocket en funcion del punto
//de impacto, la posicion del player impactado y un radio de alcance. Además aplica un impulso
//y en caso de ser un enemigo lo comunica al servidor.
float RocketBullet::explosion(Entity* player, const Vec3<float>& posExplosion, float radio)
{
	float vidaRestada = 0;

	Vec3<float> vector = posExplosion - player->getRenderPosition();
	float distancia = vector.Magnitude();
	if (distancia < radio) {
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			vidaRestada = 100 * ((radio - distancia) / ((2 * radio) / 3));
		}


		btVector3 FUERZA(vidaRestada, vidaRestada, vidaRestada);

		Vec3<float> posExplosion = cons(m_rigidBody->getCenterOfMassPosition());
		Vec3<float> posPlayer = player->getRenderPosition();

		Vec3<float> direccion = posPlayer - posExplosion;
		direccion.normalise();

		btVector3 force = bt(direccion) * FUERZA;

		//Si es el player aplicamos el impulso al player
		if (player->getClassName() == "Player") {
			static_cast<Player*>(player)->p_controller->applyImpulse(force);
		}
		//Si no es un enemigo y hay que notificar al server de ese impulso
		else if (Cliente::i().isConected()) {
			TImpulso impulso;
			impulso.fuerza = cons(force);
			impulso.guid = player->getGuid();
			Cliente::i().dispatchMessage(impulso, APLICAR_IMPULSO);
			//Cliente::i().aplicarImpulso(Vec3<float>(force.x(), force.y(), force.z()), player->getGuid());
		}

	}

	return vidaRestada;

}
