#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "KinematicCharacterController.h"
//#include <BulletDynamics\Character\btKinematicCharacterController.h>
#include "Rocket.h"

#include <vector>
//#include "DynamicCharacterController.h"
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

	float calcularDistancia(btVector3& start, btVector3& end);

	void sumarVida() { m_vida++; }

private:
	float m_vida;

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
	virtual std::string getClassName() { return "Player"; }

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

