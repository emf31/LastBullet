

#include "EntActive.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include <Player.h>
#include <Enemy_Bot.h>


class LifeObject : public EntActive
{
public:
	LifeObject(std::shared_ptr<SceneNode> nodo, const std::string& name);
	~LifeObject();

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
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual std::string getClassName() { return "LifeObject"; }
	virtual void setPosition(const Vec3<float> &pos) override;

	void setCollisionGroup(int group);
	void setCollisionMask(int mask);

	Clock clockRecargaLife;
	float timeRecargaLife = 3;

	int estado = DISPONIBLE;

	bool isAvailable() {
		return m_nodo->isVisible();
	}

private:
	btGhostObject* m_ghostObject;
	
	btVector3 m_currentPosition;

	std::shared_ptr<SceneNode> nodo_platform;
};
