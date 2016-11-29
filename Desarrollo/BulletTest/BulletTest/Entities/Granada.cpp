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
	fuerza = Vec3<float>(120.f, 120.f, 120.f);
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
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(0.15f, 0.15f, 0.15f), "../media/WPNT_MK2Grenade_Base_Color.tga", "../media/WPN_MK2Grenade.obj"));


	//m_renderState.setPosition(Vec3<float>(2, 100, 0));

	m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);

	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Rocket;
	proxy->m_collisionFilterMask = col::rocketCollidesWith;

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

		/*
				list<Entity*>characters = EntityManager::i().getCharacters();
		///Explosion

		for (list<Entity*>::Iterator it = characters.begin(); it != characters.end(); it++) {
			Entity* myentity = *it;
			myentity->restaVida(explosion(m_renderState.getPosition(), myentity->getRenderPosition(), 30.f));

		}

		*/

		//solo se comprueba si te han quitado vida a ti mismo ya que la granada esta en todos los clientes y cada uno comprueba si le han quitado vida a el.
		Entity* myentity = EntityManager::i().getEntity(PLAYER);
		myentity->restaVida(explosion(m_renderState.getPosition(), myentity->getRenderPosition(), 30.f));

//		GraphicEngine::i().removeNode(m_nodo);

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

	if (estado== GRANADACARGADA) {

		Vec3<float> posicion(posicionPlayer.x() + 3, posicionPlayer.y() + 5, posicionPlayer.z());
		/*btTransform transhobbitform = m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(posicion.getX(), posicion.getY(), posicion.getZ()));*/


		//getRenderState()->updatePositions(posicion);

		setPosition(posicion);

		printf("GRANADA DISPARADO\n");
		btVector3 FUERZA(fuerza.getX(), fuerza.getY(), fuerza.getZ());


		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();


		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		/*m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);
		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;*/

		m_rigidBody->applyCentralImpulse(force);
		

		if (Cliente::i().isConected()) {
			TGranada granada;
			granada.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
			granada.origen = posicion;
			granada.direction = direccion;
			Cliente::i().lanzarGranada(granada);
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

void Granada::serverShoot(TGranada g) {

	if (estado == GRANADACARGADA) {

		setPosition(g.origen);

		printf("GRANADA DISPARADA DESDE ENEMIGO\n");
		printf("GRANADA DISPARADA DESDE ENEMIGO\n");
		printf("GRANADA DISPARADA DESDE ENEMIGO\n");
		btVector3 FUERZA(fuerza.getX(), fuerza.getY(), fuerza.getZ());

		btVector3 direccion2(g.direction.getX(), g.direction.getY(), g.direction.getZ());

		btVector3 force = direccion2 * FUERZA;

		m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);
		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;


		m_rigidBody->applyCentralImpulse(force);
		//rocket->m_rigidBody->setCollisionFlags(4);

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
		
		std::cout << "Soy: " << m_name << "Te ha dado la explosion" << std::endl;
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			//(radio-distancia)/((2*radio)/3)
			vidaRestada = 100*((radio - distancia) / ((2 * radio) / 3));

		}
	}
	else {
		std::cout << "Soy: " << m_name << "NO te ha dado la explosion" << std::endl;

	}

	return vidaRestada;

}
