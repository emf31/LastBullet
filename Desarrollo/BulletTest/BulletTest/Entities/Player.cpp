
#include "Player.h"
#include "../Motor de Red/Cliente.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "../Handlers/MessageHandler.h"
#include "../Motor de Red/Estructuras.h"
#include "../Handlers/InputHandler.h"


Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Entity(1, NULL, name, guid), m_speedFactor(30)	//El player siempre tendra ID 1
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
	isMoving = false;
	speedFinal = Vec3<float>(0, 0, 0);

	// Ejecuta todos los comandos
	InputHandler::i().excuteCommands(this);


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
	float giroactual3 = atan((m1 - m2) / (1 + (m1*m2)));//calculo del angulo entre 2 rectas
	giroactual3 *= RADTODEG;//lo pasamos a grados

	if (giroactual3 >= -360 && giroactual3<360) {
		giro = giro - giroactual3;//aumentamos la variable giro acumulativa para setearla y se comprueba que esta en el rango 0 360

		if (giro <360)
			giro = giro + 360;
		if (giro > 360)
			giro = giro - 360;


	}
	m_renderState.updateRotations(Vec3<float>(0, giro, 0));

	Cliente::i().enviarPos(this);


	
}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 500, 0), Vec3<float>(100.f, 100.f, 100.f), "../media/earth.jpg");

	m_renderState.setPosition(Vec3<float>(0, 500, 0));

	//Creas el body(fisico) 
	m_rigidBody = PhysicsEngine::createBoxRigidBody(this, Vec3<float>(100.f, 100.f, 100.f), 1.0f, DISABLE_DEACTIVATION);

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);
}

void Player::borrarContenido()
{
	//No se si aqui habria que hacer delete al nodo porque igual se encarga irrlitch
	delete m_nodo;
}

void Player::handleMessage(const Message & message)
{
}

void Player::setPosition(Vec3<float> pos) {
	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}

void Player::jump() {

	bool isGrounded = false;

	btVector3 start = m_rigidBody->getCenterOfMassPosition(); // posicion del player
	btVector3 dest = start;

	dest.setY(dest.getY() - 50.0f);  //destino del rayo, que es la posicion del player en y - 50 unidades

	btCollisionWorld::ClosestRayResultCallback ray(start, dest); // Creo el rayo con inicio y destino
	PhysicsEngine::m_world->rayTest(start, dest, ray);//hago el ray test

	if (ray.hasHit())//si ray ha golpeado algo entro
	{
		//printf("hit something\n");

		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

		if (hit != m_rigidBody)
		{
			/*btVector3 velocity = m_rigidBody->getLinearVelocity();//DISCUTIR: Con set linear velocity queda mejor, pero he encontrado mas ejemplos que lo hacen con applyimpulse o applyforce

			velocity.setY(velocity.getY() + 5.0f);

			m_rigidBody->setLinearVelocity(velocity);*/

			numJumps = 0;
		}
	}


	if (numJumps < 2) {
		m_rigidBody->applyCentralForce(btVector3(0, 400, 0));
		numJumps++;
	}



}


void Player::shoot() {

	printf("Shoot\n");
	btVector3 SIZE_OF_WORLD(150000, 150000, 150000);

	btVector3 start(
		GraphicEngine::i().getActiveCamera()->getPosition().getX(),
		GraphicEngine::i().getActiveCamera()->getPosition().getY(),
		GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
	direccion.normalise();

	btVector3 targetCamera(target.getX(), target.getY(), target.getZ());
	btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

	btVector3 end = start + (direccion2*SIZE_OF_WORLD);

	btCollisionWorld::AllHitsRayResultCallback ray(start, end);

	PhysicsEngine::m_world->rayTest(start, end, ray);

	if (ray.hasHit())//si ray ha golpeado algo entro
	{


		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto


		if (hit != m_rigidBody)
		{

			for (int i = 0; i < ray.m_hitNormalWorld.capacity(); i++) {
				//printf("SIZE OF THE ARRAY OF HITS: %d \n", ray.m_hitNormalWorld.capacity());

				Entity* myEnt = static_cast<Entity*>(hit->getUserPointer());
				Message msg(myEnt, "COLISION_BALA", NULL);
				//TODO LLEVARLO AL HANDLERMENSAJE
				//Cliente::i().enviarDisparo(m_guid);
				MessageHandler::i().sendMessage(msg);


			}
			printf("hit something\n");

		}




	}
	
	
}


void Player::move_up()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	vectorNew = speed;

	speedFinal.addX(speed.getX());
	speedFinal.addZ(speed.getZ());

	isMoving = true;

}


void Player::move_down()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	vectorNew = speed;

	speedFinal.addX(-speed.getX());
	speedFinal.addZ(-speed.getZ());

	isMoving = true;
}

void Player::move_right()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	vectorNew = speed;

	speedFinal.addX(speed.getZ());
	speedFinal.addZ(-speed.getX());

	isMoving = true;
}

void Player::move_left()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	vectorNew = speed;

	speedFinal.addX(-speed.getZ());
	speedFinal.addZ(speed.getX());



	isMoving = true;
}