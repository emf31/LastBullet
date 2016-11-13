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


	//m_renderState.setPosition(Vec3<float>(2, 100, 0));

	m_rigidBody = PhysicsEngine::i().createSphereRigidBody(this, 0.7f, 2.f, DISABLE_DEACTIVATION);

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


void Granada::shoot(const btVector3& posicionPlayer) {

	if (estado== CARGADO) {

		Vec3<float> posicion(posicionPlayer.x() + 3, posicionPlayer.y() + 5, posicionPlayer.z());
		btTransform transform = m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(posicion.getX(), posicion.getY(), posicion.getZ()));


		getRenderState()->updatePositions(posicion);

		setPosition(posicion);

		printf("GRANADA DISPARADO\n");
		btVector3 FUERZA(1.5, 1.5, 1.5);


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		resetRigidBody();//DEBATIR: EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 


		m_rigidBody->applyCentralForce(force);
		//rocket->m_rigidBody->setCollisionFlags(4);

		setEstado(DISPARADO);
		clockRecargaGranada.restart();
	}

}