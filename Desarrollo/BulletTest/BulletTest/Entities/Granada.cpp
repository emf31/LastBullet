#include "Granada.h"
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Cliente.h>


Granada::Granada() : Entity(-1, NULL)
{

}



Granada::~Granada()
{
}

void Granada::inicializar()
{
	fuerza = Vec3<float>(60.f,100.f, 60.f);
}

void Granada::update(Time elapsedTime)
{
	if (estado == GRANADADISPARADA) {
		btVector3 Point = m_rigidBody->getCenterOfMassPosition();
		getRenderState()->updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));
		// Set rotation
		vector3df Euler;
		const btQuaternion& TQuat = m_rigidBody->getOrientation();
		quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
		q.toEuler(Euler);
		Euler *= RADTODEG;

		m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));


		if (clockRecargaGranada.getElapsedTime().asSeconds()>timeRecargaGranada) {
			setEstado(GRANADACARGADA);


			Message msg1(this, "BORRATE", NULL);

			MessageHandler::i().sendMessage(msg1);


			PhysicsEngine::i().removeRigidBody(m_rigidBody);
		
		}
	}
	
}

void Granada::handleInput()
{
}

void Granada::cargarContenido()
{

	//m_nodo = GraphicEngine::i().createNode(Vec3<float>(2, 100, 0), Vec3<float>(0.01, 0.01, 0.01), "", "../media/granada.obj");
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(0.15f, 0.15f, 0.15f), "../media/WPNT_MK2Grenade_Base_Color.tga", "../media/Granada/granada.obj");
	m_nodo->setVisible(false);

	//m_renderState.setPosition(Vec3<float>(2, 100, 0));

	/*m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);

	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Rocket;
	proxy->m_collisionFilterMask = col::rocketCollidesWith;*/

	radioExplosion=30.f;


}



void Granada::borrarContenido()
{
}

void Granada::handleMessage(const Message & message)
{

	if (message.mensaje == "COLLISION") {
		if (static_cast<Entity*>(message.data)->getClassName() != "Player" && estado==GRANADADISPARADA) {
			//std::cout << "EL MISIL HA CHOCADO CONTRA LA PARED" << std::endl;
			//PhysicsEngine::i().removeRigidBody(m_rigidBody);

		}
		
	}

	if (message.mensaje == "BORRATE") {

		if (m_explosion != NULL) {
			PhysicsEngine::i().removeGhostObject(m_explosion);
		}
			


		m_explosion = PhysicsEngine::i().createSphereShape(this, radioExplosion);


		//solo se comprueba si te han quitado vida a ti mismo ya que la granada esta en todos los clientes y cada uno comprueba si le han quitado vida a el.
		Player* myentity = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
		myentity->getLifeComponent().restaVida(explosion(m_renderState.getPosition(), myentity->getRenderPosition(), 30.f),guidLanzador);

		//volvemos a resetear el guidLanzador
		guidLanzador = RakNet::UNASSIGNED_RAKNET_GUID;

//		GraphicEngine::i().removeNode(m_nodo);

	}
}

void Granada::setPosition(const Vec3<float>& pos) {

	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}


bool Granada::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void Granada::shoot(const btVector3& posicionPlayer) {

	if (estado== GRANADACARGADA) {
		m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);
		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;

		m_nodo->setVisible(true);

		//Vec3<float> posicion(posicionPlayer.x() + 3, posicionPlayer.y() + 5, posicionPlayer.z());

		setPosition(GraphicEngine::i().getActiveCamera()->getPosition());

		btVector3 FUERZA(fuerza.getX(), fuerza.getY(), fuerza.getZ());


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		//force.setY(force.getY());

		m_rigidBody->applyCentralImpulse(force);
		

		if (Cliente::i().isConected()) {
			TGranada granada;
			granada.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
			granada.origen = m_renderState.getPosition();
			granada.direction = direccion;
			Cliente::i().dispatchMessage(granada, LANZAR_GRANADA);
		}
		
		//logica granada servidor: 
		//un player dispara la granada, se envia un mensaje al server con un TGranada desde ese player, entonces se le pasa la posicion de origen y el vector direccion
		//desde el server se envia un mensaje de que un enemigo ha disparado una granada, entonces envia un mensaje al resto de clientes y 
		//se llama al server shoot desde la granada del enemigo que la disparo que lo que hace es aplicarle una fuerza con el origen que tiene y el vector direccion
		//esta granada seria un entity entonces se añaderia a la lista de entities y se haria su update en cada unpdate.
		//rocket->m_rigidBody->setCollisionFlags(4);

		setEstado(GRANADADISPARADA);
		clockRecargaGranada.restart();
	}

}

void Granada::serverShoot(TGranada& g) {

	if (estado == GRANADACARGADA) {
		m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);
		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;

		//nos guardamos el guid de la persona que lanza por si luego lo mata poder actualizar la tabla
		guidLanzador = g.guid;

		setPosition(g.origen);

		btVector3 FUERZA(fuerza.getX(), fuerza.getY(), fuerza.getZ());

		btVector3 direccion2(g.direction.getX(), g.direction.getY(), g.direction.getZ());

		btVector3 force = direccion2 * FUERZA;

		m_rigidBody->applyCentralImpulse(force);

		setEstado(GRANADADISPARADA);
		clockRecargaGranada.restart();
	}

}

float Granada::explosion(Vec3<float> posExplosion, Vec3<float> posCharacter, float radio)
{

	int vidaRestada = 0;

	Vec3<float> vector = posExplosion - posCharacter;
	float distancia = vector.Magnitude();
	if (distancia < radio) {
		
		
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			//(radio-distancia)/((2*radio)/3)
			vidaRestada = int(100*((radio - distancia) / ((2 * radio) / 3)));

		}
	}
	

	return float(vidaRestada);

}
