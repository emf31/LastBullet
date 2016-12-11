
#include "PhysicsEngine.h"
#include "Serialize/BulletWorldImporter\btBulletWorldImporter.h"
#include <unordered_map>
#include <set>
#include "BulletCollision\CollisionDispatch\btCollisionObject.h"

#include "../Handlers/MessageHandler.h"

std::unordered_map<Entity*, std::set<Entity*>> contacts;

const Time PhysicsEngine::tickPhysics = seconds(1.f / 120.f);


//Tenemos un unordered maps de contactos, donde la key es un entity.
//El value es un std::set(igual que un array pero no admite duplicados)
//Este es el metodo al que llama bullet cuando se produce un contacto
bool HandleContacts(btManifoldPoint& point, btCollisionObject* body0, btCollisionObject* body1) {
	
	//Cogemos las 2 entities que colisionan 
	Entity* entity0 = (Entity*)body0->getUserPointer();
	Entity* entity1 = (Entity*)body1->getUserPointer();

	if (body0->getUserPointer() != NULL && body1->getUserPointer() != NULL) {
		//En la key guardamos una entity y en su value un array con las entities con las que colisiona
		//comprobamos si entity 0 esta en el mapa
		auto found = contacts.find(entity0);
		if (found != contacts.end()) {
			//Entity en mapa. Añadimod entity2 al set.
			//Como set no admite duplicados si ya esta dentro no se añade.
			found->second.insert(entity1);
		}
		else {
			//entity1 no esta en el mapa. Creamos nuevo set y añadimos entity1
			std::set<Entity*> set;
			set.insert(entity1);
			//añadimos entity0 al nuevo set
			contacts[entity0] = set;
		}
	}

	
	return true;
}


void PhysicsEngine::inicializar()
{
	m_config = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_config);

	m_broadphase = new btDbvtBroadphase();
	m_solver = new btSequentialImpulseConstraintSolver();
	m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_config);

	m_world->setGravity(btVector3(0, -40, 0));

	m_pGhostPairCallBack = new btGhostPairCallback();

	m_broadphase->getOverlappingPairCache()->setInternalGhostPairCallback(m_pGhostPairCallBack);




	//asi le decidmos a bullet que llame a handle contacts
	gContactProcessedCallback = (ContactProcessedCallback)HandleContacts;


	m_rigidBodies = std::list<btRigidBody*>();


	
}


void PhysicsEngine::update(Time elapsedTime)
{
	//Como la simulacion va lenta multiplicamos por 2
	m_world->stepSimulation(btScalar(elapsedTime.asSeconds()) * 1.25f, 20, tickPhysics.asSeconds());
	

	
}

void PhysicsEngine::notifyCollisions() {
	//Aqui calculariamos colisiones
	for (auto contactsIter = contacts.begin(); contactsIter != contacts.end(); ++contactsIter) {
		//coger la key 
		Entity* collider0 = contactsIter->first;
		//obtenemos el set con las entities que colisiona
		std::set<Entity*>& set = contactsIter->second;
		//iteramos todas las entities en el set
		for (auto entityIter = set.begin(); entityIter != set.end(); ++entityIter) {
			Entity* collider1 = *entityIter;
			//enviamos 2 mensajes uno para la entity que colisiona y otra a la entity con la que colisiona

			Message msg1(collider0, "COLLISION", collider1);
			Message msg2(collider1, "COLLISION", collider0);


			MessageHandler::i().sendMessage(msg1);
			MessageHandler::i().sendMessage(msg2);

		}
	}

	contacts.clear();
}

void PhysicsEngine::createBoxDynamicCharacter(btRigidBody* rigid)
{
	m_world->addRigidBody(rigid);
	//and add to the list of rigidBodies
	m_rigidBodies.push_back(rigid);

}

btRigidBody * PhysicsEngine::createBoxRigidBody(Entity * entity, const Vec3<float>& scale, float masa, bool haveMesh, Vec3<float>centerCol , int body_state)
{
	btTransform transform;
	transform.setIdentity();
	btVector3 pos = Vec3<float>::convertVec(entity->getRenderState()->getPosition()+centerCol);
	//std::cout << "Posicion de la entidad fisica" << pos.x() << "," << pos.y() << "," << pos.z() << '\n';
	transform.setOrigin((pos));

	//create the motionState of the object
	btDefaultMotionState* motionState = new btDefaultMotionState(transform);

	//create the bounding volume
	btCollisionShape* shape;
	if (!haveMesh) {
		btVector3 halfExtents(scale.getX()*0.5f, scale.getY()*0.5f, scale.getZ()*0.5f);
		 shape = new btBoxShape(halfExtents);
	}	
	else {
		btVector3 halfExtents(scale.getX(), scale.getY(), scale.getZ());
		 shape = new btBoxShape(halfExtents);
	}
		

	

	//create intertia info for the shape
	btVector3 localinertia;
	if(masa != 0)	//si no tiene masa no gira
		shape->calculateLocalInertia(masa, localinertia);

	//now create the rigidBody
	btRigidBody* rigidBody = new btRigidBody(masa, motionState, shape, localinertia);
	rigidBody->setActivationState(body_state);



	//add a pointer to rigidBody pointing to associated Entity
	rigidBody->setUserPointer(entity);

	//add the rigidBody to the world
	m_world->addRigidBody(rigidBody);

	//and add to the list of rigidBodies
	m_rigidBodies.push_back(rigidBody);

	//finally return created body
	return rigidBody;
}

btRigidBody * PhysicsEngine::createCapsuleRigidBody(Entity * entity, float height, float radius, float masa, int body_state)
{
	btCollisionShape* m_pCollisionShape = new btCapsuleShape(radius, height);
	//create the motionState of the object
	btDefaultMotionState* m_pMotionState = new btDefaultMotionState(btTransform(btQuaternion(1.0f, 0.0f, 0.0f, 0.0f).normalized(), btVector3(entity->getRenderState()->getPosition().getX(), entity->getRenderState()->getPosition().getY(), entity->getRenderState()->getPosition().getZ())));

	btVector3 intertia;
	m_pCollisionShape->calculateLocalInertia(masa, intertia);

	//now create the rigidBody
	btRigidBody* rigidBody = new btRigidBody(masa, m_pMotionState, m_pCollisionShape, intertia);
	rigidBody->setActivationState(body_state);

	rigidBody->setRestitution(0.7f);

	//add a pointer to rigidBody pointing to associated Entity
	rigidBody->setUserPointer(entity);

	//add the rigidBody to the world
	m_world->addRigidBody(rigidBody);

	//and add to the list of rigidBodies
	m_rigidBodies.push_back(rigidBody);

	//finally return created body
	return rigidBody;
	
}

btRigidBody * PhysicsEngine::createSphereRigidBody(Entity * entity, float radius, float mass, int body_state)
{
	// Create the shape
	btCollisionShape *m_pCollisionShape = new btSphereShape(radius);
	//create the motionState of the object
	btDefaultMotionState* m_pMotionState = new btDefaultMotionState(btTransform(btQuaternion(1.0f, 0.0f, 0.0f, 0.0f).normalized(), btVector3(entity->getRenderState()->getPosition().getX(), entity->getRenderState()->getPosition().getY(), entity->getRenderState()->getPosition().getZ())));

	btVector3 intertia;
	m_pCollisionShape->calculateLocalInertia(mass, intertia);

	//now create the rigidBody
	btRigidBody* rigidBody = new btRigidBody(mass, m_pMotionState, m_pCollisionShape, intertia);
	rigidBody->setActivationState(body_state);
	rigidBody->setRestitution(3500.f);
	//rigidBody->setHitFraction(2000.f);
	//rigidBody->setSpinningFriction(100.f);
	//add a pointer to rigidBody pointing to associated Entity
	rigidBody->setUserPointer(entity);

	//add the rigidBody to the world
	m_world->addRigidBody(rigidBody);

	//and add to the list of rigidBodies
	m_rigidBodies.push_back(rigidBody);
	//finally return created body
	return rigidBody;

}

btGhostObject * PhysicsEngine::createBoxGhostObject(Entity * entity, const Vec3<float>& scale)
{

	btVector3 halfExtents(scale.getX()*0.5f, scale.getY()*0.5f, scale.getZ()*0.5f);
	btCollisionShape* shape = new btBoxShape(halfExtents);

	btTransform transform;
	transform.setIdentity();
	btVector3 pos = Vec3<float>::convertVec(entity->getRenderState()->getPosition());
	transform.setOrigin(pos);

	btGhostObject* ghostObj = new btGhostObject();
	ghostObj->setUserPointer(entity);
	ghostObj->setWorldTransform(transform);

	ghostObj->setCollisionShape(shape);

	ghostObj->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);

	//ghostObj->setWorldTransform(transform);

	

	ghostObj->setUserPointer(entity);

	m_world->addCollisionObject(ghostObj, col::Collisions::Sensor,
		col::sensorCollidesWith);

	return ghostObj;
}

btGhostObject * PhysicsEngine::createSphereShape(Entity* entity, float radio) {
	btCollisionShape *m_pCollisionShape = new btSphereShape(radio);

	btTransform transform;
	transform.setIdentity();
	btVector3 pos = Vec3<float>::convertVec(entity->getRenderState()->getPosition());
	transform.setOrigin(pos);

	btGhostObject* ghostObj = new btGhostObject();
	ghostObj->setUserPointer(entity);
	ghostObj->setWorldTransform(transform);

	ghostObj->setCollisionShape(m_pCollisionShape);


	ghostObj->setCollisionFlags(btGhostObject::CF_NO_CONTACT_RESPONSE);

	m_world->addCollisionObject(ghostObj, btBroadphaseProxy::SensorTrigger,
		btBroadphaseProxy::CharacterFilter);

	return ghostObj;
}

bool PhysicsEngine::removeRigidBody(btRigidBody * body)
{
	m_rigidBodies.remove(body);
	m_world->removeRigidBody(body);

	//Insertamos el cuerpo en el set de borrado
	collisions_set.insert(body);

	return true;
}


bool PhysicsEngine::removeGhostObject(btGhostObject * body)
{

	m_world->removeCollisionObject(body);

	//Insertamos el cuerpo en el set de borrado
	collisions_set.insert(body);

	return true;
}

void PhysicsEngine::cleanDeleteObjects()
{
	for (auto it = collisions_set.begin(); it != collisions_set.end(); ++it)
	{
		delete (*it)->getCollisionShape();
		btRigidBody* body = btRigidBody::upcast(*it);
		if (body != NULL) {
			delete body->getMotionState();
		}
		delete (*it);
	}
	collisions_set.clear();
}


void PhysicsEngine::apagar()
{
	contacts.clear();

	//borramos todos los rigidbodies
	for (auto iter = m_rigidBodies.begin(); iter != m_rigidBodies.end(); ++iter) {
		//los borramos del mundo
		m_world->removeRigidBody(*iter);
		delete (*iter)->getCollisionShape();
		delete (*iter)->getMotionState();
		//borramos la memoria
		delete *iter;
		//iterador a null
		*iter = NULL;
	}
	//ahora vaciamos la lista
	m_rigidBodies.clear();

	//Si ha quedado algun objeto tambien lo borramos(ghost objects o cualquier cosa)
	
	for (int i = m_world->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = m_world->getCollisionObjectArray()[i];
		
		m_world->removeCollisionObject(obj);

		//delete obj->getCollisionShape();
		delete obj;
	}



	//hay que borrar las cosas de las fisicas
	delete m_world;
	m_world = NULL;
	delete m_solver;
	m_solver = NULL;
	delete m_dispatcher;
	m_dispatcher = NULL;
	delete m_broadphase;
	m_broadphase = NULL;
	delete m_config;
	m_config = NULL;
	delete m_pGhostPairCallBack;
	m_pGhostPairCallBack = NULL;

}


