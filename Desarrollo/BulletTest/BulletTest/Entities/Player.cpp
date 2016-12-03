
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
#include "RocketBulletEnemy.h"
#include "Weapons/Asalto.h"
#include "Weapons/Pistola.h"
#include "Weapons/RocketLauncher.h"
#include <memory>
#include "Enemy.h"

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
	granada->inicializar();
	granada->cargarContenido();

	animation = new Animation;

	/*****************************/
	/*******INICILAZAR ARMAS******/
	asalto = new Asalto();
	asalto->inicializar();
	asalto->cargarContenido();

	rocket = new RocketLauncher();
	rocket->inicializar();
	rocket->cargarContenido();

	pistola = new Pistola();
	pistola->inicializar();
	pistola->cargarContenido();

	listaWeapons = new Lista();

	listaWeapons->insertar(pistola);
	pistola->setEquipada(true);
	tienePistola = true;
	
	m_vida = 100;

	GraphicEngine::i().mostrarInterfaz();
}



void Player::update(Time elapsedTime)
{

	if (isDying == false) {

	
	isMoving = false;

	if (p_controller->onGround())
		p_controller->setSpeed(1.3f);//seteamos la velocidad para andar, si corre se cambiara a una mayor

	speedFinal = Vec3<float>(0, 0, 0);


	// Ejecuta todos los comandos
	InputHandler::i().excuteCommands(this);


	speedFinal.normalise();

	/*updateState();
	updateAnimation();*/


	p_controller->setWalkDirection(
		btVector3(speedFinal.getX(),
			speedFinal.getY(),
			speedFinal.getZ()));


	//p_controller->setMaxPenetrationDepth(0.f);
	//p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());


	
	GraphicEngine::i().actualizarInterfaz();

	}
	else {
		//estas muerto
		if (relojMuerte.getElapsedTime().asSeconds() > 3) {
			isDying = false;
		}
	}
	//TODO: esto hay que arreglarlo pero queremos jugar y lo hacemos asi de sucio ahora xD
	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());

	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));




	m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));

	if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
		//ahora posicion y rotacion se envian en el mismo
		Cliente::i().enviarPos(this);
	}

}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)

	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createNode(Vec3<float>(0, 100, 0), Vec3<float>(0.03f, 0.03f, 0.03f), "", ""));
	//m_nodo.get()->setTexture("../media/arma/weapon.png", 0);
	//m_nodo.get()->setTexture("../media/arma/v_hands_gloves_sf2 d.tga", 1);
	//m_nodo->addChild(asalto->getNode());
	//m_nodo->addChild(listaWeapons->valorActual()->getNode());
	
	//m_nodo->addChild(rocket->getNode());

	listaWeapons->valorActual()->getNode()->setVisible(true);

	//////////////////////////////////////añades animaciones//////////////////////////////////////////////////

	/*animation->addAnimation("Default", 0, 0);
	animation->addAnimation("Run_Forwards", 1, 69);
	animation->addAnimation("Run_backwards", 70, 138);
	animation->addAnimation("Walk", 139, 183);
	animation->addAnimation("Jump", 184, 219);
	animation->addAnimation("Jump2", 184, 219);
	animation->addAnimation("Idle", 220, 472);
	animation->addAnimation("AimRunning", 473, 524);*/

	//m_playerState = quieto;


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
	//p_controller->setLinearDamping();
	PhysicsEngine::i().m_world->addCollisionObject(p_controller->getGhostObject(), col::Collisions::Character,
		col::characterCollidesWith);

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);

	resetVida();

}

void Player::borrarContenido()
{
	//Estas cosas se borran aqui y no en el physics engine porque el player es especial
	delete m_pCollisionShape;
	delete m_pMotionState;
	//PhysicsEngine::i().m_world->removeCollisionObject(btPairCachingGhostObject::upcast(m_pGhostObject));
	//delete m_pGhostObject;
	delete p_controller;
}

void Player::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		
	}
	else if(message.mensaje == "DIBUJARBALA"){
		TBala* tBala = static_cast<TBala*>(message.data);

		GunBullet* bala = new GunBullet(tBala->position, tBala->direction, tBala->finalposition, tBala->rotation);

		//delete tBala;

	}
	else if (message.mensaje == "DIBUJAR_ROCKET") {
		TBala* tRocket = static_cast<TBala*>(message.data);

		RocketBulletEnemy* balaRocket = new RocketBulletEnemy(tRocket->position, tRocket->direction, tRocket->rotation);
		
		//delete tRocket;

	}
	else if (message.mensaje == "NUEVO_ENEMIGO") {
		TPlayer* nuevoplayer = static_cast<TPlayer*>(message.data);

		Enemy *e = new Enemy(nuevoplayer->name, nuevoplayer->guid);
		e->inicializar();
		e->cargarContenido();
		e->setPosition(nuevoplayer->position);

		delete nuevoplayer;

		EntityManager::i().mostrarClientes();
	}
}

void Player::run()
{
	if(p_controller->onGround())
		p_controller->setSpeed(3.0);
}

void Player::jump() {
	
	p_controller->jump(btVector3(0, 20, 0));
	
}


void Player::shoot() {

	listaWeapons->valorActual()->shoot();

}


void Player::shootGranada() {

	granada->shoot(p_controller->getGhostObject()->getWorldTransform().getOrigin());

}


void Player::move_up()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(speed.getX());
	speedFinal.addZ(speed.getZ());

	isMoving = true;

}


void Player::move_down()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(-speed.getX());
	speedFinal.addZ(-speed.getZ());

	isMoving = true;
}

void Player::move_right()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(speed.getZ());
	speedFinal.addZ(-speed.getX());

	isMoving = true;
}

void Player::move_left()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

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

void Player::UpWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	//m_nodo->removeChild(listaWeapons->valorActual()->getNode());
	listaWeapons->Siguiente();
	//m_nodo->addChild(listaWeapons->valorActual()->getNode());
	listaWeapons->valorActual()->getNode()->setVisible(true);
	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(1,m_guid);
	}
}

void Player::DownWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	//m_nodo->removeChild(listaWeapons->valorActual()->getNode());
	listaWeapons->Anterior();
	//m_nodo->addChild(listaWeapons->valorActual()->getNode());
	listaWeapons->valorActual()->getNode()->setVisible(true);

	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(2, m_guid);
	}
}

void Player::impulsar(Vec3<float> force)
{
	printf("ME IMPULSO\n");
	btVector3 fuerza(force.getX(), force.getY(), force.getZ());
	p_controller->applyImpulse(fuerza);
}

void Player::setWeapon(int newWeapon) {

	switch (newWeapon) {
		case LANZACOHETES:
			if (!tieneRocketLauncher) {
				printf("TE HAS EQUIPADO UN LANZACOHETES\n");
				listaWeapons->insertar(rocket);
				tieneRocketLauncher = true;
			}
			else {
				rocket->resetAmmoTotal();
			}
		break;
		case ASALTO:
			if (!tieneAsalto) {
				printf("TE HAS EQUIPADO UN ASALTO\n");
				listaWeapons->insertar(asalto);
				tieneAsalto = true;
			}
			else {
				asalto->resetAmmoTotal();
			}
		break;
		case PISTOLA:
			if (!tienePistola) {
				printf("TE HAS EQUIPADO UNA PISTOLA\n");
				listaWeapons->insertar(pistola);
				tienePistola = true;
			}
			else {
				pistola->resetAmmoTotal();
			}
		break;
	}


}

void Player::resetAll() {

	listaWeapons->valorActual()->getNode()->setVisible(false);


	listaWeapons->Vaciar();

	tieneRocketLauncher = false;
	tienePistola = false;
	tieneAsalto = false;


	asalto = new Asalto();
	asalto->inicializar();
	asalto->cargarContenido();

	rocket = new RocketLauncher();
	rocket->inicializar();
	rocket->cargarContenido();

	pistola = new Pistola();
	pistola->inicializar();
	pistola->cargarContenido();

	listaWeapons = new Lista();

	listaWeapons->insertar(pistola);
	listaWeapons->valorActual()->getNode()->setVisible(true);

	rocket->setEquipada(false);
	asalto->setEquipada(false);

	pistola->setEquipada(true);
	tienePistola = true;

}