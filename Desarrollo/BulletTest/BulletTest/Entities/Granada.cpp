#include "Granada.h"
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <EntityManager.h>
#include <NetworkManager.h>
#include <Quaternion.h>


Granada::Granada(Character* owner) : EntActive(-1, NULL)
{
	m_character = owner;
}



Granada::~Granada()
{
}

void Granada::inicializar()
{
	fuerza = Vec3<float>(15.f ,35.f, 15.f);
	radioExplosion = 10.f;
	height = 0.3f;
	radius = 0.1f;
	mass = 1.f;
	timeRecargaGranada = 2.f;
	restitution = 1.f;
	estado = GRANADACARGADA;
	guidLanzador = RakNet::UNASSIGNED_RAKNET_GUID;
}

void Granada::update(Time elapsedTime)
{
	if (estado == GRANADADISPARADA) {
		btVector3 Point = m_rigidBody->getCenterOfMassPosition();
		getRenderState()->updatePositions(Vec3<float>((float)Point[0], (float)Point[1], (float)Point[2]));
		// Set rotation
		btVector3 Euler;
		const btQuaternion& TQuat = m_rigidBody->getOrientation();
		quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
		q.toEuler(cons(Euler));

		Euler *= RADTODEG;


		m_renderState.updateRotations(Vec3<float>(Euler.getX(), Euler.getY(), Euler.getZ()));


		if (clockRecargaGranada.getElapsedTime().asSeconds() > timeRecargaGranada) {
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
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(0.03f, 0.03f, 0.03f), "../media/WPNT_MK2Grenade_Base_Color.tga", "../media/Granada/granada.obj");
	m_nodo->setVisible(false);

}

void Granada::borrarContenido()
{
}

void Granada::handleMessage(const Message & message)
{

	if (message.mensaje == "BORRATE") {

		if (m_explosion != NULL) {
			PhysicsEngine::i().removeGhostObject(m_explosion);
		}

		m_explosion = PhysicsEngine::i().createSphereShape(this, radioExplosion);




		//solo se comprueba si te han quitado vida a ti mismo y a los bots si tienes ya que la granada 
		//esta en todos los clientes y cada uno comprueba si le han quitado vida a el.

		std::list<Character*>characters = EntityManager::i().getPlayerAndBots();

		float damage;
		///Recorremos todos el player y los enemies para ver si le ha dado a alguno
		for (std::list<Character*>::iterator it = characters.begin(); it != characters.end(); it++) {

			Character* myentity = *it;

			damage = explosion(myentity, cons(m_rigidBody->getCenterOfMassPosition()), radioExplosion);


			if (damage > 0) {

				TImpactoRocket gran;
				gran.guidDisparado = m_character->getGuid();
				gran.guidImpactado = myentity->getGuid();
				gran.damage = damage;

				Message msg(myentity, "COLISION_GRANADA", &gran);
				MessageHandler::i().sendMessageNow(msg);

			}
		}


		//volvemos a resetear el guidLanzador
		guidLanzador = RakNet::UNASSIGNED_RAKNET_GUID;

		m_nodo->setVisible(false);

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
		m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, height, radius, mass);
		m_rigidBody->setRestitution(restitution);


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


		m_rigidBody->applyCentralImpulse(force);
		

		TGranada granada;
		granada.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
		granada.origen = m_renderState.getPosition();
		granada.direction = direccion;

		NetworkManager::i().dispatchMessage(granada, LANZAR_GRANADA);
		
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
		m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, height, radius, mass);
		m_rigidBody->setRestitution(restitution);

		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;

		m_nodo->setVisible(true);

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

//Calcula la el daño que hace la explosion de un rocket en funcion del punto
//de impacto, la posicion del player impactado y un radio de alcance. Además aplica un impulso
//y en caso de ser un enemigo lo comunica al servidor.
float Granada::explosion(Character* player, const Vec3<float>& posExplosion, float radio)
{
	int vidaRestada = 0;

	Vec3<float> vector = posExplosion - player->getRenderState()->getPosition();
	float distancia = vector.Magnitude();
	if (distancia < radio) {
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			//(radio-distancia)/((2*radio)/3)
			vidaRestada = int(100 * ((radio - distancia) / ((2 * radio) / 3)));

		}
	}


	return float(vidaRestada);

}