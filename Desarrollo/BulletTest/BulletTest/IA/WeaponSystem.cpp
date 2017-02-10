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

void WeaponSystem::AddNoiseToAim(Vec3<float>& AimingPos)const {


	//Chino enamorao

	/*Vec3<float> toPos = AimingPos - m_pOwner->getRenderPosition();

	Vec2DRotateAroundOrigin(toPos, Randf(-m_dAimAccuracy, m_dAimAccuracy));

	AimingPos = toPos + m_pOwner->getRenderPosition();
	*/


	//Myself

	Vec3<float> toPos;

	toPos.setX(AimingPos.getX() + Randf(-m_dAimAccuracy, m_dAimAccuracy));
	toPos.setY(AimingPos.getY() + Randf(-m_dAimAccuracy, m_dAimAccuracy));
	toPos.setZ(AimingPos.getZ() + Randf(-m_dAimAccuracy, m_dAimAccuracy));



	AimingPos = toPos;

}

