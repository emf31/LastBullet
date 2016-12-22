#pragma once
#include "Entity.h"
#include "../Motor/BasicSceneNode.h"
class Button : public Entity {
public:
	Button(std::shared_ptr<BasicSceneNode> nodo, const std::string& name);
	~Button();

	void setPosition(Vec3<float> &pos);

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct * Trigger) override;
	virtual std::string getClassName() override;
};

