#pragma once
#include "irrlicht.h"
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

using namespace irr;
using namespace scene;

class Player : public Entity
{
public:
	Player(ISceneManager* escena,IVideoDriver* driver);
	~Player();

private:
	ISceneManager* m_escena;
	IVideoDriver* m_driver;
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

