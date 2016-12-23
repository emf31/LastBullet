#pragma once
#include "WeaponDrop.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision\CollisionDispatch\btGhostObject.h"

class RocketLauncherDrop :
	public WeaponDrop
{
public:

	RocketLauncherDrop(std::shared_ptr<SceneNode> nodo, const std::string& name);
	~RocketLauncherDrop();


	void setGhostObject(btGhostObject* ghostObject) { m_ghostObject = ghostObject; }
	btGhostObject* getGhostObject() { return m_ghostObject; }


	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "RocketLauncherDrop"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;


};

