#pragma once
#include <EntActive.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <BulletCollision\CollisionDispatch\btGhostObject.h>
#include <Player.h>
#include <Enemy_Bot.h>
#include <StatesIA\BuscarWeapon.h>



class WeaponDrop : public EntActive
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

	virtual std::string getClassName() = 0;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;

	virtual void setPosition(const Vec3<float> &pos) override;

	void asignaTiempo(Clock tiempo);
	void ArmaCogida();

	bool isAvailable() {
		return m_nodo->isVisible();
	}
protected:
	Clock clockRespawnWeapon;
	float timeRespawnWeapon;
	

	int estado = DISPONIBLE;
	btGhostObject* m_ghostObject;							
	btVector3 m_currentPosition;

	std::shared_ptr<SceneNode> nodo_platform;
};

