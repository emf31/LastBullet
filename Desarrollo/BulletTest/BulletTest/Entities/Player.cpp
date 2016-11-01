#include "stdafx.h"
#include "Player.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "math.h"




Player::Player() : Entity(-1, NULL, "Player"), m_speedFactor(30)
{
	vectorPrev = vectorNew = Vec3<float>(0, 0, 0);
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
		//printf("Direction: X=%f Y=%f\n", speedFinal.getX(), speedFinal.getZ());
		m_renderState.setDirection(speedFinal);
		m_renderState.setAccelerating(true);
	}
	else {
		m_renderState.setAccelerating(false);
	}

	
	m_renderState.updateVelocity(elapsedTime.asSeconds());
	m_rigidBody->setLinearVelocity(btVector3(m_renderState.getVelocity().getX(), m_renderState.getVelocity().getY(), m_renderState.getVelocity().getZ()));

	// Set position
	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;


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
	//isMovingForward = MastEventReceiver::i().keyDown(KEY_KEY_W);
	/*isMovingBackward = MastEventReceiver::i().keyDown(KEY_KEY_S);
	isMovingLeft = MastEventReceiver::i().keyDown(KEY_KEY_A);
	isMovingRight = MastEventReceiver::i().keyDown(KEY_KEY_D);*/

	//isJumping = MastEventReceiver::i().keyDown(KEY_SPACE);
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

	if (isJumping == false){



	btVector3 start = m_rigidBody->getCenterOfMassPosition(); // posicion del player
	btVector3 dest = start;

	dest.setY(dest.getY() - 50.0f);  //destino del rayo, que es la posicion del player en y - 50 unidades



	btCollisionWorld::ClosestRayResultCallback ray(start, dest); // Creo el rayo con inicio y destino
	PhysicsEngine::m_world->rayTest(start, dest, ray);//hago el ray test

	if (ray.hasHit())//si ray a golpeado algo entro
	{
		printf( "hit something\n");

		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

		if (hit != m_rigidBody) 
		{
			/*btVector3 velocity = m_rigidBody->getLinearVelocity();//DISCUTIR: Con set linear velocity queda mejor, pero he encontrado mas ejemplos que lo hacen con applyimpulse o applyforce

			velocity.setY(velocity.getY() + 5.0f);

			m_rigidBody->setLinearVelocity(velocity);*/

			m_rigidBody->applyCentralForce(btVector3(0, 400, 0));

			isJumping = true;
		}
	}
	else
	{
		printf("missed\n"); 
	}

	}
	else {
		m_rigidBody->applyCentralForce(btVector3(0, 400, 0));
		isJumping = false;
	}

}

void Player::move(bool arriba, bool abajo, bool izq, bool der) {

		isMovingForward = arriba;
		isMovingRight = der;
		isMovingLeft = izq;
		isMovingBackward = abajo;

}

void Player::shoot() {



/*	btVector3 start = cameraPosition;
	btVector3 end = start + (cameraDirection * SIZE_OF_WORLD);*/

	printf("Shoot\n");
	btVector3 SIZE_OF_WORLD(150000, 150000, 150000);
	//btVector3 start = GraphicEngine::i().getActiveCamera()->getPosition();
	btVector3 start(
		GraphicEngine::i().getActiveCamera()->getPosition().getX(),
			GraphicEngine::i().getActiveCamera()->getPosition().getY(),
				GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

	Vec3<float> varMolto= GraphicEngine::i().getActiveCamera()->getTarget();
	varMolto.normalise();

	btVector3 targetCamera(varMolto.getX(), varMolto.getY(), varMolto.getZ());


	btVector3 end = start+(targetCamera * SIZE_OF_WORLD);

	printf("Start: X=%f Y=%f Z=%f\n", start.getX(), start.getZ(), start.getY());

	printf("Target: X=%f Y=%f Z=%f\n", targetCamera.getX(), targetCamera.getZ(), targetCamera.getY());

	printf("Direction: X=%f Y=%f Z=%f\n", end.getX(), end.getZ(),end.getY());

	btCollisionWorld::ClosestRayResultCallback ray(start, end);

	PhysicsEngine::m_world->rayTest(start, end, ray);

	if (ray.hasHit())//si ray a golpeado algo entro
	{

		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

		if (hit != m_rigidBody)
		{

			printf("hit something\n");


		}
	}


}