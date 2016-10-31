#pragma once
#include "irrlicht.h"
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

using namespace irr;
using namespace scene;

class PhysicsEntity : public Entity
{
public:
	PhysicsEntity(SceneNode* nodo, const std::string& name);
	~PhysicsEntity();

	void setRigidBody(btRigidBody* rigidBody) { m_rigidBody = rigidBody; }
	btRigidBody* getRigidBody() { return m_rigidBody; }

	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message & message) override;

private:
	btRigidBody* m_rigidBody;

};

