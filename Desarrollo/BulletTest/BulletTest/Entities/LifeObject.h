#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include "Player.h"


class LifeObject : public Entity
{
public:
	LifeObject(std::shared_ptr<SceneNode> nodo, const std::string& name);
	~LifeObject();

	//void setRigidBody(btRigidBody* rigidBody) { m_rigidBody = rigidBody; }
	//btRigidBody* getRigidBody() { return m_rigidBody; }

	void setGhostObject(btGhostObject* ghostObject) { m_ghostObject = ghostObject; }
	btGhostObject* getGhostObject() { return m_ghostObject; }

	void rotate(Vec3<float> rot);

	void asignaTiempo(Clock tiempo);
	void VidaCogida();
	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "LifeObject"; }

	void setPosition(Vec3<float> pos) {

		m_renderState.setPosition(pos);
		//m_currentPosition = m_ghostObject->getWorldTransform().getOrigin();

		btTransform transform = m_ghostObject->getWorldTransform();
		transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
		m_ghostObject->setWorldTransform(transform);

		m_nodo->setPosition(pos);
	}
	Clock clockRecargaLife;
	float timeRecargaLife = 3;

	int estado = DISPONIBLE;
private:
	//btGhostPairCallback* m_ghostPairCallback = NULL;				// Needed once to enable ghost objects inside Bullet
	btGhostObject* m_ghostObject;							// simple aabb ghost object (keeps track of the objects whose aabbs intersect its own collision shape aabb: this is called "broadphase stage collision detection")
	//btPairCachingGhostObject* m_ghostObject;		// full shape ghost object (keeps track of the objects whose collision shape intersect its own collision shape: this is called "narrowphase stage collision detection")
	btVector3 m_currentPosition;
};
