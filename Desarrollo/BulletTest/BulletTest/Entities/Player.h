#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

class Player : public Entity
{
public:
	Player();
	~Player();

private:
	
	btRigidBody* m_rigidBody;

	bool isMovingBackward;
	bool isMovingForward;
	bool isMovingLeft;
	bool isMovingRight;
	bool isJumping;

	float m_speedFactor;
	Clock tiempoSalto;

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
};

