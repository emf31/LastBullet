#include "Rocket.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"


Rocket::Rocket() : Entity(-1, NULL)
{

}



Rocket::~Rocket()
{
}

void Rocket::inicializar()
{
}

void Rocket::update(Time elapsedTime)
{

}

void Rocket::handleInput()
{
}

void Rocket::cargarContenido()
{

	m_nodo = GraphicEngine::i().createNode(Vec3<float>(100, 200, 0), Vec3<float>(100, 100.f, 100.f), "../media/ice0.jpg", "");

	m_renderState.setPosition(Vec3<float>(100, 200, 0));

	m_rigidBody = PhysicsEngine::createBoxRigidBody(this, Vec3<float>(100.f, 100.f, 100.f), 0.0f, DISABLE_SIMULATION);

}



void Rocket::borrarContenido()
{
}

void Rocket::handleMessage(const Message & message)
{
}

void Rocket::setPosition(Vec3<float> pos) {

	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}