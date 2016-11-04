#pragma once
#pragma once

#include "../Motor\PhysicsEngine.h"
#include "../Otros\vec3.hpp"
#include "../Otros\Vec2f.h"
#include "../Otros\Vec3f.h"

#include <vector>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>

class DynamicCharacterController
{
public:
	DynamicCharacterController(const Vec3<float> spawnPos, float radius, float height, float mass, float stepHeight);
	~DynamicCharacterController();

	float m_deceleration;
	float m_maxSpeed;
	float m_jumpImpulse;
	int numJumps = 0;

	btRigidBody* m_pRigidBody;

	
	// Acceleration vector in XZ plane
	void Walk(const Vec2f dir);

	// Ignores y
	void Walk(const Vec3f dir);

	void Update(Time elapsedTime);

	void Jump();

	Vec3<float> GetPosition();
	Vec3<float> GetVelocity();

	bool IsOnGround() const;
private:
	// Physics
	//SceneObject_PhysicsWorld* m_pPhysicsWorld;
	//Scene* m_pScene;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	
	btPairCachingGhostObject* m_pGhostObject;

	bool m_onGround;
	//bool m_onJumpableGround; // A bit lower contact than just onGround
	bool m_hittingWall;

	float m_bottomYOffset;
	float m_bottomRoundedRegionYOffset;

	float m_stepHeight;

	btTransform m_motionTransform;

	Vec3f  m_manualVelocity;
	std::vector<Vec3f> m_surfaceHitNormals;

	btVector3 m_previousPosition;

	void ParseGhostContacts();

	void UpdatePosition();
	void UpdateVelocity(Time elapsedTime);
};