
#include "Enemy.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor de Red/Estructuras.h"
#include "../Motor de Red/Cliente.h"
#include "../Entities/EntityManager.h"
#include <iostream>


Enemy::Enemy(const std::string& name, RakNet::RakNetGUID guid) : Entity(-1, NULL, name, guid)
{
	animation = new Animation();
}


Enemy::~Enemy()
{

}

void Enemy::inicializar()
{
	
}

void Enemy::update(Time elapsedTime)
{
	updateState();
	updateAnimation();
	isMoving = true;
	if (m_renderState.getPreviousPosition().getX() == m_renderState.getPosition().getX() &&
		m_renderState.getPreviousPosition().getY() == m_renderState.getPosition().getY() &&
		m_renderState.getPreviousPosition().getZ() == m_renderState.getPosition().getZ())
		isMoving = false;
}

void Enemy::handleInput()
{
}

void Enemy::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createAnimatedNode(Vec3<float>(0, 100, 0), Vec3<float>(0.05f, 0.05f, 0.05f), "", "../media/ArmyPilot.b3d"));
	m_nodo->setTexture("../media/body01.png", 1);
	m_nodo->setTexture("../media/head01.png", 0);
	m_nodo->setTexture("../media/m4tex.png", 2);

	m_renderState.setPosition(Vec3<float>(0, 100, 0));

	animation->addAnimation("Default", 0, 0);
	animation->addAnimation("Run_Forwards", 1, 69);
	animation->addAnimation("Run_backwards", 70, 138);
	animation->addAnimation("Walk", 139, 183);
	animation->addAnimation("Jump", 184, 219);
	animation->addAnimation("Jump2", 184, 219);
	animation->addAnimation("Idle", 220, 472);
	animation->addAnimation("AimRunning", 473, 524);

	m_animState = quieto;

	radius = 1.2f;
	height = 7.3f;
	mass = 0.f;

	//Al mundo de fisicas del cliente añadimos una representacion del objeto fisico pero no calcula fisicas
	//(servira para hacer los raycast)


	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this,height, radius, mass, DISABLE_SIMULATION);

}

void Enemy::borrarContenido()
{

	GraphicEngine::i().removeNode(m_nodo);
}

//Teletransporta un enemigo a la posicion que le pasas
void Enemy::setPosition(Vec3<float> pos) {

	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}


void Enemy::updateEnemigo(Vec3<float> pos) {
	m_renderState.updatePositions(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY() + (height / 2) + radius, pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);

}

void Enemy::handleMessage(const Message & message)
{
	if (message.mensaje == "COLISION_BALA") {
		//TODO
		printf("le has dado a un enemigo\n");
		Cliente::i().enviarDisparo(m_guid);
	}
}

//pila posiciones
void Enemy::encolaPos(TPlayer pos)
{
	m.lock();
	// Añadir a la cola
	m_positions.push(pos.position);
	m_renderState.setVelocity(pos.velocidad);

	m.unlock();
}

void Enemy::desEncolaPos()
{	
	m.lock();
	//std::cout << "Numero Paquetes: " << m_positions.size() << std::endl;
	
	if (m_positions.size() > 3) {
		Vec3<float> new_pos;
		while (!m_positions.empty()) {
			new_pos = m_positions.front();
			//lo borramos de la cola
			m_positions.pop();
			//llamamos al update con la nueva posicion
		}
		updateEnemigo(new_pos);
	}

	else if (m_positions.size() > 0) {
		Vec3<float> new_pos;
			new_pos = m_positions.front();
			//lo borramos de la cola
			m_positions.pop();
			//llamamos al update con la nueva posicion
		updateEnemigo(new_pos);
	}else {
		updateEnemigo(m_renderState.getPosition() + m_renderState.getVelocity() * (1.f / 7.f));
		
	}
	m.unlock();

}
/////////

//pila rotaciones

void Enemy::encolaRot(TPlayer rot)
{
	m.lock();
	// Añadir a la cola
	m_rotations.push(rot.position);

	m.unlock();
}

void Enemy::desEncolaRot()
{
	m.lock();

	if (m_rotations.size() > 3) {
		Vec3<float> new_rot;
		while (!m_rotations.empty()) {
			new_rot = m_rotations.front();
			//lo borramos de la cola
			m_rotations.pop();
			//llamamos al update con la nueva posicion
		}
		
		m_renderState.updateRotations(new_rot);
	}

	else if (m_positions.size() > 0) {
		Vec3<float> new_rot;
		new_rot = m_rotations.front();
		//lo borramos de la cola
		m_rotations.pop();
		//llamamos al update con la nueva posicion
		m_renderState.updateRotations(new_rot);
	}
	m.unlock();

}
/////////

void Enemy::updateAnimation()
{
	switch (m_animState)
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

void Enemy::updateState()
{
	/*if (!p_controller->onGround() && p_controller->numJumps == 0) {
		m_playerState = saltando;
	}
	else if (!p_controller->onGround() && p_controller->numJumps == 1) {
		m_playerState = saltando2;
	}
	else*/ if (isMoving) {
		m_animState = andando;
	}
	else {
		m_animState = quieto;
	}
}
