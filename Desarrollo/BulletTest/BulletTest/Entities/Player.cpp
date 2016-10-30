#include "stdafx.h"
#include "Player.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "math.h"




Player::Player() : Entity(-1, NULL, "Player"), m_speedFactor(30)
{
	
}


Player::~Player()
{
	m_renderState.setVelocity(Vec3<float>(m_speedFactor, m_speedFactor, m_speedFactor));
}

void Player::inicializar()
{
	vectorPrev = vectorNew = Vec3<float>(0, 0, 0);
	giro = 0;
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



	//float giro = acos(
		//( vectorNew.getX()*vectorPrev.getX() + vectorNew.getZ()*vectorPrev.getZ() ) /
		//(sqrt(pow(vectorNew.getX(),2)+pow(vectorNew.getZ(),2)) * sqrt(pow(vectorPrev.getX(), 2) + pow(vectorPrev.getZ(), 2)))
	//);

	vectorNew.normalise();//normalizamos los vectores
	vectorPrev.normalise();

	if(vectorNew.getX()!=0 && vectorPrev.getX()!=0){//comprobamos posibles errores matematicos(division entre 0)
	float giroactual =  atan(vectorNew.getZ()/ vectorNew.getX())- atan(vectorPrev.getZ() / vectorPrev.getX());//generamos el angulo entre los vectores
	giroactual *= RADTODEG;//lo pasamos a grados

	if (abs(giroactual) > 90)//entra aqui cuando no has girado tanto... NOSE QUE PASA
		printf("------SE NOS VA A LA MIERDA-----\n");

	giro = giro-giroactual;//aumentamos la variable giro acumulativa para setearla y se comprueba que esta en el rango -180 180
	if (giro < -180)
		giro = giro + 180;
	if (giro > 180)
		giro = giro - 180;
	


	printf("GIRO %f\n", giro);
	
	//}
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