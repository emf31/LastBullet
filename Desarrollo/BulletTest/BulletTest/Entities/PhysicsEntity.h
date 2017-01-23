#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "../Motor/BasicSceneNode.h"
#include <PhysicsEngine.h>
class PhysicsEntity : public Entity
{
public:
	PhysicsEntity(std::shared_ptr<BasicSceneNode> nodo, const std::string& name);
	~PhysicsEntity();

	void setRigidBody(btRigidBody* rigidBody) { 
		m_rigidBody = rigidBody;
	}
	void setCollisionGroup(int group);
	void setCollisionMask(int mask);

	btRigidBody* getRigidBody() const{ return m_rigidBody; }

	void rotate(Vec3<float> rot);

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual std::string getClassName() { return "PhysicsEntity"; }
	virtual void setPosition(const Vec3<float> &pos) override;


	Vec3<float> centerCollision;
private:
	btRigidBody* m_rigidBody;
	
};

