#include "Granada.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor de Red/Cliente.h"


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
	if (estado == DISPARADO) {
		


		if (clockRecargaGranada.getElapsedTime().asSeconds()>timeRecargaGranada) {
			setEstado(CARGADO);
			PhysicsEngine::i().removeRigidBody(m_rigidBody);

		
		}
	}

	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	getRenderState()->updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));
	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;

	m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));
	
}

void Granada::handleInput()
{
}

void Granada::cargarContenido()
{

	//m_nodo = GraphicEngine::i().createNode(Vec3<float>(2, 100, 0), Vec3<float>(0.01, 0.01, 0.01), "", "../media/granada.obj");
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(1.f, 1.f, 1.f), "../media/ice0.jpg", "../media/plasma grenade.obj"));


	//m_renderState.setPosition(Vec3<float>(2, 100, 0));

	m_rigidBody = PhysicsEngine::i().createSphereRigidBody(this, 1.25f, 0.5f);

	PhysicsEngine::i().removeRigidBody(m_rigidBody);
}

void Granada::resetRigidBody()
{
	PhysicsEngine::i().removeRigidBody(m_rigidBody);
	m_rigidBody = PhysicsEngine::i().createSphereRigidBody(this, 1.25f, 0.5f);

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
	m_nodo.get()->setPosition(pos);

}


void Granada::shoot(const btVector3& posicionPlayer) {

	if (estado== CARGADO) {

		Vec3<float> posicion(posicionPlayer.x() + 3, posicionPlayer.y() + 5, posicionPlayer.z());
		/*btTransform transhobbitform = m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(posicion.getX(), posicion.getY(), posicion.getZ()));*/


		//getRenderState()->updatePositions(posicion);

		setPosition(posicion);

		printf("GRANADA DISPARADO\n");
		btVector3 FUERZA(20.f,20.f,20.f);


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		resetRigidBody();//DEBATIR: EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 


		m_rigidBody->applyCentralForce(force);
		TGranada granada;
		granada.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
		granada.origen = posicion;
		granada.direction = direccion;
		Cliente::i().lanzarGranada(granada);
		//logica granada servidor: 
		//un player dispara la granada, se envia un mensaje al server con un TGranada desde ese player, entonces se le pasa la posicion de origen y el vector direccion
		//desde el server se envia un mensaje de que un enemigo ha disparado una granada, entonces envia un mensaje al resto de clientes y 
		//se llama al server shoot desde la granada del enemigo que la disparo que lo que hace es aplicarle una fuerza con el origen que tiene y el vector direccion
		//esta granada seria un entity entonces se a�aderia a la lista de entities y se haria su update en cada unpdate.
		//rocket->m_rigidBody->setCollisionFlags(4);

		setEstado(DISPARADO);
		clockRecargaGranada.restart();
	}

}

void Granada::serverShoot(TGranada g) {

	if (estado == CARGADO) {

		setPosition(g.origen);

		printf("GRANADA DISPARADA DESDE ENEMIGO\n");
		btVector3 FUERZA(20.f, 20.f, 20.f);

		btVector3 direccion2(g.direction.getX(), g.direction.getY(), g.direction.getZ());

		btVector3 force = direccion2 * FUERZA;

		resetRigidBody();//DEBATIR: EL RIGID BODY SE VUELVE LOCO, ASI QUE LO RESETEO 


		m_rigidBody->applyCentralForce(force);
		//rocket->m_rigidBody->setCollisionFlags(4);

		setEstado(DISPARADO);
		clockRecargaGranada.restart();
	}

}