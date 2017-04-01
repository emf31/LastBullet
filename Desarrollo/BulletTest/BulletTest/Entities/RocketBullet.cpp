#include <RocketBullet.h>
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Util.h>
#include <NetworkManager.h>


#include <list>

//Clase que representa un misil disparado por un rocketLauncher. Cuando colisiona con algun otro objeto,
//comprueba mediante un radio de explosion si ha impactado con algun jugador. Esta clase es responsable
//de liberar todos los recursos asignados a ella cuando colisiona con algun objeto o cuando termina su tiempo de vida.

RocketBullet::RocketBullet(Character* owner, Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : EntActive(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(60), m_rotation(rotation), radioExplosion(5), m_owner(owner)
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
	m_renderState.updatePositions(Vec3<float>((float)Point[0], (float)Point[1], (float)Point[2]));

	m_renderState.setRotation(m_nodo->getRotation());


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
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(0.3f, 0.3f, 0.3f), "", "../media/bullets/rocketbullet.obj");
	m_renderState.setPosition(m_position);
	m_nodo->setRotationXYZ(m_rotation);

	//m_rotation.display();
	//m_renderState.setRenderRot(m_rotation);

	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(0.5f, 0.3f, 0.2f), 1, false);
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Rocket;
	proxy->m_collisionFilterMask = col::rocketCollidesWith;

	//Sin respuesta a la colision mejor asi porque es mas optimo
	m_rigidBody->setCollisionFlags(4);
}

void RocketBullet::borrarContenido()
{
	GraphicEngine::i().removeNode(m_nodo);
}


void RocketBullet::handleMessage(const Message & message)
{

	float damage = 0;

	//Si llega un mensaje de colision o de borrado ejecutamos las comprobaciones necesarias
	if (message.mensaje == "COLLISION" || message.mensaje == "BORRATE") {


		std::list<Character*>characters = EntityManager::i().getCharacters();
		///Explosion
		for (std::list<Character*>::iterator it = characters.begin(); it != characters.end(); it++) {

			Character* myentity = *it;

			damage = explosion(myentity, cons(m_rigidBody->getCenterOfMassPosition()), radioExplosion) / 1.5f;

			std::cout << "Damage: " << damage << std::endl;

			if (damage > 0) {

				if (myentity->getID() == m_owner->getID()) {
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
					impact->guidDisparado = m_owner->getGuid();
					impact->guidImpactado = myentity->getGuid();;

					Message msg(myentity, "COLISION_ROCKET", impact);
					MessageHandler::i().sendMessage(msg);

				}

			}
		}


	}

	PhysicsEngine::i().removeRigidBody(m_rigidBody);

	EntityManager::i().removeEntity(this);
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
float RocketBullet::explosion(Character* player, const Vec3<float>& posExplosion, float radio)
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


		btVector3 FUERZA(vidaRestada / 3, vidaRestada / 3, vidaRestada / 3);

		Vec3<float> posExplosion = cons(m_rigidBody->getCenterOfMassPosition());
		Vec3<float> posPlayer = player->getRenderPosition();

		Vec3<float> direccion = posPlayer - posExplosion;
		direccion.normalise();

		btVector3 force = bt(direccion) * FUERZA;

		//Si es el player aplicamos el impulso al player
		if (player->getClassName() == "Player") {
			static_cast<Player*>(player)->p_controller->applyImpulse(force);
		}
		//Si es un enemigo y hay que notificar al server de ese impulso
		else {
			TImpulso impulso;
			impulso.fuerza = cons(force);
			impulso.guid = player->getGuid();
			NetworkManager::i().dispatchMessage(impulso, APLICAR_IMPULSO);
		}

	}

	return vidaRestada;

}
