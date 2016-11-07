#include "Player.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "../Handlers/InputHandler.h"
#include "../Handlers/MessageHandler.h"
#include "math.h"




Player::Player() : Entity(2, NULL, "Player"),
m_acceleration_walk(10.f), 
//m_acceleration_run(5.f), 
m_deceleration_walk(11.f), 
//m_deceleration_run(0.2f), 
m_maxSpeed_walk(60.f)
//m_maxSpeed_run(18.0f)

{
	

}


Player::~Player()
{
	
}

void Player::inicializar()
{
	vectorPrev = vectorNew = Vec3<float>(0, 0, 0);
	giro = 0;
	rocket = new Rocket();
}



void Player::update(Time elapsedTime)
{
	isMoving = false;
	speedFinal = Vec3<float>(0, 0, 0);

	// Ejecuta todos los comandos
	InputHandler::i().excuteCommands(this);
	

	speedFinal.normalise();

	/*p_controller->m_maxSpeed = m_maxSpeed_walk;
	p_controller->m_deceleration = m_deceleration_walk;*/

	//p_controller->setVelocityForTimeInterval(btVector3(speedFinal.getX(), speedFinal.getY(), speedFinal.getZ(),elapsedTime.asSeconds()));

	
	//p_controller->setFallSpeed(2.f);

	p_controller->setWalkDirection(
		btVector3(speedFinal.getX(),
			speedFinal.getY(),
			speedFinal.getZ()));

	//p_controller->setMaxPenetrationDepth(0.f);
	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());



	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y()-(height/2)-radius,
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));
	
	

	if (rocket->getEstado() == CARGADO) {
		Vec3<float> posicion(p_controller->getGhostObject()->getWorldTransform().getOrigin().x() +5, p_controller->getGhostObject()->getWorldTransform().getOrigin().y(), p_controller->getGhostObject()->getWorldTransform().getOrigin().z());
		btTransform transform = rocket->m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(posicion.getX(), posicion.getY(), posicion.getZ()));


		rocket->getRenderState()->updatePositions(posicion);

		//rocket->m_rigidBody->set
	}
	else if (rocket->getEstado() == DISPARADO) {
		btVector3 Point = rocket->m_rigidBody->getCenterOfMassPosition();
		rocket->getRenderState()->updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));
		if (clockRecargaRocket.getElapsedTime().asSeconds()>timeRecargaRocket) {
			rocket->setEstado(CARGADO);
		}
	}
	

	// Set rotation
	/*vector3df Euler;
	const btQuaternion& TQuat = p_controller->m_pRigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;


	vectorPrev = vectorNew;
	Vec3<float>target =GraphicEngine::i().getActiveCamera()->getTarget();
	Vec3<float>pos=Vec3<float>(p_controller->GetPosition().getX(), p_controller->GetPosition().getY(), p_controller->GetPosition().getZ());
	vectorNew = target - pos;

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
	m_renderState.updateRotations(Vec3<float>(0, giro, 0));*/
}

void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 100, 0), Vec3<float>(3.f, 3.f, 3.f), "../media/textureMan.bmp", "../media/MeshPlayer.obj");

	m_renderState.setPosition(Vec3<float>(0, 100, 0));


	////////////////////////////////////////////SHAPE///////////////////////////////////////////////////////////

	radius = 1.2f;
	height = 3.3f;
	mass = 70.f;

	m_pCollisionShape = new btCapsuleShape(radius, height);

	m_pMotionState = new btDefaultMotionState(btTransform(btQuaternion(1.0f, 0.0f, 0.0f, 0.0f).normalized(), btVector3(0,10,0)));

	btVector3 intertia;
	m_pCollisionShape->calculateLocalInertia(mass, intertia);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 10, 0)); // check

	btPairCachingGhostObject* actorGhost = new btPairCachingGhostObject();
	actorGhost->setUserPointer(this);
	actorGhost->setWorldTransform(startTransform);

	actorGhost->setCollisionShape(m_pCollisionShape);
	actorGhost->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);

	p_controller = new KinematicCharacterController(actorGhost, static_cast<btConvexShape*>(m_pCollisionShape), 0.5f);
	//p_controller->setGravity(btVector3(0,-9.8*3,0));
	//p_controller->setJumpSpeed(5);
	p_controller->setUp(btVector3(0,1,0));
	//p_controller->setFallSpeed(55);
	//p_controller->setMaxJumpHeight(20);
	//p_controller->setLinearDamping(0.1);

	PhysicsEngine::i().m_world->addCollisionObject(p_controller->getGhostObject(), btBroadphaseProxy::CharacterFilter,
		btBroadphaseProxy::StaticFilter | btBroadphaseProxy::DefaultFilter);
	//PhysicsEngine::i().m_world->addAction(p_controller);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//(const Vec3<float> spawnPos, float radius, float height, float mass, float stepHeight);
	//p_controller = new btKinematicCharacterController(Vec3<float>(0, 100, 0),);
}

void Player::borrarContenido()
{
	//No se si aqui habria que hacer delete al nodo porque igual se encarga irrlitch
	delete m_nodo;
}

void Player::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		//std::cout << "Colisiono" << std::endl;
	}
}

void Player::jump() {


	/*btVector3 start = m_rigidBody->getCenterOfMassPosition(); // posicion del player
	btVector3 dest = start;

	dest.setY(dest.getY() - 50.0f);  //destino del rayo, que es la posicion del player en y - 50 unidades

	btCollisionWorld::ClosestRayResultCallback ray(start, dest); // Creo el rayo con inicio y destino
	PhysicsEngine::i().m_world->rayTest(start, dest, ray);//hago el ray test

	if (ray.hasHit())//si ray ha golpeado algo entro
	{
		printf("hit something\n");

		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

		if (hit != m_rigidBody)
		{
			/*btVector3 velocity = m_rigidBody->getLinearVelocity();//DISCUTIR: Con set linear velocity queda mejor, pero he encontrado mas ejemplos que lo hacen con applyimpulse o applyforce

			velocity.setY(velocity.getY() + 5.0f);

			m_rigidBody->setLinearVelocity(velocity);
			
			numJumps = 0;
		}
	}
	else
	{
		printf("missed");
	}

	if (numJumps < 2) {
		m_rigidBody->applyCentralForce(btVector3(0, 400, 0));
		numJumps++;
	}*/

	
	p_controller->jump(btVector3(0,20,0));
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

	btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

	btVector3 end = start+(direccion2*SIZE_OF_WORLD);
	
	btCollisionWorld::AllHitsRayResultCallback ray(start, end);

	PhysicsEngine::i().m_world->rayTest(start, end, ray);

	if (ray.hasHit())//si ray ha golpeado algo entro
	{


		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto
		
		////////////////////////////////////////////////////////////
		//TODO:CAMBIAR ESTO POR EL RIGID BODY DEL PLAYER CONTROLLER
		//if (hit != m_rigidBody)
		//{
			
			for (int i = 0; i < ray.m_hitNormalWorld.capacity(); i++) {
				//printf("SIZE OF THE ARRAY OF HITS: %d \n", ray.m_hitNormalWorld.capacity());

				Entity* myEnt = static_cast<Entity*>(hit->getUserPointer());
				Message msg(myEnt,"COLISION_BALA",NULL);
				MessageHandler::i().sendMessage(msg);


				printf("hit something\n");
				}

			}

		//}
	}


void Player::shootRocket() {


	if (rocket->getEstado() == CARGADO) {

		printf("ROCKET DISPARADO\n");
		btVector3 SIZE_OF_WORLD(70, 70, 70);


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * SIZE_OF_WORLD;

		rocket->resetRigidBody();//DEBATIR: EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 

		rocket->m_rigidBody->activate();

		rocket->m_rigidBody->applyCentralForce(force);

		rocket->setEstado(DISPARADO);
		clockRecargaRocket.restart();
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

