#pragma once
#include "../Entity.h"

class Weapon :
	public Entity
{
public:
	Weapon();
	~Weapon();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Weapon"; }

	virtual void shoot();
};

