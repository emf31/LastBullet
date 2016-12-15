#include "RocketBullet.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"
#include "../Otros/Util.h"
#include "../Motor de Red/Cliente.h"


#include <list>



RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(65), m_rotation(rotation), radioExplosion(40)
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
	radioExplosion = 40.f;
}

void RocketBullet::borrarContenido()
{
}

void RocketBullet::handleMessage(const Message & message)
{

	float damage = 0;

	if (message.mensaje == "COLLISION") {

		if (estado == DISPONIBLE) {

			list<Entity*>characters = EntityManager::i().getCharacters();
			///Explosion
			for (list<Entity*>::Iterator it = characters.begin(); it != characters.end(); it++) {

				Entity* myentity = *it;

				damage = explosion(myentity, cons(m_rigidBody->getCenterOfMassPosition()), myentity->getRenderPosition(), radioExplosion);

				if (Cliente::i().isConected()) {
					if (damage > 0) {

						if (myentity->getID() == PLAYER) {
							Cliente::i().impactoRocket(myentity->getGuid(), int(damage / 3), RakNet::UNASSIGNED_RAKNET_GUID);
						}
						else {
							Cliente::i().impactoRocket(myentity->getGuid(), int(damage), EntityManager::i().getEntity(PLAYER)->getGuid());
						}

					}
				}
				else {

					myentity->restaVida(damage);

					//TODO: si estas jugando en un solo player aqui tendras que quitarle vida a la IA
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


		btVector3 FUERZA(btScalar(vidaRestada / 2.3), btScalar(vidaRestada / 2.3), btScalar(vidaRestada / 2.3));

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
			Cliente::i().aplicarImpulso(Vec3<float>(force.x(), force.y(), force.z()), player->getGuid());
		}

	}

	return vidaRestada;

}
