#pragma once
#include <Entity.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <BulletCollision\CollisionDispatch\btGhostObject.h>
#include <Player.h>



class WeaponDrop : public Entity
{
public:
	WeaponDrop(std::shared_ptr<SceneNode> nodo, const std::string& name);
	virtual ~WeaponDrop();


	void setGhostObject(btGhostObject* ghostObject) { m_ghostObject = ghostObject; }
	btGhostObject* getGhostObject() { return m_ghostObject; }


	virtual void inicializar() = 0;

	virtual void update(Time elapsedTime) = 0;

	virtual void handleInput() = 0;

	virtual void cargarContenido() = 0;

	virtual void borrarContenido() = 0;

	virtual void handleMessage(const Message& message) =0;

	virtual std::string getClassName() { return "WeaponDrop"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;

	void setPosition(Vec3<float> pos) {

		m_renderState.setPosition(pos);
		//m_currentPosition = m_ghostObject->getWorldTransform().getOrigin();

		btTransform transform = m_ghostObject->getWorldTransform();
		transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
		m_ghostObject->setWorldTransform(transform);

		m_nodo->setPosition(pos);
	}
	void asignaTiempo(Clock tiempo);
	void ArmaCogida();

protected:
	Clock clockRespawnWeapon;
	float timeRespawnWeapon =3;
	

	int estado = DISPONIBLE;
	btGhostObject* m_ghostObject;							
	btVector3 m_currentPosition;
};

