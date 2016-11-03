#pragma once
#include <list>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

#include "../Entities/Entity.h"
#include "../Otros/Time.hpp"

class PhysicsEngine
{
public:

	static PhysicsEngine& i() {
		static PhysicsEngine singleton;
		return singleton;
	}

	btDynamicsWorld* m_world;

	//Inicializa el motor de fisicas
	void inicializar();

	//Updatea las fisicas
	void update(Time elapsedTime);

	void createBoxDynamicCharacter(btRigidBody* rigid);

	//creamos y registramos un rigidbody cuadrado - asumimos que la posicion esta puesta
	btRigidBody* createBoxRigidBody(Entity* entity, const Vec3<float> &scale, float masa, int body_state = ACTIVE_TAG);

	//creamos y registramos una esfera - asumimos que la posicion esta puesta
	btRigidBody* createSphereRigidBody(Entity* entity, float radius, float mass);

	//borra un rigidbody de la simulacion
	bool removeRigidBody(btRigidBody* body);

	//aqui se borran todos los punteros
	void apagar();


private:
	btDefaultCollisionConfiguration* m_config;
	btCollisionDispatcher* m_dispatcher;
	btBroadphaseInterface* m_broadphase;
	btSequentialImpulseConstraintSolver* m_solver;
	btGhostPairCallback* m_pGhostPairCallBack;

	std::list<btRigidBody*> m_rigidBodies;

	//Constructor privado para que no se pueda llamar
	PhysicsEngine() { }
};

