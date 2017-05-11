#pragma once
#include "WeaponDrop.h"
class SniperDrop :
	public WeaponDrop
{
public:
	SniperDrop(std::shared_ptr<SceneNode> nodo, const std::string& name);
	~SniperDrop();

	void setGhostObject(btGhostObject* ghostObject) { m_ghostObject = ghostObject; }
	btGhostObject* getGhostObject() { return m_ghostObject; }

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "SniperDrop"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
private:
	
};

