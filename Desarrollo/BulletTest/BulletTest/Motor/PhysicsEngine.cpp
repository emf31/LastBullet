#include "stdafx.h"
#include "PhysicsEngine.h"

//Inicializar a NULL los valores static sino peta

btDynamicsWorld* PhysicsEngine::m_world = NULL;
btDefaultCollisionConfiguration* PhysicsEngine::m_config = NULL;
btCollisionDispatcher* PhysicsEngine::m_dispatcher = NULL;
btBroadphaseInterface* PhysicsEngine::m_broadphase = NULL;
btSequentialImpulseConstraintSolver* PhysicsEngine::m_solver = NULL;
std::list<btRigidBody*> PhysicsEngine::m_rigidBodies = std::list<btRigidBody*>();

void PhysicsEngine::inicializar()
{
	m_config = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_config);
	m_broadphase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	m_solver = new btSequentialImpulseConstraintSolver();
	m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_config);
}

void PhysicsEngine::update(Time elapsedTime)
{
	m_world->stepSimulation(elapsedTime.asMilliseconds(), 60);

	//Aqui calculariamos colisiones
}

btRigidBody * PhysicsEngine::createBoxRigidBody(Entity * entity, const Vec3<float>& scale, float masa)
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
	return false;
}

void PhysicsEngine::apagar()
{
}
