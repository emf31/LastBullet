
#include "Player.h"
#include "../Motor de Red/Cliente.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "../Handlers/MessageHandler.h"
#include "../Motor de Red/Estructuras.h"
#include "../Handlers/InputHandler.h"
#include "math.h"
#include "../Otros/Vec3f.h"
#include "../Otros/Util.h"
#include "GunBullet.h"
#include "RocketBullet.h"
#include "Weapons/Asalto.h"

Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Entity(1000, NULL, name, guid),
m_acceleration_walk(10.f),
//m_acceleration_run(5.f), 
m_deceleration_walk(11.f),
//m_deceleration_run(0.2f), 
m_maxSpeed_walk(60.f),
//m_maxSpeed_run(18.0f),
m_vida(5)
{
	

}


Player::~Player()
{
	
}

void Player::setPosition(Vec3<float> pos)
{
	m_renderState.setPosition(pos);
	p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	//m_nodo->setPosition(pos);
	m_nodo->setPosition(pos);
}




void Player::inicializar()
{
	vectorPrev = vectorNew = Vec3<float>(0, 0, 0);
	giro = 0;

	granada = new Granada();
	granada->cargarContenido();

	animation = new Animation;

	//wp = new Asalto();


	m_vida = 5;
}



void Player::update(Time elapsedTime)
{
	isMoving = false;
	p_controller->setSpeed(1.3);//seteamos la velocidad para andar, si corre se cambiara a una mayor

	speedFinal = Vec3<float>(0, 0, 0);


	// Ejecuta todos los comandos
	InputHandler::i().excuteCommands(this);
	
	speedFinal.normalise();

	updateState();
	updateAnimation();
	
	/*if (speedFinal.Magnitude() > 0) {
		if(animation->getActualAnimation()!="Run_Forwards")
			m_nodo->setAnimation(animation->getAnimationStart("Run_Forwards"), animation->getAnimationEnd("Run_Forwards"));
	}
	else {
		if (animation->getActualAnimation() != "Idle") {
			m_nodo->setAnimation(animation->getAnimationStart("Idle"), animation->getAnimationEnd("Idle"));
		}
	}*/


	/*if (p_controller->onGround()) {
		if (animation->getActualAnimation() != "Jump")
			m_nodo->setAnimation(animation->getAnimationStart("Jump"), animation->getAnimationEnd("Jump"));
	}*/

	/*p_controller->m_maxSpeed = m_maxSpeed_walk;
	p_controller->m_deceleration = m_deceleration_walk;*/


	p_controller->setWalkDirection(
		btVector3(speedFinal.getX(),
			speedFinal.getY(),
			speedFinal.getZ()));


	//p_controller->setMaxPenetrationDepth(0.f);
	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());


	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y()-(height/2),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));
	
	

	if (granada->getEstado() == DISPARADO) {
		btVector3 Point = granada->m_rigidBody->getCenterOfMassPosition();
		granada->getRenderState()->updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));
		if (granada->clockRecargaGranada.getElapsedTime().asSeconds()>granada->timeRecargaGranada) {
			granada->setEstado(CARGADO);
			PhysicsEngine::i().removeRigidBody(granada->m_rigidBody);

		}
	}
	
	

	// Set rotation
	/*vector3df Euler;

	const btQuaternion& TQuat = p_controller->getGhostObject()->get();

	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;*/


/*

	vectorPrev = vectorNew;
	Vec3<float>target = GraphicEngine::i().getActiveCamera()->getTarget();
	Vec3<float>pos = Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()
		);
	vectorNew = target - pos;

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

	*/
	m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));

	if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
		Cliente::i().enviarPos(this);
		Cliente::i().enviarRot(this);
	}


	
}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)

	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(0, 100, 0), Vec3<float>(0.03f, 0.03f, 0.03f), "", "../media/arma/ak.obj");
	//m_nodo->setTexture("../media/arma/car4_scope.tga", 1);
	//m_nodo->setTexture("../media/arma/v_hands_gloves_sf2 d.tga", 1);
	m_nodo->setTexture("../media/arma/weapon.png", 0);
	m_nodo->setTexture("../media/arma/v_hands_gloves_sf2 d.tga", 1);
	//m_nodo->setTexture("../media//arma/m4tex.png", 2);

	//TODO esto igual es que se ha rayado ese set position pinta raro
	Vec3<float> pos= Vec3<float>(0, 100, 0);
	m_renderState.setPosition(pos);
	//p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	//m_nodo->setPosition(pos); 
	//////////////////////////////////////añades animaciones//////////////////////////////////////////////////

	animation->addAnimation("Default", 0, 0);
	animation->addAnimation("Run_Forwards", 1, 69);
	animation->addAnimation("Run_backwards", 70, 138);
	animation->addAnimation("Walk", 139, 183);
	animation->addAnimation("Jump", 184, 219);
	animation->addAnimation("Jump2", 184, 219);
	animation->addAnimation("Idle", 220, 472);
	animation->addAnimation("AimRunning", 473, 524);

	m_playerState = quieto;

	//m_nodo->setAnimation(animation->getAnimationStart("Idle"), animation->getAnimationEnd("Idle"));

	////////////////////////////////////////////SHAPE///////////////////////////////////////////////////////////

	radius = 1.2f;
	height = 7.3f;
	mass = 70.f;

	m_pCollisionShape = new btCapsuleShape(radius, height);

	m_pMotionState = new btDefaultMotionState(btTransform(btQuaternion(1.0f, 0.0f, 0.0f, 0.0f).normalized(), btVector3(0,100,0)));

	btVector3 intertia;
	m_pCollisionShape->calculateLocalInertia(mass, intertia);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 100, 0)); // check

	btPairCachingGhostObject* actorGhost = new btPairCachingGhostObject();
	actorGhost->setUserPointer(this);
	actorGhost->setWorldTransform(startTransform);

	actorGhost->setCollisionShape(m_pCollisionShape);
	actorGhost->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);

	p_controller = new KinematicCharacterController(actorGhost, static_cast<btConvexShape*>(m_pCollisionShape), 2.f);
	p_controller->setUp(btVector3(0, 1, 0));
	//p_controller->setGravity(btVector3(0,-9.8*3,0));
	//p_controller->setJumpSpeed(5);
	//p_controller->setMaxSlope(btRadians(30.0));
	//p_controller->setFallSpeed(200);
	//p_controller->setMaxJumpHeight(20);
	//p_controller->setLinearDamping(0.1);

	PhysicsEngine::i().m_world->addCollisionObject(p_controller->getGhostObject(), btBroadphaseProxy::CharacterFilter,
		btBroadphaseProxy::StaticFilter | btBroadphaseProxy::DefaultFilter | btBroadphaseProxy::SensorTrigger);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//(const Vec3<float> spawnPos, float radius, float height, float mass, float stepHeight);
	//p_controller = new btKinematicCharacterController(Vec3<float>(0, 100, 0),);

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);
	resetVida();

}

void Player::borrarContenido()
{

}

void Player::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		if (static_cast<Entity*>(message.data)->getClassName() == "LifeObject") {
			//std::cout << "Has cogido vida" << std::endl;

		}
	}

	if (message.mensaje == "DIBUJARBALA") {
		//TBala* tBala= static_cast<TBala*>(message.data);
			//std::cout << "Has cogido vida" << std::endl;
		GunBullet* bala = new GunBullet(static_cast<TBala*>(message.data)->position, static_cast<TBala*>(message.data)->direction, static_cast<TBala*>(message.data)->finalposition, static_cast<TBala*>(message.data)->rotation);
		
	}
}

void Player::run()
{
	p_controller->setSpeed(3.0);
}

void Player::jump() {

	/*bool isGrounded = false;
	>>>>>>> refs/heads/Player-Controller

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

	/*	numJumps = 0;
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


	
	p_controller->jump(btVector3(0, 20, 0));

}


void Player::shoot() {

	//weapon->shoot();

	if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
		printf("Shoot\n");
	btVector3 SIZE_OF_WORLD(1500, 1500, 1500);

	btVector3 start(
		GraphicEngine::i().getActiveCamera()->getPosition().getX(),
		GraphicEngine::i().getActiveCamera()->getPosition().getY(),
		GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
	direccion.normalise();

	btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

	btVector3 end = start + (direccion2*SIZE_OF_WORLD);

	btCollisionWorld::AllHitsRayResultCallback ray(start, end);

	PhysicsEngine::i().m_world->rayTest(start, end, ray);

	Vec3<float> posicionImpacto(1500, 1500, 1500);


	if (ray.hasHit())//si ray ha golpeado algo entro
	{


		const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

																			 //calcularDistancia(start, end);

																			 ////////////////////////////////////////////////////////////
																			 //TODO:CAMBIAR ESTO POR EL RIGID BODY DEL PLAYER CONTROLLER
																			 //if (hit != m_rigidBody)
																			 //{
		
		Entity* myEnt = static_cast<Entity*>(hit->getUserPointer());
		if (myEnt->getClassName() == "Enemy") {
			Message msg(myEnt, "COLISION_BALA", NULL);
			MessageHandler::i().sendMessage(msg);
		}
		
		posicionImpacto = Vec3<float>(ray.m_hitPointWorld.at(0).x(), ray.m_hitPointWorld.at(0).y(), ray.m_hitPointWorld.at(0).z());

	}
	
	//creamos la bala cuando disparamos, le pasamos la posicion de inicio, el vector direccion por el cual se movera y la posicion final
	//TODO: mas adelante la posicion inicial no sera la posicion de la camara sino que sera la posicion del arma.
	
	//disparamos la bala en nuestro cliente
	Vec3<float> posDisparo = GraphicEngine::i().getActiveCamera()->getPosition();
	posDisparo += Vec3<float>(Randf(-1.f,1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

	if(arma != LANZACOHETES)
	GunBullet* bala = new GunBullet(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
	else{
	RocketBullet* bala = new RocketBullet(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
	}
	
	
	if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
		//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
		Cliente::i().dispararBala(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
	}
	//}

		relojCadencia.restart();
	}

	
}


void Player::shootGranada() {


	if (granada->getEstado() == CARGADO) {

		Vec3<float> posicion(p_controller->getGhostObject()->getWorldTransform().getOrigin().x() + 3, p_controller->getGhostObject()->getWorldTransform().getOrigin().y() + 5, p_controller->getGhostObject()->getWorldTransform().getOrigin().z());
		btTransform transform = granada->m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(posicion.getX(), posicion.getY(), posicion.getZ()));


		granada->getRenderState()->updatePositions(posicion);

		granada->setPosition(posicion);

		printf("GRANADA DISPARADO\n");
		btVector3 FUERZA(1.5, 1.5, 1.5);


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		granada->resetRigidBody();//DEBATIR: EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 


		granada->m_rigidBody->applyCentralForce(force);
		//rocket->m_rigidBody->setCollisionFlags(4);

		granada->setEstado(DISPARADO);
		granada->clockRecargaGranada.restart();
	}

}


void Player::move_up()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	//vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	//vectorNew = speed;

	speedFinal.addX(speed.getX());
	speedFinal.addZ(speed.getZ());

	isMoving = true;

}


void Player::move_down()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	//vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	//vectorNew = speed;

	speedFinal.addX(-speed.getX());
	speedFinal.addZ(-speed.getZ());

	isMoving = true;
}

void Player::move_right()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	//vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	//vectorNew = speed;

	speedFinal.addX(speed.getZ());
	speedFinal.addZ(-speed.getX());

	isMoving = true;
}

void Player::move_left()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	//vectorPrev = vectorNew;
	Vec3<float> speed = target - posicion;
	//vectorNew = speed;

	speedFinal.addX(-speed.getZ());
	speedFinal.addZ(speed.getX());



	isMoving = true;
}

float Player::calcularDistancia(btVector3& start, btVector3& end) {

	btVector3 vecDiferencia(end.x() - start.x(), end.y() - start.y(), end.z() - start.z());
	float distancia = sqrtf(pow(vecDiferencia.x(), 2) + pow(vecDiferencia.y(), 2) + pow(vecDiferencia.z(), 2));
	printf("DISTANCIA: %f", distancia);
	return 0.5f;
}

void Player::updateAnimation()
{
	switch (m_playerState)
	{
	case quieto:
		if (animation->getActualAnimation() != "Idle") {
			m_nodo->setAnimation(animation->getAnimationStart("Idle"), animation->getAnimationEnd("Idle"));
		}
		break;

	case andando:
		if (animation->getActualAnimation() != "Walk") {
			m_nodo->setAnimation(animation->getAnimationStart("Walk"), animation->getAnimationEnd("Walk"));
		}
		break;

	case saltando:
		if (animation->getActualAnimation() != "Jump") {
			m_nodo->setAnimation(animation->getAnimationStart("Jump"), animation->getAnimationEnd("Jump"));
		}
		break;
	case saltando2:
		if (animation->getActualAnimation() != "Jump2") {
			m_nodo->setAnimation(animation->getAnimationStart("Jump2"), animation->getAnimationEnd("Jump2"));
		}
		break;

	}
}

void Player::updateState()
{
	if(!p_controller->onGround() && p_controller->numJumps==0){
		m_playerState = saltando;
	}
	else if (!p_controller->onGround() && p_controller->numJumps ==1) {
		m_playerState = saltando2;
	}
	else if (isMoving) {
		m_playerState = andando;
	}
	else {
		m_playerState = quieto;
	}
}

void Player::setWeapon(int weapon) {
	arma = weapon;

	switch (weapon) {
		case LANZACOHETES:
			printf("TE HAS EQUIPADO UN LANZACOHETES\n");
		break;
		case ASALTO:
			printf("TE HAS EQUIPADO UN FUSIL DE ASALTO\n");
		break;
		case PISTOLA:
			printf("TE HAS EQUIPADO UNA PISTOLA\n");
		break;
	}
}