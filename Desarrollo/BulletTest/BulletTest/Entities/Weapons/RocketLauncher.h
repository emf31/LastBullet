#pragma once
#include "Weapon.h"

#define numCargadoresRocket 3


class RocketLauncher :
	public Weapon
{
public:
	RocketLauncher();
	~RocketLauncher();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "RocketLauncher"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot();

	virtual double getDesirability(double distToTarget);


	virtual void resetAmmoTotal() {
		numCargadores = numCargadoresRocket;
	}
private:
	btVector3 SIZE_OF_WORLD;
};

