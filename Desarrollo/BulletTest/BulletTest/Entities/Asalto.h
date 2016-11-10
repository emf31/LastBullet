#pragma once
#include "Weapon.h"
class Asalto :
	public Weapon
{
public:
	Asalto(SceneNode* nodo, const std::string& name);
	~Asalto();

	void setGhostObject(btGhostObject* ghostObject) { m_ghostObject = ghostObject; }
	btGhostObject* getGhostObject() { return m_ghostObject; }


	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Asalto"; }
};

