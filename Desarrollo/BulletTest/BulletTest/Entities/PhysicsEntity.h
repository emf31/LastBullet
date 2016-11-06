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

	void rotate(Vec3<float> rot);

	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	void setPosition(Vec3<float> pos) {

		m_renderState.setPosition(pos);
		btTransform transform = m_rigidBody->getCenterOfMassTransform();
		transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
		m_rigidBody->setCenterOfMassTransform(transform);
		m_nodo->setPosition(pos);

	}

private:
	btRigidBody* m_rigidBody;

};

