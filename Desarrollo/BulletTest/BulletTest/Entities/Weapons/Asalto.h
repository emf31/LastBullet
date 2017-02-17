#pragma once
#include "Weapon.h"
#include <Character.h>

#define numCargadoresAsalto 5


class Asalto : public Weapon
{
public:
	Asalto(Character* ent);
	~Asalto();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Asalto"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot(const Vec3<float>& target);


	virtual void resetAmmoTotal() { numCargadores = numCargadoresAsalto; }

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;


	Character* m_ent;

};

