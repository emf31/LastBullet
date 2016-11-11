#pragma once
#include "Weapon.h"

class Asalto :
	public Weapon
{
public:
	Asalto();
	~Asalto();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Asalto"; }

	virtual void shoot();


};

