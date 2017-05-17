
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
#include <Run.h>
#include <Death.h>
#include <ResourceProvider.h>
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

	footsteps = SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("footsteps.wav", "sounds"), getRenderState()->getPosition(), true);
	footsteps->setIsPaused(true);

	animationMachine = new AnimationMachine(this);

	//Start runing
	animationMachine->SetCurrentAnimation(&Run::i());
	
}

void Enemy::update(Time elapsedTime)
{
	animationMachine->Update();

	if (NetworkManager::i().isMovementPrediction()) {
		nPrediction.interpolateWithPrediction();
	}
	else {
		nPrediction.interpolateWithoutPrediction();
	}

	updateState();


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
	m_nodo = GraphicEngine::i().createAnimatedNode(
		rp.getResourceGroupDirectory("characters"), 70
		);
	m_nodo->setAnimation("correr", 0, 16, true);
	m_nodo->setAnimation("muerte", 17, 69, false);
	m_nodo->setCurrentAnimation("correr");
	m_nodo->setFrameTime(milliseconds(25));
	m_nodo->setScale(Vec3<float>(0.04f, 0.04f, 0.04f));

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
	//granada->serverShoot(g);
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