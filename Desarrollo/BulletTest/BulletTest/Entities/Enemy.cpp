
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
	animationMachine = new AnimationMachine(this);

	

	
}

void Enemy::cargarContenido()
{
	ResourceProvider& rp = Settings::i().GetResourceProvider();

	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createAnimatedNode(
		"../media/personaje1", 118
	);
	m_nodo->setAnimation("correr", 0, 16, true);
	m_nodo->setAnimation("idle", 17, 47, true);
	m_nodo->setAnimation("muerte", 48, 93, false);
	m_nodo->setAnimation("salto", 94, 117, false);
	m_nodo->setCurrentAnimation("correr");
	m_nodo->setFrameTime(milliseconds(20));
	m_nodo->setScale(Vec3<float>(0.023f, 0.023f, 0.023f));

	//Start runing
	animationMachine->SetCurrentAnimation(&Run::i());

	animationMachine->ChangeState(&Run::i());

	radius = 0.5f;
	height = 3.f;
	mass = 1000.f;


	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, height, radius, mass, DISABLE_SIMULATION);

	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;


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


	moving = true;

	if (m_renderState.getPreviousPosition().getX() == m_renderState.getPosition().getX() &&
		m_renderState.getPreviousPosition().getY() == m_renderState.getPosition().getY() &&
		m_renderState.getPreviousPosition().getZ() == m_renderState.getPosition().getZ()) 
	{
		moving = false;
	}
		

}

void Enemy::handleInput()
{
}



void Enemy::borrarContenido()
{
	delete animationMachine;

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


		//Solo informar al player del impacto al enemigo si este esta vivo
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

void Enemy::setVisibilidadBilboardSync()
{
	m_nodo->setTexture("../media/body01green.png", 1);
}


bool Enemy::isOnGround() const
{
	return onGround;
}

bool Enemy::isDying() {
	return getLifeComponent()->isDying();
}