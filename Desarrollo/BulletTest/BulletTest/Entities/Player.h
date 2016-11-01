#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

#include <vector>

#define Derecha 1
#define Izquierda 2
#define Arriba 3
#define Abajo 4

class Player : public Entity
{
public:
	Player();
	~Player();

	void jump();
	//void move(bool arriba, bool abajo, bool izq, bool der);

	void move_up();
	void move_down();
	void move_right();
	void move_left();

private:
	// Command queue
	
	btRigidBody* m_rigidBody;
	
	bool isMovingBackward;
	bool isMovingForward;
	bool isMovingLeft;
	bool isMovingRight;
	bool isJumping;

	bool isMoving;

	bool jumped=false;

	float m_speedFactor;
	float giro;
	Clock tiempoSalto;

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


};

