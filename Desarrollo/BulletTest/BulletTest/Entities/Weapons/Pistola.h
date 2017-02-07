#pragma once
#include "Weapon.h"

#define numCargadoresPistola 6

class Pistola :
	public Weapon
{
public:
	Pistola();
	~Pistola();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Pistola"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot();

	virtual double getDesirability(double dist);

	virtual void createRules();

	virtual void resetAmmoTotal() {
		numCargadores= numCargadoresPistola;
	}

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;
};

