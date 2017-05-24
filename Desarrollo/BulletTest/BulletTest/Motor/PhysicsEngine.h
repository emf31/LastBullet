#pragma once
#include <list>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

#include <Entity.h>
#include <Time.hpp>
#include <KinematicCharacterController.h>

#include <unordered_set>

#define BIT(x) (1<<(x))
namespace col {
	enum Collisions {
		COL_NOTHING = 0,
		RAY_CAST = BIT(0),
		Granada = BIT(1),
		Character = BIT(2),
		Rocket = BIT(3),
		Bot = BIT(4),
		Enemy = BIT(5),
		Sensor = BIT(6),
		RocketEnemy = BIT(7),
		Static = BIT(8),
	};

	const int staticCollidesWith = Collisions::RAY_CAST | Collisions::Character | Collisions::Rocket | Collisions::Bot | Collisions::Enemy | Collisions::RocketEnemy;
	const int characterCollidesWith = Collisions::RAY_CAST | Collisions::Character | Collisions::Static | Collisions::Sensor | Collisions::Enemy | Collisions::RocketEnemy| Collisions::Bot;
	const int rocketCollidesWith = Collisions::Static | Collisions::Bot | Collisions::Enemy;
	const int rocketenemyCollidesWith = Collisions::Static | Collisions::Character | Collisions::Bot;
	const int sensorCollidesWith = Collisions::Character | Collisions::Bot;
	const int BotCollidesWith = Collisions::RAY_CAST | Collisions::Rocket | Collisions::Static/*| Collisions::Character */ | Collisions::Sensor | Collisions::RocketEnemy /*| Collisions::Enemy | Collisions::Bot*/;
	const int enemyCollidesWith = Collisions::RAY_CAST | Collisions::Static | Collisions::Character | Collisions::Rocket | Collisions::Bot | Collisions::Enemy;
}

namespace bodyPart {
	enum Body {
		CUERPO = 0,
		CABEZA = 1,
		EXTERNA = 2
	};
}





class btKinematicClosestShapeResultCallback : public btCollisionWorld::ClosestRayResultCallback
{
public:
	btKinematicClosestShapeResultCallback(const btVector3& start, const btVector3& end) : btCollisionWorld::ClosestRayResultCallback(start, end)
	{
		parte = bodyPart::Body::CUERPO;
	}

	virtual btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult, bool normalInWorldSpace)
	{
		if (rayResult.m_localShapeInfo) {
			m_shapeIndex = rayResult.m_localShapeInfo->m_triangleIndex;
		}

		if (rayResult.m_collisionObject->getCollisionShape()->getShapeType() == COMPOUND_SHAPE_PROXYTYPE) {
			btCompoundShape* compound = (btCompoundShape*)rayResult.m_collisionObject->getCollisionShape();
			parte = static_cast<bodyPart::Body>(compound->getChildShape(m_shapeIndex)->getUserIndex());

			if (parte == bodyPart::Body::EXTERNA) {
				return btScalar(1.0);
			}
		}




		return ClosestRayResultCallback::addSingleResult(rayResult, normalInWorldSpace);
	}
public:
	bodyPart::Body parte;
	int m_shapeIndex;
};

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

	void notifyCollisions();

	//Crea un kinematic character controller
	KinematicCharacterController* createCapsuleKinematicCharacter(Entity* ent, float radius, float height, float mass);

	btRigidBody* createCompoundShape(Entity* entity, const Vec3<float> &scale, float masa, const std::string& mesh, int body_state = ACTIVE_TAG);

	//creamos y registramos un rigidbody cuadrado - asumimos que la posicion esta puesta
	btRigidBody* createBoxRigidBody(Entity* entity, const Vec3<float> &scale, float masa,bool haveMesh , Vec3<float> centerCol = Vec3<float>(0, 0, 0),int body_state = ACTIVE_TAG);

	btRigidBody* createCapsuleRigidBody(Entity* entity, float height, float radius, float masa, int body_state = ACTIVE_TAG);

	//creamos y registramos una esfera - asumimos que la posicion esta puesta
	btRigidBody * createSphereRigidBody(Entity * entity, float radius, float mass, int body_state = ACTIVE_TAG);

	btGhostObject* createBoxGhostObject(Entity * entity, const Vec3<float>& scale);

	btGhostObject* createSphereShape(Entity* entity, float radio);


	//borra un rigidbody de la simulacion
	bool removeRigidBody(btRigidBody* body);
	bool removeGhostObject(btGhostObject * body);
	bool removeKinematic(KinematicCharacterController* kinematic);

	void cleanDeleteObjects();

	//aqui se borran todos los punteros
	void apagar();

private:
	btDefaultCollisionConfiguration* m_config;
	btCollisionDispatcher* m_dispatcher;
	btBroadphaseInterface* m_broadphase;
	btSequentialImpulseConstraintSolver* m_solver;
	btGhostPairCallback* m_pGhostPairCallBack;

	std::list<btRigidBody*> m_rigidBodies;

	std::unordered_set<btCollisionObject*> collisions_set;

	static const Time tickPhysics;

	//Constructor privado para que no se pueda llamar
	PhysicsEngine() { }
};

