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

void WeaponSystem::AddNoiseToAim(Vec2f& AimingPos)const {

//	Vec2f toPos = AimingPos - m_pOwner->Pos();

//	Vec2DRotateAroundOrigin(toPos, Randf(-m_dAimAccuracy, m_dAimAccuracy));

//	AimingPos = toPos + m_pOwner->Pos();

}

