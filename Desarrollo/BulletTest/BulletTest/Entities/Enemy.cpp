
#include "Enemy.h"
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <Estructuras.h>
#include <EntityManager.h>
#include <iostream>
#include <NetworkManager.h>
#include <Settings.h>
#include <GUIManager.h>
#include <DebugMenuGUI.h>


//Clase que representa a un enemigo, esta clase recibe mensajes de sincronizacion de movimiento. 
//Tambien se encarga de enviar los mensajes apropiados al servidor cuando halla recibido un impacto
//de bala o de rocket.

Enemy::Enemy(const std::string& name, RakNet::RakNetGUID guid) : Character(-1, NULL, name, guid), nPrediction(this)
{


	EntityManager::i().registerRaknetEntity(this);
}


Enemy::~Enemy()
{

}

void Enemy::inicializar()
{
	animation = new Animation();
	granada = new Granada(this);
	//m_isDying = false;

	footsteps = SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("footsteps.wav", "sounds"), getRenderState()->getPosition(), true);
	footsteps->setIsPaused(true);
	
}

void Enemy::update(Time elapsedTime)
{
	//desencolaMovimiento();

	if (NetworkManager::i().isMovementPrediction()) {
		nPrediction.interpolateWithPrediction();
	}
	else {
		nPrediction.interpolateWithoutPrediction();
	}



	updateState();
	//updateAnimation();

	/*//si estas 5 segundo sin recibir paquetes de sincronizacion se pone en rojo
	if (lastSyncPacket.getElapsedTime().asSeconds() >= 5) {
		m_nodo->setTexture("../media/body01red.png", 1);
	}
	//si el verde supera los 2 segundos se reestablece la skin original
	if (billboardTime.getElapsedTime().asSeconds() >= 2) {
		m_nodo->setTexture("../media/body01.png", 1);
		billboardTime.restart();
	}*/

	isMoving = true;

	if (m_renderState.getPreviousPosition().getX() == m_renderState.getPosition().getX() &&
		m_renderState.getPreviousPosition().getY() == m_renderState.getPosition().getY() &&
		m_renderState.getPreviousPosition().getZ() == m_renderState.getPosition().getZ())
		isMoving = false;

	if (isMoving) {
		footsteps->setIsPaused(false);
	}
	else if (footsteps != NULL) {
		footsteps->setIsPaused(true);
	}


	//m_pStateMachine->Update();

	/*if (m_isDying && relojMuerte.getElapsedTime().asSeconds() > 3) {
	m_isDying = false;
	}*/

}

void Enemy::handleInput()
{
}

void Enemy::cargarContenido()
{
	ResourceProvider& rp = Settings::i().GetResourceProvider();
	
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(
		Vec3<float>(0, 100, 0), 
		Vec3<float>(0.075f, 0.075f, 0.075f), 
		"", 
		rp.getFinalFilename("personaje2.obj", "characters"));


	//GraphicEngine::i().createBillboardText(m_nodo, m_name, Vec2f(100, 10), Vec3<float>(0, 30, 0), Color4f(255,255,255,0));
	

	animation->addAnimation("Default", 0, 0);
	animation->addAnimation("Run_Forwards", 1, 69);
	animation->addAnimation("Run_backwards", 70, 138);
	animation->addAnimation("Walk", 139, 183);
	animation->addAnimation("Jump", 184, 219);
	animation->addAnimation("Jump2", 184, 219);
	animation->addAnimation("Idle", 220, 472);
	animation->addAnimation("AimRunning", 473, 524);


	granada->inicializar();
	granada->cargarContenido();

	m_animState = quieto;

	radius = 0.5f;
	height = 3.f;
	mass = 1000.f;


	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, height, radius, mass, DISABLE_SIMULATION);

	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;

}

void Enemy::borrarContenido()
{
	delete animation;

	PhysicsEngine::i().removeRigidBody(m_rigidBody);

	//GraphicEngine::i().removeNode(m_nodo);
	
}

//Teletransporta un enemigo a la posicion que le pasas
void Enemy::setPosition(const Vec3<float>& pos)
{
	Vec3<float> aux = pos;
	aux.setY(aux.getY() - 0.5f);
	m_renderState.setPosition(aux);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY() + (height / 2)/* + radius*/, pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
}


void Enemy::updateEnemigo(Vec3<float> pos) {
	Vec3<float> aux = pos;
	aux.setY(aux.getY() - 0.5f);
	m_renderState.updatePositions(aux);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY() + (height / 2)/* + radius*/ , pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);

}

void Enemy::handleMessage(const Message & message)
{
	if (message.mensaje == "COLISION_BALA") {
		if (!isDying()) {
			
			TImpactoBala impacto = *static_cast<TImpactoBala*>(message.data);

			NetworkManager::i().dispatchMessage(impacto, IMPACTO_BALA);

		}

	}
	else if (message.mensaje == "ARMAUP") {
		//TODO poner el codigo de cambiar el modelo del arma hacia arriba

	}
	else if (message.mensaje == "ARMADOWN") {
		//TODO poner el codigo de cambiar el modelo del arma hacia abajo

	}
	else if (message.mensaje == "COLISION_ROCKET") {

		NetworkManager::i().dispatchMessage(*(TImpactoRocket*)message.data, IMPACTO_ROCKET);

		Player* p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));

		if (p && !isDying()) {
			p->relojHit.restart();
		}

		delete message.data;

	}
}

bool Enemy::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}



void Enemy::lanzarGranada(TGranada g)
{
	granada->serverShoot(g);
}

void Enemy::setVisibilidadBilboardSync()
{
	m_nodo->setTexture("../media/body01green.png", 1);
}


/*void Enemy::updateAnimation()
{
	switch (m_animState)
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
}*/

void Enemy::updateState()
{
	if (isMoving) {
		m_animState = andando;
	}
	else {
		m_animState = quieto;
	}
}




bool Enemy::isDying() {
	return getLifeComponent()->isDying();
}