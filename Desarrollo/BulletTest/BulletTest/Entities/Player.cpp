#include "stdafx.h"
#include "Player.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "math.h"




Player::Player() : Entity(-1, NULL, "Player"), m_speedFactor(30)
{
	vectorPrev = vectorNew = Vec3<float>(0, 0, 0);
	mousePrev = mouseNew = MastEventReceiver::i().mouseX();
	giro = 0;
}


Player::~Player()
{
	m_renderState.setVelocity(Vec3<float>(m_speedFactor, m_speedFactor, m_speedFactor));
}

void Player::inicializar()
{

}

void Player::update(Time elapsedTime)
{
	Vec3<float> speedFinal;
	const float jump_gain = 200.0f;

	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	vectorNew = speed;
	
	speedFinal = Vec3<float>(0, 0, 0);
	bool isMoving = false;

	if (isMovingForward) {
		speedFinal.setX(speedFinal.getX() + speed.getX());
		speedFinal.setZ(speedFinal.getZ() + speed.getZ());
		isMoving = true;
	}
	if (isMovingBackward) {
		speedFinal.setX(speedFinal.getX() - speed.getX());
		speedFinal.setZ(speedFinal.getZ() - speed.getZ());
		isMoving = true;
	}
	if (isMovingLeft) {
		speedFinal.setX(speedFinal.getX() - speed.getZ());
		speedFinal.setZ(speedFinal.getZ() + speed.getX());
		isMoving = true;
	}
	if (isMovingRight) {
		speedFinal.setX(speedFinal.getX() + speed.getZ());
		speedFinal.setZ(speedFinal.getZ() - speed.getX());
		isMoving = true;
	}

	if (isMoving) {
		speedFinal.normalise();
		m_renderState.setDirection(speedFinal);
		m_renderState.setAccelerating(true);
	}
	else {
		m_renderState.setAccelerating(false);
	}

	
	m_renderState.updateVelocity(elapsedTime.asSeconds());
	m_rigidBody->setLinearVelocity(btVector3(m_renderState.getVelocity().getX(), m_renderState.getVelocity().getY(), m_renderState.getVelocity().getZ()));





	if (isJumping) {

	}

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


	bool direccion=1;


	vectorNew.normalise();//normalizamos los vectores
	vectorPrev.normalise();


		float m1 = vectorNew.getZ() / vectorNew.getX();//pendiente del 1
		float m2 = vectorPrev.getZ() / vectorPrev.getX();//pendiente del 2
		float giroactual3 = atan((m1-m2)/(1+(m1*m2)));//calculo del angulo entre 2 rectas
		giroactual3 *= RADTODEG;//lo pasamos a grados

		if(giroactual3>=-360 && giroactual3<360 ){
			giro = giro-giroactual3;//aumentamos la variable giro acumulativa para setearla y se comprueba que esta en el rango 0 360

			if (giro <360)
				giro = giro + 360;
			if (giro > 360)
				giro = giro - 360;
	

	}
	m_renderState.updateRotations(Vec3<float>(0, giro, 0));
}

void Player::handleInput()
{
	isMovingForward = MastEventReceiver::i().keyDown(KEY_KEY_W);
	isMovingBackward = MastEventReceiver::i().keyDown(KEY_KEY_S);
	isMovingLeft = MastEventReceiver::i().keyDown(KEY_KEY_A);
	isMovingRight = MastEventReceiver::i().keyDown(KEY_KEY_D);

	isJumping = MastEventReceiver::i().keyDown(KEY_SPACE);
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(50.f, 50.f, 50.f), "../media/textureMan.bmp","../media/MeshPlayer.obj");
	//m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(50.f, 50.f, 50.f), "../media/textureMan.jpg", "");

	m_renderState.setPosition(Vec3<float>(0, 500, 0));

	//Creas el body(fisico) 
	m_rigidBody = PhysicsEngine::createBoxRigidBody(this, Vec3<float>(100.f, 100.f, 100.f), 1.0f, DISABLE_DEACTIVATION);
}

void Player::borrarContenido()
{
	//No se si aqui habria que hacer delete al nodo porque igual se encarga irrlitch
	delete m_nodo;
}

void Player::handleMessage(const Message & message)
{
}

void Player::jump() {
	if (!jumped) {
		m_rigidBody->applyCentralForce(btVector3(0, 400, 0));

		jumped = true;
		printf("Ha saltado\n");

	}

}