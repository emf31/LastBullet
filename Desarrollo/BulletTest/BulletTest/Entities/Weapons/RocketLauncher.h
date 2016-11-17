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

	virtual void shoot();


	virtual void resetAmmoTotal() {
		numCargadores = numCargadoresRocket;
	}
};

