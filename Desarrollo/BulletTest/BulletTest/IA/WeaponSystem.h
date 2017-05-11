#pragma once
#include "Weapons/Asalto.h"
#include "Weapons/Pistola.h"
#include "Weapons/RocketLauncher.h"
#include "Weapons/Sniper.h"
#include "../Otros/Lista.h"
#include <Vec2f.h>




class Enemy_Bot;

class WeaponSystem
{
public:
	WeaponSystem(Enemy_Bot* owner, double ReactionTime, double AimAccuracy, double AimPersistance);
	~WeaponSystem();



	void Inicializar();
	void TakeAimAndShoot()const;
	void Equipar(std::string weapon);

	Weapon* GetCurrentWeapon()const { return listaWeapons->valorActual(); }
	Weapon* GetWeaponFromInventory(std::string weapon);
	double getReactionTime()const { return m_dReactionTime; }

	int getAmmoAsalto() { return asalto->getMunicionTotal(); }
	int getAmmoSniper() { return sniper->getMunicionTotal(); }
	int getAmmoPistola() { return pistola->getMunicionTotal(); }
	int getAmmoRocketLauncher() { return rocket->getMunicionTotal(); }


	void WeaponSystemResetAll();
	void setWeapon(int weapon);

	void vaciarArma(std::string);
	void InsertarArmaDebug(std::string);

	bool buscar(std::string weapon) { return listaWeapons->Buscar(weapon); }


	Vec3<float> PredictFuturePositionOfTarget()const;
	void AddNoiseToAim(Vec3<float>& AimingPos) const;


private:

	Enemy_Bot* m_pOwner;

	Lista* listaWeapons;

	double m_dReactionTime;
	double m_dAimAccuracy;
	double m_dAimPersistance;

	Asalto* asalto;
	Pistola* pistola;
	Sniper* sniper;
	RocketLauncher* rocket;


};

