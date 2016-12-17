
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


Player::Player(const std::string& name, std::vector<Vec3<float>> spawnPoints, RakNet::RakNetGUID guid) : Entity(1000, NULL, name, guid) ,
	m_spawns(spawnPoints),
	life_component(this)
{
	//Registramos la entity en el trigger system
	TriggerSystem::i().RegisterEntity(this);

}


Player::~Player()
{
	
}

void Player::setPosition(Vec3<float> &pos)
{
	m_renderState.setPosition(pos);
	p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	//m_nodo->setPosition(pos);
	m_nodo.get()->setPosition(pos);
}

//Busca en la lista de puntos de spawn alguno que no intersecte con ningún enemigo de radio x,
//luego con la lista que queda se coge un punto aleatorio
void Player::searchSpawnPoint()
{
	float radio = 100;
	float fDistance = 0;
	int spawn = 0;

	if (m_spawns.size() == 1) {
		setPosition(m_spawns.at(0));
		return;
	}

	std::list<Entity*> enemies = EntityManager::i().getEnemies();

	std::vector<Vec3<float>> auxSpawns;

	std::list<Entity*>::iterator it;
	std::vector<Vec3<float>>::iterator it2;

	for (it2 = m_spawns.begin(); it2 != m_spawns.end(); ++it2) {
		bool valid = true;
		for (it = enemies.begin(); it != enemies.end(); ++it) {
			Vec3<float> vector = (*it)->getRenderState()->getPosition() - (*it2);
			fDistance = vector.Magnitude();

			if (fDistance < 100) {
				valid = false;
				break;
			}

		}
		if (valid) {
			auxSpawns.push_back(*it2);
		}	

	}

	//Si hay mas de 1 elegimos uno aleatorio
	if (auxSpawns.size() > 1) {
		spawn = Randi(0, auxSpawns.size() - 1);
	}
	
	//Si no esta vacio es que hemos encontrado uno
	if (!auxSpawns.empty()) {
		setPosition(auxSpawns.at(spawn));
	}
	else {
		setPosition(m_spawns.at(Randi(0, m_spawns.size() - 1)));
	}
	
}




void Player::inicializar()
{
	isRunning = false;
	isReloading = false;
	isShooting = false;
	tieneAsalto = false;
	tieneRocketLauncher = false;
	tienePistola = false;

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


	GraphicEngine::i().mostrarInterfaz();
}



void Player::update(Time elapsedTime)
{
	isMoving = false;
	

	if (p_controller->onGround()) {
		p_controller->jumpedOnAir = false;
	}

	speedFinal = Vec3<float>(0, 0, 0);

	//Si es true estamos muriendo por lo que bloqueamos movimiento y acciones
	if (life_component.update() == false) {

		// Ejecuta todos los comandos
		InputHandler::i().excuteCommands(this);
		speedFinal.normalise();
		p_controller->setWalkDirection(btVector3(speedFinal.getX(), speedFinal.getY(), speedFinal.getZ()));

	} else {
		p_controller->setWalkDirection(
			btVector3(0.f, 0.f, 0.f));
	}


	GraphicEngine::i().actualizarInterfaz();


	
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


	btPairCachingGhostObject* actorGhost = new btPairCachingGhostObject();
	actorGhost->setUserPointer(this);

	actorGhost->setCollisionShape(m_pCollisionShape);
	actorGhost->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);

	p_controller = new KinematicCharacterController(actorGhost, static_cast<btConvexShape*>(m_pCollisionShape), 2.f);
	p_controller->setUp(btVector3(0, 1, 0));

	PhysicsEngine::i().m_world->addCollisionObject(p_controller->getGhostObject(), col::Collisions::Character,
		col::characterCollidesWith);

	p_controller->m_acceleration_walk = 6.3f;
	p_controller->m_deceleration_walk = 8.5f;
	p_controller->m_maxSpeed_walk = 6.f;

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);

	life_component.resetVida();
	searchSpawnPoint();

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

}

bool Player::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void Player::run()
{
	if(p_controller->onGround())
		p_controller->setSpeed(3.0);
}

void Player::jump() {


	TriggerSystem::i().RegisterTrigger(kTrig_EnemyNear, 1001, this->getID(), this->getRenderPosition(), 50, milliseconds(800), false);
	
	p_controller->jump(btVector3(0, 60, 0));
	
}


void Player::shoot() {


	TriggerSystem::i().RegisterTrigger(kTrig_Explosion, 1000, this->getID(), this->getRenderPosition(), 50, milliseconds(500), false);

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

void Player::bindWeapon() {
	if (listaWeapons->valorActual()->getClassName() == "Asalto") {
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootAsalto()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "Pistola") {
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootPistola()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "RocketLauncher") {
		InputHandler::i().bind(KEY_LBUTTON, CommandPtr(new ShootRocket()));
	}
}


void Player::UpWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	listaWeapons->Siguiente();

	bindWeapon();

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

	bindWeapon();
	
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


	asalto->borrarContenido();
	asalto->inicializar();
	asalto->cargarContenido();

	rocket->borrarContenido();
	rocket->inicializar();
	rocket->cargarContenido();

	pistola->borrarContenido();
	pistola->inicializar();
	pistola->cargarContenido();


	listaWeapons->insertar(pistola);
	listaWeapons->valorActual()->getNode()->setVisible(true);

	rocket->setEquipada(false);
	asalto->setEquipada(false);

	pistola->setEquipada(true);
	tienePistola = true;

}

