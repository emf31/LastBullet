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

	virtual void shoot();

	virtual void resetAmmoTotal() {
		numCargadores= numCargadoresPistola;
	}

};

