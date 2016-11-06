#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "../KinematicCharacterController.h"
//#include <BulletDynamics\Character\btKinematicCharacterController.h>
#include "Rocket.h"
#include <vector>
#include "DynamicCharacterController.h"

enum EPhysicsCollisionMask {

	E_Static = 1 << 0,
	E_Riggid = 1 << 1,
	E_Actor = 1 << 2,
	E_Trigger = 1 << 3,

	E_StaticGroup = E_Riggid | E_Actor,
	E_ActorGroup = E_Static | E_Riggid | E_Actor | E_Trigger,
	E_RiggidGroup = E_Static | E_Riggid | E_Actor | E_Trigger,
	E_TriggerGroup = E_Riggid | E_Actor
};

class Player : public Entity
{
public:
	Player();
	~Player();

	void jump();

	void shoot();
	void shootRocket();


	void move_up();
	void move_down();
	void move_right();
	void move_left();



private:
	//Se usa el body del character controller
	//btRigidBody* m_rigidBody;

	Rocket* rocket;
	Clock clockRecargaRocket;
	float timeRecargaRocket = 3;


	bool isJumping;
	bool isMoving;

	
	float giro;

	Vec3<float> vectorPrev;
	Vec3<float> vectorNew;

	Vec3<float> speedFinal;


	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;

	//Player controller
	KinematicCharacterController* p_controller;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	btPairCachingGhostObject* m_pGhostObject;

	float radius;
	float height;
	float mass;

	float m_acceleration_walk;
	float m_acceleration_run;
	float m_deceleration_walk;
	float m_deceleration_run;
	float m_maxSpeed_walk;
	float m_maxSpeed_run;
};

