#pragma once
#include "Weapon.h"

#define numCargadoresSniper 3


class Sniper : public Weapon
{
public:
	Sniper();
	~Sniper();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Sniper"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot();

	virtual double getDesirability(double distToTarget);

	virtual void resetAmmoTotal() {
		numCargadores = numCargadoresSniper;
	}

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

};

