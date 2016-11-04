#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

#include "../DynamicCharacterController.h"

#include <vector>


class Player : public Entity
{
public:
	Player();
	~Player();

	void jump();

	void shoot();


	void move_up();
	void move_down();
	void move_right();
	void move_left();


private:
	
	btRigidBody* m_rigidBody;
	

	int numJumps;

	bool isJumping;

	bool isMoving;

	bool jumped=false;


	float m_speedFactor;
	float giro;
	Clock tiempoSalto;

	Vec3<float> vectorPrev;
	Vec3<float> vectorNew;

	Vec3<float> speedFinal;


	DynamicCharacterController* p_controller;


	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;

	float m_acceleration_walk;
	float m_acceleration_run;
	float m_deceleration_walk;
	float m_deceleration_run;
	float m_maxSpeed_walk;
	float m_maxSpeed_run;


};

