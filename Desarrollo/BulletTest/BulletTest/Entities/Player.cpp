
#include "Player.h"
#include "../Motor de Red/Cliente.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "../Handlers/MessageHandler.h"
#include "../Motor de Red/Estructuras.h"
#include "../Handlers/InputHandler.h"
#include "math.h"
#include<memory>
#include "../Otros/Vec3f.h"
#include "../Otros/Util.h"
#include "GunBullet.h"
#include "RocketBullet.h"
#include "Weapons/Asalto.h"
#include "Weapons/Pistola.h"
#include "Weapons/RocketLauncher.h"

Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Entity(1000, NULL, name, guid)
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
	m_nodo.get()->setPosition(pos);
}




void Player::inicializar()
{

	granada = new Granada();
	granada->cargarContenido();

	animation = new Animation;

	Weapon* firstWeapon;
	Weapon* pistola = new Pistola();
	Weapon* lanzacohetes= new RocketLauncher();


	float RandomNumber = Randf(0, 3);
	std::cout << RandomNumber << std::endl;

	if (RandomNumber >= 0 && RandomNumber < 1) {
		firstWeapon = new Asalto();
		tieneAsalto = true;
	}
	else if (RandomNumber >= 1 && RandomNumber < 2) {
		firstWeapon = new Pistola();
		tienePistola = true;
	}
	else if (RandomNumber >= 2 && RandomNumber <= 3) {
		firstWeapon = new RocketLauncher();
		tieneRocketLauncher = true;
	}
	else {
		firstWeapon = new Asalto();
	}

	listaWeapons = new Lista();

	listaWeapons->insertar(firstWeapon);

	m_vida = 5;

	//GraphicEngine::i().mostrarInterfaz();
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
	
	
	//granada->update(elapsedTime);
	
	

	
	m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));

	if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
		//ahora posicion y rotacion se envian en el mismo
		Cliente::i().enviarPos(this);
		//Cliente::i().enviarRot(this);
	}

	//GraphicEngine::i().actualizarInterfaz();
	
}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)

	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createAnimatedNode(Vec3<float>(0, 100, 0), Vec3<float>(0.03f, 0.03f, 0.03f), "", "../media/arma/ak.obj"));
	m_nodo.get()->setTexture("../media/arma/weapon.png", 0);
	m_nodo.get()->setTexture("../media/arma/v_hands_gloves_sf2 d.tga", 1);

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
		TBala* tBala= static_cast<TBala*>(message.data);

		GunBullet* bala = new GunBullet(tBala->position, tBala->direction, tBala->finalposition, tBala->rotation);
		
	}
}

void Player::run()
{
	if(p_controller->onGround())
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

	listaWeapons->dispararArmaActual();

}


void Player::shootGranada() {

	granada->shoot(p_controller->getGhostObject()->getWorldTransform().getOrigin());

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

void Player::updateAnimation()
{
	switch (m_playerState)
	{
	case quieto:
		if (animation->getActualAnimation() != "Idle") {
			m_nodo.get()->setAnimation(animation->getAnimationStart("Idle"), animation->getAnimationEnd("Idle"));
		}
		break;

	case andando:
		if (animation->getActualAnimation() != "Walk") {
			m_nodo.get()->setAnimation(animation->getAnimationStart("Walk"), animation->getAnimationEnd("Walk"));
		}
		break;

	case saltando:
		if (animation->getActualAnimation() != "Jump") {
			m_nodo.get()->setAnimation(animation->getAnimationStart("Jump"), animation->getAnimationEnd("Jump"));
		}
		break;
	case saltando2:
		if (animation->getActualAnimation() != "Jump2") {
			m_nodo.get()->setAnimation(animation->getAnimationStart("Jump2"), animation->getAnimationEnd("Jump2"));
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

void Player::setWeapon(int newWeapon) {

	Weapon* weapon;

	switch (newWeapon) {
		case LANZACOHETES:
			if (!tieneRocketLauncher) {
				printf("TE HAS EQUIPADO UN LANZACOHETES\n");
				weapon = new RocketLauncher();
				listaWeapons->insertar(weapon);
				tieneRocketLauncher = true;
			}
		break;
		case ASALTO:
			if (!tieneAsalto) {
				printf("TE HAS EQUIPADO UN ASALTO\n");
				weapon = new Asalto();
				listaWeapons->insertar(weapon);
				tieneAsalto = true;
			}
		break;
		case PISTOLA:
			if (!tienePistola) {
				printf("TE HAS EQUIPADO UNA PISTOLA\n");
				weapon = new Pistola();
				listaWeapons->insertar(weapon);
				tienePistola = true;
			}
		break;
	}


}