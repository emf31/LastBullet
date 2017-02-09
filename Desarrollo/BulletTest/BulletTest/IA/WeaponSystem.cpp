#include "WeaponSystem.h"

#include "Enemy_Bot.h"


WeaponSystem::WeaponSystem(Enemy_Bot* Owner, double ReactionTime, double AimAccuracy, double AimPersistance) :
	m_pOwner(Owner),
	m_dReactionTime(ReactionTime), 
	m_dAimAccuracy(AimAccuracy), 
	m_dAimPersistance(AimPersistance)
{

}


WeaponSystem::~WeaponSystem()
{
}

void WeaponSystem::Inicializar() {

	pistola = new Pistola();

	listaWeapons = new Lista();
	listaWeapons->insertar(pistola);

}

void WeaponSystem::TakeAimAndShoot()const
{

}

void WeaponSystem::Equipar(std::string weapon) {
	listaWeapons->Equipar(weapon);
}
