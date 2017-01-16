#include <RocketBullet.h>
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Util.h>
#include <Cliente.h>


#include <list>



RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(125), m_rotation(rotation), radioExplosion(30)
{
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

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;

	m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));
}

void RocketBullet::handleInput()
{
}

void RocketBullet::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(1, 1, 1), "../media/redTexture.jpg", "");
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);


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

	if (message.mensaje == "COLLISION") {

		if (estado == DISPONIBLE) {

			std::list<Entity*>characters = EntityManager::i().getCharacters();
			///Explosion
			for (std::list<Entity*>::iterator it = characters.begin(); it != characters.end(); it++) {

				Entity* myentity = *it;

				damage = explosion(myentity, cons(m_rigidBody->getCenterOfMassPosition()), myentity->getRenderPosition(), radioExplosion) / 3.f;

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
							impact->guidDisparado = myentity->getGuid();
							impact->guidImpactado = EntityManager::i().getEntity(PLAYER)->getGuid();
							Message msg(myentity, "COLISION_ROCKET", impact);
							MessageHandler::i().sendMessage(msg);

						}

					}
				}
				else {

					//TODO cuando haya IA habra que hacer una comprobacion extra
					static_cast<Player*>(myentity)->getLifeComponent()->restaVida(damage);

					//TODO si estas jugando en un solo player aqui tendras que quitarle vida a la IA
				}

			}

			PhysicsEngine::i().removeRigidBody(m_rigidBody);

			GraphicEngine::i().removeNode(m_nodo);

			EntityManager::i().removeEntity(this);
		}


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

float RocketBullet::explosion(Entity* player, Vec3<float> posExplosion, Vec3<float> posCharacter, float radio)
{
	float vidaRestada = 0;

	Vec3<float> vector = posExplosion - posCharacter;
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
