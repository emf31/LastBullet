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




	virtual void resetAmmoTotal() {
		numCargadores= numCargadoresPistola;
	}

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;
	/*
	FuzzyModule fm;

	FuzzyVariable& DistToTarget = fm.CreateFLV("DistToTarget");
	FuzzyVariable& Desirability = fm.CreateFLV("Desirability");
	FuzzyVariable& AmmoStatus = fm.CreateFLV("AmmoStatus");

	FzSet Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 500);

	FzSet Undesirable = Desirability.AddLeftShoulderSet("Underisable", 0, 25, 50);
	FzSet Desirable = Desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet VeryDesirable = Desirability.AddRightShoulderSet("Target_Far", 50, 75, 100);

	FzSet Ammo_Low = AmmoStatus.AddLeftShoulderSet("Ammo_Low", 0, 0, 10);
	FzSet Ammo_Okay = AmmoStatus.AddTriangularSet("Ammo_Okay", 0, 10, 30);
	FzSet Ammo_Loads = AmmoStatus.AddRightShoulderSet("Ammo_Loads", 10, 30, 40);*/
};

