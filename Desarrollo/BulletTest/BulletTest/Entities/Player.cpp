#include "stdafx.h"
#include "Player.h"
#include "../Motor/PhysicsEngine.h"
#include "../MastEventReceiver.hpp"


Player::Player(ISceneManager* escena) : Entity(-1, NULL, "Player"), m_escena(escena), m_speedFactor(30)
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
			m_escena->getActiveCamera()->getTarget().X,
			m_escena->getActiveCamera()->getTarget().Y,
			m_escena->getActiveCamera()->getTarget().Z
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

void Player::handleInput()
{
	isMovingForward = MastEventReceiver::i().keyDown(KEY_KEY_W);
	isMovingBackward = MastEventReceiver::i().keyDown(KEY_KEY_S);
	isMovingLeft = MastEventReceiver::i().keyDown(KEY_KEY_A);
	isMovingRight = MastEventReceiver::i().keyDown(KEY_KEY_D);
	isMovingForward = true;
}

void Player::cargarContenido()
{
	m_nodo = m_escena->addCubeSceneNode(1.0f);
	m_nodo->setScale(vector3df(0.5f, 2.f, 0.5f));
	m_nodo->setPosition(vector3df(0, 100, 0));
	//Asi no le afectan las luces
	m_nodo->setMaterialFlag(EMF_LIGHTING, false);
	//Node->setMaterialTexture(0, m_escena->getTexture("../media/rockwall.jpg"));
	m_rigidBody = PhysicsEngine::createBoxRigidBody(this, Vec3<float>(0.5f, 2.f, 0.5f), 1.0f);
}

void Player::borrarContenido()
{
	//No se si aqui habria que hacer delete al nodo porque igual se encarga irrlitch
}
