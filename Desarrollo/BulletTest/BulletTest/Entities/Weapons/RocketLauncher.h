#pragma once
#include "Weapon.h"
#include <Character.h>


class Player;

#define numCargadoresRocket 3


class RocketLauncher : public Weapon
{
public:
	RocketLauncher(Character* ent);
	~RocketLauncher();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "RocketLauncher"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot(const Vec3<float>& target);


	virtual void resetAmmoTotal() { numCargadores = numCargadoresRocket; }

private:
	btVector3 SIZE_OF_WORLD;

	Character* m_ent;
};

