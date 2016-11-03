
#include "PhysicsEngine.h"

//Inicializar a NULL los valores static sino peta

void PhysicsEngine::inicializar()
{
	m_config = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_config);
	m_broadphase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	m_solver = new btSequentialImpulseConstraintSolver();
	m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_config);
	m_world->setGravity(btVector3(0, -20, 0));

	m_pGhostPairCallBack = new btGhostPairCallback();

	m_world->getPairCache()->setInternalGhostPairCallback(m_pGhostPairCallBack);

	m_rigidBodies = std::list<btRigidBody*>();
}

void PhysicsEngine::update(Time elapsedTime)
{
	m_world->stepSimulation(elapsedTime.asMilliseconds(), 60);

	//Aqui calculariamos colisiones
}

void PhysicsEngine::createBoxDynamicCharacter(btRigidBody* rigid)
{
	m_world->addRigidBody(rigid);
	//and add to the list of rigidBodies
	m_rigidBodies.push_back(rigid);
	
}

btRigidBody * PhysicsEngine::createBoxRigidBody(Entity * entity, const Vec3<float>& scale, float masa, int body_state)
{
	btTransform transform;
	transform.setIdentity();
	btVector3 pos = Vec3<float>::convertVec(entity->getRenderState()->getPosition());
	transform.setOrigin(pos);

	//create the motionState of the object
	btDefaultMotionState* motionState = new btDefaultMotionState(transform);

	//create the bounding volume
	btVector3 halfExtents(scale.getX()*0.5f, scale.getY()*0.5f, scale.getZ()*0.5f);
	btCollisionShape* shape = new btBoxShape(halfExtents);

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

btRigidBody * PhysicsEngine::createSphereRigidBody(Entity * entity, float radius, float mass)
{
	return nullptr;
}

bool PhysicsEngine::removeRigidBody(btRigidBody * body)
{
	m_rigidBodies.remove(body);
	m_world->removeRigidBody(body);

	return true;
}

void PhysicsEngine::apagar()
{
	//borramos todos los rigidbodies
	for (auto iter = m_rigidBodies.begin(); iter != m_rigidBodies.end(); ++iter) {
		//los borramos del mundo
		m_world->removeRigidBody(*iter);
		//borramos la memoria
		delete *iter;
		//iterador a null
		*iter = NULL;
	}
	//ahora vaciamos la lista
	m_rigidBodies.clear();

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
}


