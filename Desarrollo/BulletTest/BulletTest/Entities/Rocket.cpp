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

	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

}

void Rocket::handleInput()
{
}

void Rocket::cargarContenido()
{

	m_nodo = GraphicEngine::i().createNode(Vec3<float>(2, 100, 0), Vec3<float>(1, 1, 1), "../media/ice0.jpg", "");
	m_renderState.setPosition(Vec3<float>(2, 100, 0));

	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1, 1, 1), 1.f, DISABLE_DEACTIVATION);

}

void Rocket::resetRigidBody()
{
	PhysicsEngine::i().removeRigidBody(m_rigidBody);//EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 
	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1, 1, 1), 1.f, DISABLE_DEACTIVATION);
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

