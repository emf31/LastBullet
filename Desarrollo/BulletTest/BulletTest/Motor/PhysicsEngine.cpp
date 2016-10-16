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
	return nullptr;
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
