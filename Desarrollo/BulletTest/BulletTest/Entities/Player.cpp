
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
#include "../Command/ShootAsalto.h"
#include "../Command/ShootRocket.h"
#include "../Command/ShootPistola.h"

#include "../TriggerSystem.h"


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
	/*******INICIALIZAR ARMAS******/
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
	isMoving = false;
	

	if (p_controller->onGround()) {
		//seteamos la velocidad para andar, si corre se cambiara a una mayor
		//p_controller->setSpeed(1.3f);

		
		

	}

	speedFinal = Vec3<float>(0, 0, 0);

	// Ejecuta todos los comandos
	InputHandler::i().excuteCommands(this);


	speedFinal.normalise();

	//p_controller->m_speed += p_controller->m_speed * m_acceleration_walk;

	
	/*if (p_controller->getSpeedFactor() > m_maxSpeed_walk) {
		p_controller->setSpeed(m_maxSpeed_walk);
	}*/

	if (isDying == false) {
		p_controller->setWalkDirection(
			btVector3(speedFinal.getX(),
				speedFinal.getY(),
				speedFinal.getZ()));
	}
	else {
		p_controller->setWalkDirection(
			btVector3(0.f,0.f,0.f));
	}


	GraphicEngine::i().actualizarInterfaz();


	//TODO esto hay que arreglarlo pero queremos jugar y lo hacemos asi de sucio ahora xD
	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());

	

	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));


	m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));

	if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
		//ahora posicion y rotacion se envian en el mismo
		Cliente::i().enviarMovimiento(this);
	}

	//Una vez termine la nimacion de muerte, volvemos a movernos
	if (relojMuerte.getElapsedTime().asSeconds() > 3 && isDying) {
		isDying = false;
		//TODO la posicion de respawn será un array de posiciones que se leen del mapa
		setPosition(Vec3<float>(0,10,0));
	}

}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)

	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 30, 0), Vec3<float>(0.03f, 0.03f, 0.03f), "", "");

	listaWeapons->valorActual()->getNode()->setVisible(true);



	radius = 1.2f;
	height = 7.3f;
	mass = 70.f;

	m_pCollisionShape = new btCapsuleShape(radius, height);

	btVector3 intertia;
	m_pCollisionShape->calculateLocalInertia(mass, intertia);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 30, 0)); // check

	btPairCachingGhostObject* actorGhost = new btPairCachingGhostObject();
	actorGhost->setUserPointer(this);
	actorGhost->setWorldTransform(startTransform);

	actorGhost->setCollisionShape(m_pCollisionShape);
	actorGhost->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);

	p_controller = new KinematicCharacterController(actorGhost, static_cast<btConvexShape*>(m_pCollisionShape), 2.f);
	p_controller->setUp(btVector3(0, 1, 0));

	PhysicsEngine::i().m_world->addCollisionObject(p_controller->getGhostObject(), col::Collisions::Character,
		col::characterCollidesWith);

	p_controller->m_acceleration_walk = 1.3f;
	p_controller->m_deceleration_walk = 5.5f;
	p_controller->m_maxSpeed_walk = 3.f;

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);

	resetVida();

}

void Player::borrarContenido()
{
	//Estas cosas se borran aqui y no en el physics engine porque el player es especial(ghost object)
	delete m_pCollisionShape;
	delete p_controller;
}

void Player::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		
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
	
	p_controller->jump(btVector3(0, 90, 0));
	
}


void Player::shoot() {

	enum EnumTriggerType explosion = kTrig_Explosion;

	Time k;

	TriggerSystem::i().RegisterTrigger(explosion, 1000, this->getID(), this->getRenderPosition(), 50,k, false);

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


void Player::UpWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	listaWeapons->Siguiente();

	if (listaWeapons->valorActual()->getClassName() == "Asalto") {
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootAsalto()));
	}
	else if(listaWeapons->valorActual()->getClassName() == "Pistola"){
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootPistola()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "RocketLauncher") {
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootRocket()));
	}

	listaWeapons->valorActual()->getNode()->setVisible(true);
	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(1,m_guid);
	}
}

void Player::DownWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	listaWeapons->Anterior();
	listaWeapons->valorActual()->getNode()->setVisible(true);

	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(2, m_guid);
	}
}

void Player::impulsar(Vec3<float> force)
{
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