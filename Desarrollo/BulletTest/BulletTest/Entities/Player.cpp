#include "Player.h"
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <MessageHandler.h>
#include <Estructuras.h>
#include <InputHandler.h>
#include "math.h"
#include <vec3.hpp>
#include <Util.h>
#include "GunBullet.h"
#include "RocketBullet.h"
#include "RocketBulletEnemy.h"
#include <memory>
#include <Enemy.h>
#include <ShootAsalto.h>
#include <ShootRocket.h>
#include <ShootPistola.h>
#include <ShootSniper.h>
#include <TriggerSystem.h>
#include <Map.h>
#include <TimePerFrame.h>


#include <NetworkManager.h>
#include <glm\glm.hpp>




Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Character(1000, NULL, name, guid) , life_component(this)
{
	//Registramos la entity en el trigger system
	dwTriggerFlags = kTrig_Explosion | kTrig_EnemyNear | Button_Spawn | Button_Trig_Ent | Button_Trig_Ent_Pistola| Button_Trig_Ent_Rocket | Button_Trig_Ent_Asalto | kTrig_EnemyShootSound;

	TriggerSystem::i().RegisterEntity(this);
	

	/////////////////////////////////////////
	////////////////////////////////////////
	//NETWORK
	//Creates object to send and receive packets
	m_network.reset();
	m_network = NetworkManager::i().createNetPlayer(this);

}


Player::~Player()
{
	
}



void Player::inicializar()
{
	isRunning = false;
	isReloading = false;
	isShooting = false;
	tieneAsalto = false;
	tieneSniper = false;
	tieneRocketLauncher = false;
	tienePistola = false;

	//Activamos la camara FPS
	GraphicEngine::i().setActiveCamera("CamaraPlayer");
	Camera* camaraPlayer = GraphicEngine::i().getActiveCamera();
	camaraPlayer->asignarEntity(this);
	
	


	granada = new Granada();
	granada->inicializar();
	granada->cargarContenido();

	animation = new Animation;

	/*******************************/
	/*******INICIALIZAR ARMAS******/
	/*****************************/
	asalto = new Asalto(this);
	asalto->inicializar();
	asalto->cargarContenido();

	rocket = new RocketLauncher(this);
	rocket->inicializar();
	rocket->cargarContenido();

	pistola = new Pistola(this);
	pistola->inicializar();
	pistola->cargarContenido();

	sniper = new Sniper(this);
	sniper->inicializar();
	sniper->cargarContenido();

	

	listaWeapons = new Lista();

	listaWeapons->insertar(asalto);
	tieneAsalto = true;
	asalto->setEquipada(true);
	bindWeapon();



	/*listaWeapons->insertar(sniper);
	tieneSniper = true;

	listaWeapons->insertar(asalto);
	tieneAsalto = true;

	listaWeapons->insertar(rocket);
	tieneRocketLauncher = true;*/

	/*GraphicEngine::i().getActiveCamera()->addChild(asalto->getNode());
	GraphicEngine::i().getActiveCamera()->addChild(rocket->getNode());
	GraphicEngine::i().getActiveCamera()->addChild(pistola->getNode());
	GraphicEngine::i().getActiveCamera()->addChild(sniper->getNode());*/

	listaWeapons->valorActual()->getNode()->setVisible(true);

	/*listaWeapons->insertar(sniper);
	sniper->setEquipada(true);
	tieneSniper = true;
	bindWeapon();*/

	
}



void Player::update(Time elapsedTime)
{
	isMoving = false;
	isShooting = false;
	
	//Reseteamos la variable de saltado en el aire cuando tocas el suelo
	if (p_controller->onGround() && p_controller->jumpedOnAir) {
		p_controller->jumpedOnAir = false;
	}

	//Detectamos si chocamos al suelo con una velocidad previa muy rapida
	 if (p_controller->onGround() && p_controller->fallDownSpeed < -50) {
		 //printf("He caido de alto\n");
		 GraphicEngine::i().getActiveCamera()->cameraShake();
	 }
	 p_controller->fallDownSpeed = p_controller->getLinearVelocity().y();

	 //Deteccion de movimiento
	speedFinal = Vec3<float>(0, 0, 0);

	//Si es true estamos muriendo por lo que bloqueamos movimiento y acciones
	if (life_component.isDying() == false) {
		// Ejecuta todos los comandos
		InputHandler::i().excuteCommands(this);
	}

	speedFinal.normalise();
	p_controller->setWalkDirection(btVector3(speedFinal.getX(), speedFinal.getY(), speedFinal.getZ()));

	life_component.update();
	
	p_controller->updateAction(PhysicsEngine::i().m_world, TimePerFrameClass::GetTimePerFrame().asSeconds());

	

	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));


	m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));

	if (m_network->isConnected()) {

		TMovimiento mov;
		mov.isDying = getLifeComponent().isDying();
		mov.position = getRenderState()->getPosition();
		mov.rotation = getRenderState()->getRotation();
		mov.guid = getGuid();
	
		m_network->dispatchMessage(mov, MOVIMIENTO);
		
	}

	if (m_renderState.getPosition().getY() < -200) {
		getLifeComponent().restaVida(100, m_guid);
	}

	updateRelojes();

}




void Player::handleInput()
{
	InputHandler::i().handleInput();
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)


	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 30, 0), Vec3<float>(0.02f, 0.02f, 0.02f), "", "assets/nanosuit.obj");
	ResourceManager::i().getMesh("../media/bullet.obj");
	ResourceManager::i().getMesh("../media/bullets/rocketbullet.obj");
	m_nodo->setVisible(false);

	

	radius = 0.5f;
	height = 3.f;
	mass = 70.f;

	p_controller = PhysicsEngine::i().createCapsuleKinematicCharacter(this, radius, height, mass);

	p_controller->m_acceleration_walk = 0.8;
	p_controller->m_deceleration_walk = 5.f;
	p_controller->m_maxSpeed_walk = 0.7;


	life_component.resetVida();

	p_controller->reset(PhysicsEngine::i().m_world);

	setPosition(Map::i().searchSpawnPoint());

	

}

void Player::borrarContenido()
{


	PhysicsEngine::i().removeKinematic(p_controller);
}

void Player::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		
	}else if (message.mensaje == "COLISION_ROCKET") {
		NetworkManager::i().dispatchMessage(*(TImpactoRocket*)message.data, IMPACTO_ROCKET);
		delete message.data;
	}
	else if (message.mensaje == "COLISION_BALA") {
			//Este float * es una referencia a una variable de clase asi que no hay problema
			TImpactoBala impacto = *static_cast<TImpactoBala*>(message.data);

			getLifeComponent().restaVida(impacto.damage, impacto.guid);
			relojSangre.restart();
			//static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojHit.restart();
		
	}

}

bool Player::handleTrigger(TriggerRecordStruct * Trigger)
{

	/*if (MastEventReceiver::i().keyDown(KEY_KEY_E)) {
		Entity* ent = EntityManager::i().getEntity(Trigger->idSource);
		if (ent->getID() == 65534) {
			//Respawns
			p_controller->reset(PhysicsEngine::i().m_world);
			setPosition(Map::i().searchSpawnPoint());
		} else if (ent->getID() == 65535) {
			//LifeObjects
			Entity *ge = EntityManager::i().getEntity(9000);
			ge->handleTrigger(Trigger);
		} else if (ent->getID() == 65536) {
			//Button_Trig_Ent_Asalto
			Entity *grupoAsaltos = EntityManager::i().getEntity(9001);
			grupoAsaltos->handleTrigger(Trigger);

		} else if (ent->getID() == 65537) {
			//Button_Trig_Ent_Pistola
			Entity *grupoPistola = EntityManager::i().getEntity(9002);
			grupoPistola->handleTrigger(Trigger);

		} else if (ent->getID() == 65538) {
			//Button_Trig_Ent_Rocket
			Entity *grupoRocket = EntityManager::i().getEntity(9003);
			grupoRocket->handleTrigger(Trigger);

		}
	}
	return true;*/
	return true;
}

void Player::setPosition(const Vec3<float>& pos)
{
	m_renderState.setPosition(pos);
	p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	p_controller->reset(PhysicsEngine::i().m_world);
	m_nodo->setPosition(pos);
}

void Player::jump() {


	TriggerSystem::i().RegisterTrigger(kTrig_EnemyNear, 1001, this->getID(), this->getRenderPosition(), 50, milliseconds(800), false);
	
	p_controller->jump(btVector3(0, 15, 0));
	
}


void Player::shoot() {

	isShooting = true;
	
	if (listaWeapons->valorActual()->canShoot()) {	
		listaWeapons->valorActual()->shoot(GraphicEngine::i().getActiveCamera()->getTarget());
		GraphicEngine::i().getActiveCamera()->cameraRecoil();
		TriggerSystem::i().RegisterTrigger(kTrig_EnemyShootSound, 1002, m_id, m_renderState.getPosition(), 50, milliseconds(50), false);
	}
	


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

	speedFinal.addX(-speed.getZ());
	speedFinal.addZ(speed.getX());


	isMoving = true;
}

void Player::move_left()
{
	

	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(speed.getZ());
	speedFinal.addZ(-speed.getX());

	isMoving = true;
}

void Player::bindWeapon() {

	if (listaWeapons->valorActual()->getClassName() == "Asalto") {
		InputHandler::i().bind(GLFW_MOUSE_BUTTON_1, CommandPtr(new ShootAsalto()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "Pistola") {
		InputHandler::i().bind(GLFW_MOUSE_BUTTON_1, CommandPtr(new ShootPistola()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "RocketLauncher") {
		InputHandler::i().bind(GLFW_MOUSE_BUTTON_1, CommandPtr(new ShootRocket()));
	}
	else if (listaWeapons->valorActual()->getClassName() == "Sniper") {
		InputHandler::i().bind(GLFW_MOUSE_BUTTON_1, CommandPtr(new ShootSniper()));
	}

}


void Player::UpWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	listaWeapons->Siguiente();
	if (apuntando) {
		GraphicEngine::i().getActiveCamera()->restablecerMira();
		apuntando = false;
	}
	bindWeapon();

	listaWeapons->valorActual()->getNode()->setVisible(true);
	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	/*if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(1,m_guid);
	}*/
}

void Player::DownWeapon()
{
	listaWeapons->valorActual()->getNode()->setVisible(false);
	listaWeapons->Anterior();
	if (apuntando) {
		GraphicEngine::i().getActiveCamera()->restablecerMira();
		apuntando = false;
	}

	bindWeapon();
	
	listaWeapons->valorActual()->getNode()->setVisible(true);

	//TODO aqui controlar que cambia de arma, es decir que no tines solo 1 arma
	/*if (Cliente::i().isConected()) {
		Cliente::i().cambioArma(2, m_guid);
	}*/
}

void Player::reload() {
	listaWeapons->valorActual()->recargar();
}

void Player::apuntar()
{

	if (listaWeapons->valorActual()->getClassName()=="Sniper") {
		if (!apuntando) {
			GraphicEngine::i().getActiveCamera()->apuntar();
			apuntando = true;
		}
		else {
			GraphicEngine::i().getActiveCamera()->restablecerMira();
			apuntando = false;
		}
	}

}

void Player::restablecerMira()
{
	GraphicEngine::i().getActiveCamera()->restablecerMira();
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
				listaWeapons->insertar(rocket);
				tieneRocketLauncher = true;
			}
			else {
				rocket->resetAmmoTotal();
			}
		break;
		case ASALTO:
			if (!tieneAsalto) {
				listaWeapons->insertar(asalto);
				tieneAsalto = true;
			}
			else {
				asalto->resetAmmoTotal();
			}
		break;
		case PISTOLA:
			if (!tienePistola) {
				listaWeapons->insertar(pistola);
				tienePistola = true;
			}
			else {
				pistola->resetAmmoTotal();
			}
		break;
		case SNIPER:
			if (!tieneSniper) {
				listaWeapons->insertar(sniper);
				tieneSniper = true;
			}
			else {
				sniper->resetAmmoTotal();
			}
			break;
	}


}

int Player::getAmmoTotal() {

	if (listaWeapons->valorActual()->getEstadoWeapon() == CARGADA) {
		return listaWeapons->valorActual()->getNumCargadores()*getCargadorActual() + listaWeapons->valorActual()->getBalasRestantes();
	}
	else {
		return -1;
	}
}

void Player::resetAll() {

	listaWeapons->valorActual()->getNode()->setVisible(false);


	listaWeapons->Vaciar();

	tieneRocketLauncher = false;
	tienePistola = false;
	tieneAsalto = false;
	tieneSniper = false;

	asalto->inicializar();
	
	rocket->inicializar();
	
	pistola->inicializar();
	
	sniper->inicializar();


	listaWeapons->insertar(pistola);
	listaWeapons->valorActual()->getNode()->setVisible(true);

	rocket->setEquipada(false);
	asalto->setEquipada(false);
	sniper->setEquipada(false);

	pistola->setEquipada(true);
	tienePistola = true;

	life_component.resetVida();

}

void Player::updateRelojes() {
	if (relojHit.getElapsedTime().asSeconds()<=0.5) {
		hit = true;
	}
	else {
		hit = false;
	}

	if (relojSangre.getElapsedTime().asSeconds() <= 0.5) {
		sangre = true;
	}
	else {
		sangre = false;
	}
}


float Player::getVida() {
	return life_component.getVida();
}

bool Player::isDying() {
	return life_component.isDying();
}

