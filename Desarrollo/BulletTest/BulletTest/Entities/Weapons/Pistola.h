#pragma once
#include "Weapon.h"
#include <Character.h>

#define numCargadoresPistola 6


class Pistola : public Weapon
{
public:
	Pistola(Character* ent);
	~Pistola();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Pistola"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot(const Vec3<float>& target);

	virtual void resetAmmoTotal() { numCargadores= numCargadoresPistola; }

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

	Character* m_ent;
};

