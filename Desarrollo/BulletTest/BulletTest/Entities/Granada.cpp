#include "Granada.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"


Granada::Granada() : Entity(-1, NULL)
{

}



Granada::~Granada()
{
}

void Granada::inicializar()
{
}

void Granada::update(Time elapsedTime)
{

	/*btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));*/

}

void Granada::handleInput()
{
}

void Granada::cargarContenido()
{

	//m_nodo = GraphicEngine::i().createNode(Vec3<float>(2, 100, 0), Vec3<float>(0.01, 0.01, 0.01), "", "../media/granada.obj");
	m_nodo= GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(1.f, 1.f, 1.f), "../media/ice0.jpg", "");


	m_renderState.setPosition(Vec3<float>(2, 100, 0));

	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 0.7f, 1.f, 0.1f, DISABLE_DEACTIVATION);

	PhysicsEngine::i().removeRigidBody(m_rigidBody);
}

void Granada::resetRigidBody()
{
	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 0.7f, 1.f, 0.1f, DISABLE_DEACTIVATION);

	//m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1, 1, 1), 0.1f, DISABLE_DEACTIVATION);
	//m_rigidBody = PhysicsEngine::i().createSphereRigidBody(this, 1, 0.1f);
}


void Granada::borrarContenido()
{
}

void Granada::handleMessage(const Message & message)
{

	if (message.mensaje == "COLLISION") {
		if (static_cast<Entity*>(message.data)->getClassName() != "Player" && estado==DISPARADO) {
			//std::cout << "EL MISIL HA CHOCADO CONTRA LA PARED" << std::endl;
			//PhysicsEngine::i().removeRigidBody(m_rigidBody);

		}
		
	}
}

void Granada::setPosition(Vec3<float> pos) {

	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}

