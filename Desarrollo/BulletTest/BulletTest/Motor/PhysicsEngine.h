#pragma once
#include <list>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

#include "../Entities/Entity.h"
#include "../Otros/Time.hpp"

#define BIT(x) (1<<(x))
namespace col {
	enum Collisions {
		COL_NOTHING = 0,
		Static = BIT(0),
		Granada = BIT(1),
		Character = BIT(2),
		Rocket = BIT(3),
		Caja = BIT(4),
		Enemy = BIT(5),
		Sensor = BIT(6),
		RocketEnemy = BIT(7)
	};

	const int staticCollidesWith = Collisions::Character | Collisions::Rocket | Collisions::Caja | Collisions::Enemy | Collisions::RocketEnemy;
	const int characterCollidesWith = Collisions::Static | Collisions::Sensor | Collisions::Enemy | Collisions::RocketEnemy;
	const int rocketCollidesWith = Collisions::Static | Collisions::Caja;
	const int rocketenemyCollidesWith = Collisions::Static | Collisions::Character | Collisions::Caja;
	const int sensorCollidesWith = Collisions::Character;
	const int cajaCollidesWith = Collisions::Rocket | Collisions::Static;
	const int enemyCollidesWith = Collisions::Static | Collisions::Character | Collisions::Rocket;
}

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

	void notifyCollisions();

	//creamos y registramos un rigidbody cuadrado - asumimos que la posicion esta puesta
	btRigidBody* createBoxRigidBody(Entity* entity, const Vec3<float> &scale, float masa,bool haveMesh ,int body_state = ACTIVE_TAG);

	btRigidBody* createCapsuleRigidBody(Entity* entity, float height, float radius, float masa, int body_state = ACTIVE_TAG);

	//creamos y registramos una esfera - asumimos que la posicion esta puesta
	btRigidBody * createSphereRigidBody(Entity * entity, float radius, float mass, int body_state = ACTIVE_TAG);

	btGhostObject* createBoxGhostObject(Entity * entity, const Vec3<float>& scale);

	btGhostObject* createSphereShape(Entity* entity, float radio);


	//borra un rigidbody de la simulacion
	bool removeRigidBody(btRigidBody* body);
	bool removeGhostObject(btGhostObject * body);

	//aqui se borran todos los punteros
	void apagar();

private:
	btDefaultCollisionConfiguration* m_config;
	btCollisionDispatcher* m_dispatcher;
	btBroadphaseInterface* m_broadphase;
	btSequentialImpulseConstraintSolver* m_solver;
	btGhostPairCallback* m_pGhostPairCallBack;

	std::list<btRigidBody*> m_rigidBodies;
	std::list<btCollisionShape*> m_collisionShapes;

	static const Time tickPhysics;

	//Constructor privado para que no se pueda llamar
	PhysicsEngine() { }
};

