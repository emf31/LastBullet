#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>

#include "../Handlers/Message.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;

	void setPosition(Vec3<float> pos);
	//void updateEnemigo(Vec3<float> pos);


	virtual void handleMessage(const Message & message) override;

	virtual std::string getClassName() { return "Enemy"; }

private:
	btRigidBody* m_rigidBody;

	
};

