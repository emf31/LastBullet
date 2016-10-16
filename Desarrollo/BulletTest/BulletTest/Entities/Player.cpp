#include "stdafx.h"
#include "Player.h"


Player::Player() : Entity(-1, NULL, "Player")
{
}


Player::~Player()
{
}

void Player::inicializar()
{
}

void Player::update(Time elapsedTime)
{
	Vec3<float> speedFinal;
	Vec3<float> vector = Vec3<float>(0.f, 0.f, 0.f);

	//isMovingRight = true;

	if (isMovingForward)
		vector.addX(1.f);
	if (isMovingBackward)
		vector.addX(-1.f);
	if (isMovingLeft)
		vector.addZ(1.f);
	if (isMovingRight)
		vector.addZ(-1.f);

	m_renderState.setVelocity(vector);

		Vec3<float> target = Vec3<float>(
			irrScene->getActiveCamera()->getTarget().X,
			irrScene->getActiveCamera()->getTarget().Y,
			irrScene->getActiveCamera()->getTarget().Z
			);

		Vec3<float> posicion = Vec3<float>(m_nodo->getPosition().X, m_nodo->getPosition().Y, m_nodo->getPosition().Z);
		Vec3<float> speed = target - posicion;
		speedFinal = Vec3<float>(0, 0, 0);

		if (isMovingForward) {
			speedFinal.setX(speedFinal.getX() + speed.getX());
			speedFinal.setZ(speedFinal.getZ() + speed.getZ());
		}
		if (isMovingBackward) {
			speedFinal.setX(speedFinal.getX() - speed.getX());
			speedFinal.setZ(speedFinal.getZ() - speed.getZ());
		}
		if (isMovingLeft) {
			speedFinal.setX(speedFinal.getX() - speed.getZ());
			speedFinal.setZ(speedFinal.getZ() + speed.getX());
		}
		if (isMovingRight) {
			speedFinal.setX(speedFinal.getX() + speed.getZ());
			speedFinal.setZ(speedFinal.getZ() - speed.getX());
		}
		speedFinal.normalise();
		m_rigidBody->setLinearVelocity(btVector3(speedFinal.getX()*m_speedFactor, speedFinal.getY(), speedFinal.getZ()*m_speedFactor));


	if (isJumping && tiempoSalto.getElapsedTime().asSeconds() > 3) {
		m_rigidBody->setLinearVelocity(btVector3(0, 7, 0));
		tiempoSalto.restart();
	}

	// Set position
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

void Player::cargarContenido()
{
}

void Player::borrarContenido()
{
}
