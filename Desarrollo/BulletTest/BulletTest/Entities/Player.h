#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>


class Player : public Entity
{
public:
	Player(const std::string& name, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	~Player();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;

	void setPosition(Vec3<float> pos);

	btRigidBody* getRigidBody() { return m_rigidBody; }


	void jump();

	void shoot();


	void move_up();
	void move_down();
	void move_right();
	void move_left();

private:
	
	btRigidBody* m_rigidBody;

	bool isMovingBackward;
	bool isMovingForward;
	bool isMovingLeft;
	bool isMovingRight;
	bool isShooting=false;
	bool moviendo = false;

	float m_speedFactor;
	Clock tiempoSalto;


	int numJumps;
	bool isJumping;
	bool isMoving;
	bool jumped = false;

	Vec3<float> vectorPrev;
	Vec3<float> vectorNew;

	Vec3<float> speedFinal;

	float giro;
	
};

