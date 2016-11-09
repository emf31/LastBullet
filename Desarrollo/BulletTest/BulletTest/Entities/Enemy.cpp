
#include "Enemy.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor de Red/Estructuras.h"
#include "../Motor de Red/Cliente.h"
#include "../Entities/EntityManager.h"
#include <iostream>


Enemy::Enemy(const std::string& name, RakNet::RakNetGUID guid) : Entity(-1, NULL, name, guid)
{
}


Enemy::~Enemy()
{
}

void Enemy::inicializar()
{
}

void Enemy::update(Time elapsedTime)
{

}

void Enemy::handleInput()
{
}

void Enemy::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 100, 0), Vec3<float>(0.05f, 0.05f, 0.05f), "", "../media/ArmyPilot.b3d");
	m_nodo->setTexture("../media/body01.png", 1);
	m_nodo->setTexture("../media/head01.png", 0);
	m_nodo->setTexture("../media/m4tex.png", 2);

	m_renderState.setPosition(Vec3<float>(0, 100, 0));

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
	std::cout << "Numero Paquetes: " << m_positions.size() << std::endl;
	
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

