#include "RocketBullet.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"

#include <list>



RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(65), m_rotation(rotation), radioExplosion(40)
{

	//NOTA: llevar cuidado con esto puede que pete aqui
	cargarContenido();
}


RocketBullet::~RocketBullet()
{
}

void RocketBullet::inicializar()
{
}

void RocketBullet::update(Time elapsedTime)
{
	//m_renderState.updateVelocity(elapsedTime.asSeconds(), (m_direction*m_velocity));
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
	/*if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds() || timelifeclock.getElapsedTime().asSeconds() > 4) {
		//EntityManager::i().removeEntity(this);
		printf("Explosion en %f %f %f\n",m_renderState.getPosition().getX(), m_renderState.getPosition().getY(), m_renderState.getPosition().getZ());

		Message msg1(this, "BORRATE", NULL);

		MessageHandler::i().sendMessage(msg1);
	}
	*/
}

void RocketBullet::handleInput()
{
}

void RocketBullet::cargarContenido()
{
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createNode(m_position, Vec3<float>(1, 1, 1), "../media/redTexture.jpg", ""));
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);
	m_renderState.setRenderRot(m_rotation);

	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1.f, 1.f, 1.f), 1);

	radioExplosion = 40.f;
}

void RocketBullet::borrarContenido()
{
}

void RocketBullet::handleMessage(const Message & message)
{


	if (message.mensaje == "COLLISION") {

	//	m_explosion = PhysicsEngine::i().createSphereShape(this, 40.f);
		//m_explosion =PhysicsEngine::i().createSphereShape(this, radioExplosion);
		if (static_cast<Entity*>(message.data)->getClassName() != "Player") {

			list<Entity*>characters = EntityManager::i().getCharacters();
			///Explosion
			for (list<Entity*>::Iterator it = characters.begin(); it != characters.end(); it++) {

				Entity* myentity = *it;
				myentity->restaVida(explosion(m_renderState.getPosition(), myentity->getRenderPosition(), radioExplosion));

			}

			PhysicsEngine::i().removeRigidBody(m_rigidBody);

			EntityManager::i().removeEntity(this);
		}

	}
}

std::string RocketBullet::getClassName()
{
	return "RocketBullet";
}

float RocketBullet::explosion(Vec3<float> posExplosion, Vec3<float> posCharacter, float radio)
{
	float vidaRestada = 0;

	Vec3<float> vector = posExplosion - posCharacter;
	float distancia = vector.Magnitude();
	if (distancia < radio) {
		printf("Te ha dado la explosion\n");
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			//(radio-distancia)/((2*radio)/3)
			vidaRestada = 100 * ((radio - distancia) / ((2 * radio) / 3));

		}
	}
	else {
		printf("NO te ha dado la explosion\n");

	}

	return vidaRestada;

}
