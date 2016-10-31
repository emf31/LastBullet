#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

class Player : public Entity
{
public:
	Player();
	~Player();

	void jump();

private:
	
	btRigidBody* m_rigidBody;
	
	bool isMovingBackward;
	bool isMovingForward;
	bool isMovingLeft;
	bool isMovingRight;
	bool isJumping;

	bool jumped=false;

	float m_speedFactor;
	float giro;
	float mouseNew;
	float mousePrev;
	Clock tiempoSalto;

	Vec3<float> vectorPrev;
	Vec3<float> vectorNew;


	// Heredado v�a Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;


};

