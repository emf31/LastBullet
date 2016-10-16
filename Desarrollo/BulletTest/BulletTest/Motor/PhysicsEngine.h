#pragma once
#include <list>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "../Entities/Entity.h"
#include "../Otros/Time.hpp"

class PhysicsEngine
{
public:

	//Inicializa el motor de fisicas
	static void inicializar();

	//Updatea las fisicas
	static void update(Time elapsedTime);

	//creamos y registramos un rigidbody cuadrado - asumimos que la posicion esta puesta
	static btRigidBody* createBoxRigidBody(Entity* entity, const Vec3<float> &scale, float masa);

	//creamos y registramos una esfera - asumimos que la posicion esta puesta
	static btRigidBody* createSphereRigidBody(Entity* entity, float radius, float mass);

	//borra un rigidbody de la simulacion
	static bool removeRigidBody(btRigidBody* body);

	//aqui se borran todos los punteros
	static void apagar();

private:
	static btDynamicsWorld* m_world;
	static btDefaultCollisionConfiguration* m_config;
	static btCollisionDispatcher* m_dispatcher;
	static btBroadphaseInterface* m_broadphase;
	static btSequentialImpulseConstraintSolver* m_solver;
	static std::list<btRigidBody*> m_rigidBodies;

	//Constructor privado para que no se pueda llamar
	PhysicsEngine() { }
};

