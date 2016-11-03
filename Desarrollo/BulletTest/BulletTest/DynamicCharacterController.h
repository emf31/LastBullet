#pragma once

#include "Motor\PhysicsEngine.h"
#include "Otros\vec3.hpp"

#include <vector>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>

class DynamicCharacterController
{
private:
	// Physics
	//SceneObject_PhysicsWorld* m_pPhysicsWorld;
	//Scene* m_pScene;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	btRigidBody* m_pRigidBody;
	btPairCachingGhostObject* m_pGhostObject;

	bool m_onGround;
	//bool m_onJumpableGround; // A bit lower contact than just onGround
	bool m_hittingWall;

	float m_bottomYOffset;
	float m_bottomRoundedRegionYOffset;

	float m_stepHeight;

	btTransform m_motionTransform;

	Vec3<float> m_manualVelocity;
	std::vector<Vec3<float>> m_surfaceHitNormals;

	btVector3 m_previousPosition;

	float m_jumpRechargeTimer;

	void ParseGhostContacts();

	void UpdatePosition();
	void UpdateVelocity(Time elapsedTime);

public:
	float m_deceleration;
	float m_maxSpeed;
	float m_jumpImpulse;

	float m_jumpRechargeTime;

	DynamicCharacterController(const Vec3<float> spawnPos, float radius, float height, float mass, float stepHeight);
	~DynamicCharacterController();

	// Acceleration vector in XZ plane
	void Walk(const float x, const float z);

	// Ignores y
	void Walk(const Vec3<float> dir);

	void Update(Time elapsedTime);

	void Jump();

	Vec3<float> GetPosition();
	Vec3<float> GetVelocity();

	bool IsOnGround() const;
};
