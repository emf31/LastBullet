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
#include <SoundManager.h>
#include <GUIManager.h>
#include <InGameHUD.h>


#include <NetworkManager.h>
#include <glm\glm.hpp>
#include <Death.h>

#include <AnimationMachine.h>


Player::Player(const std::string& name, std::shared_ptr<NetPlayer> netPlayer, RakNet::RakNetGUID guid) : Character(1000, NULL, name, guid), m_godMode(false), isMoving(false)
{
	//Registramos la entity en el trigger system
	dwTriggerFlags = kTrig_Explosion | kTrig_EnemyNear | Button_Spawn | Button_Trig_Ent | Button_Trig_Ent_Pistola| Button_Trig_Ent_Rocket | Button_Trig_Ent_Asalto | kTrig_EnemyShootSound;

	TriggerSystem::i().RegisterEntity(this);
	

	/////////////////////////////////////////
	////////////////////////////////////////
	//NETWORK
	//Creates object to send and receive packets
	m_network = netPlayer;
	m_network->setPlayerObject(this);
	setGUID(NetworkManager::i().getNetPlayer()->getMyGUID());
	EntityManager::i().registerRaknetEntity(this);

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
	
	

	animationMachine = new AnimationMachine(this);

	

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

	listaWeapons->insertar(pistola);
	tienePistola = true;
	pistola->setEquipada(true);
	bindWeapon();




	listaWeapons->valorActual()->getNode()->setVisible(true);

	/*listaWeapons->insertar(sniper);
	sniper->setEquipada(true);
	tieneSniper = true;
	bindWeapon();*/

	//Creas el nodo(grafico)

}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)


	ResourceProvider& rp = Settings::i().GetResourceProvider();

	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createAnimatedNode(
		"../media/personaje1", 191
	);
	m_nodo->setAnimation("correrAsalto", 0, 16, true);
	m_nodo->setAnimation("idleAsalto", 17, 47, true);
	m_nodo->setAnimation("muerte", 48, 93, false);
	m_nodo->setAnimation("saltoAsalto", 94, 117, false);
	m_nodo->setAnimation("correrRocket", 118, 134, true);
	m_nodo->setAnimation("idleRocket", 136, 166, true);
	m_nodo->setAnimation("saltoRocket", 168, 190, false);
	m_nodo->setCurrentAnimation("correrAsalto");
	m_nodo->setFrameTime(milliseconds(20));
	m_nodo->setScale(Vec3<float>(0.023f, 0.023f, 0.023f));

	m_nodo->setVisible(false);

	//Start runing
	animationMachine->SetCurrentAnimation(&Death::i());

	animationMachine->ChangeState(&Death::i());



	radius = 0.5f;
	height = 3.f;
	mass = 70.f;

	p_controller = PhysicsEngine::i().createCapsuleKinematicCharacter(this, radius, height, mass);

	p_controller->m_acceleration_walk = 1.1f;
	p_controller->m_deceleration_walk = 8.f;
	p_controller->m_maxSpeed_walk = 1.f;


	life_component->resetVida();

	p_controller->reset(PhysicsEngine::i().m_world);

	setPosition(Map::i().searchSpawnPoint());



}




void Player::update(Time elapsedTime)
{
	

	calcularMovimiento();

	life_component->update();
	
	p_controller->updateAction(PhysicsEngine::i().m_world, TimePerFrameClass::GetTimePerFrame().asSeconds());

	

	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));

	
	if (!life_component->isDying()) {
		m_renderState.updateRotations(Vec3<float>(0, GraphicEngine::i().getActiveCamera()->getRotation().getY(), 0));
	}

	//update animations
	//animationMachine->Update();

	if (m_network->isConnected()) {

		unsigned char useTimeStamp; // Assign this to ID_TIMESTAMP
		RakNet::Time timeStamp; // Put the system time in here returned by RakNet::GetTime()
		unsigned char typeId; // This will be assigned to a type I've added after ID_USER_PACKET_ENUM, lets say ID_SET_TIMED_MINEf
		Vec3<float> position;
		Vec3<float> rotation;
		RakNet::RakNetGUID guid;

		useTimeStamp = ID_TIMESTAMP;
		timeStamp = RakNet::GetTime();
		typeId = MOVIMIENTO;
		RakNet::BitStream myBitStream;
		myBitStream.Write(useTimeStamp);
		myBitStream.Write(timeStamp);
		myBitStream.Write(typeId);
		myBitStream.Write(getLifeComponent().isDying());
		myBitStream.Write(p_controller->onGround());
		myBitStream.Write(getCurrentWeaponType());
		myBitStream.Write(moving);
		myBitStream.Write(getRenderState()->getPosition());
		myBitStream.Write(getRenderState()->getRotation());
		myBitStream.Write(getGuid());

		m_network->peer->Send(&myBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_network->getServerGUID(), false);
		
	}

	if (m_renderState.getPosition().getY() < -200) {
		getLifeComponent().restaVida(100, m_guid);
	}

	SoundManager::i().setListenerPosition(m_renderState.getPosition(), GraphicEngine::i().getActiveCamera()->getVectorDirection());

	//m_nodoPersonaje->setPosition(m_renderState.getPosition());

	updateRelojes();

}

void Player::calcularMovimiento() {
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
	if (life_component->isDying() == false) {
		// Ejecuta todos los comandos
		InputHandler::i().excuteCommands(this);
	}

	setIsMoving(isMoving);

	speedFinal.normalise();
	p_controller->setWalkDirection(btVector3(speedFinal.getX(), speedFinal.getY(), speedFinal.getZ()));
}


void Player::handleInput()
{
	InputHandler::i().handleInput();
}



void Player::borrarContenido()
{
	delete animationMachine;

	PhysicsEngine::i().removeKinematic(p_controller);

}

void Player::handleMessage(const Message & message)
{
	if (!m_godMode) {

	
		if (message.mensaje == "COLLISION") {
		
		}else if (message.mensaje == "COLISION_ROCKET") {
			NetworkManager::i().dispatchMessage(*(TImpactoRocket*)message.data, IMPACTO_ROCKET);

			TImpactoRocket* imp = static_cast<TImpactoRocket*>(message.data);
			if (imp != nullptr) {
				getLifeComponent().restaVida(imp->damage, imp->guidDisparado);
				relojSangre.restart();
			}
			

			delete message.data;
		}
		else if (message.mensaje == "COLISION_BALA") {
				//Este float * es una referencia a una variable de clase asi que no hay problema
				TImpactoBala* impacto = static_cast<TImpactoBala*>(message.data);

				if (impacto != nullptr) {
					getLifeComponent().restaVida(impacto->damage, impacto->guidDisparado);
					relojSangre.restart();

					delete impacto;
				}

				
		
		}

	}
}

bool Player::handleTrigger(TriggerRecordStruct * Trigger)
{

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
	Character* hitted = nullptr;

	if (listaWeapons->valorActual()->canShoot()) {	

		

		//Devuelve una entity si le ha dado a alguien
		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		targetToWorld(target);

		hitted = listaWeapons->valorActual()->shoot(target);

		//GraphicEngine::i().getActiveCamera()->cameraRecoil();

		TriggerSystem::i().RegisterTrigger(kTrig_EnemyShootSound, 1002, m_id, m_renderState.getPosition(), 50, milliseconds(50), false);
	}
	

	if (hitted != nullptr && !hitted->getLifeComponent()->isDying()) {
		relojHit.restart();
	}


}


void Player::move_up()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	targetToWorld(target);

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;


	speedFinal.addX(speed.getX());
	speedFinal.addZ(speed.getZ());



	isMoving = true;
}


void Player::move_down()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	targetToWorld(target);

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(-speed.getX());
	speedFinal.addZ(-speed.getZ());

	isMoving = true;
}

void Player::move_right()
{
	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	targetToWorld(target);

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;

	speedFinal.addX(-speed.getZ());
	speedFinal.addZ(speed.getX());


	isMoving = true;
}

//Por necesidad de nuestro motor le sumamos al target devuelvto por la camara la posicion del player
void Player::targetToWorld(Vec3<float>& target) {
	Vec3<float> pos = getPosition();
	pos.addY(3.f);
	target += pos;
}

void Player::move_left()
{
	

	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
	targetToWorld(target);

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
	SceneManager::i().zoomZout();
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
	SceneManager::i().zoomZout();
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

	if (listaWeapons->valorActual()->getClassName() == "Sniper") {
		if (!apuntando) {
			SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("Aim.mp3", "sounds"), Sound::type::sound);
			SceneManager::i().ziZoom(38.0f);
			apuntando = true;
		}
		else {
			SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("Aim.mp3", "sounds"), Sound::type::sound);
			SceneManager::i().zoomZout();
			apuntando = false;
		}
	}

}

void Player::restablecerMira()
{
	SceneManager::i().zoomZout();
}

void Player::impulsar(Vec3<float> force)
{
	btVector3 fuerza(force.getX(), force.getY(), force.getZ());
	p_controller->applyImpulse(fuerza);
}

void Player::godMode()
{
	std::cout << "God mode" << std::endl;
	m_godMode = !m_godMode;
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

	bindWeapon();

	SceneManager::i().zoomZout();
	apuntando = false;
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
	return life_component->getVida();
}

bool Player::isDying() {
	return life_component->isDying();
}

bool Player::isOnGround() const
{
	return p_controller->onGround();
}

