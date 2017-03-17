#pragma once
#include "EntPassive.h"
#include "../Motor/BasicSceneNode.h"
#include <PhysicsEngine.h>
class Button : public EntPassive {
public:
	Button(std::shared_ptr<BasicSceneNode> nodo, const std::string& name, EnumTriggerType type, int id);
	~Button();


	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct * Trigger) override;
	virtual std::string getClassName() override;
	virtual void setPosition(const Vec3<float> &pos) override;

private:
	EnumTriggerType m_triggerType;

	btGhostObject *m_ghostTrigger;
};

