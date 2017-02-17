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

	pistola = new Pistola(m_pOwner);
	pistola->inicializar();
	pistola->cargarContenido();

	asalto = new Asalto(m_pOwner);
	asalto->inicializar();
	asalto->cargarContenido();

	sniper = new Sniper(m_pOwner);
	sniper->inicializar();
	sniper->cargarContenido();

	rocket = new RocketLauncher(m_pOwner);
	rocket->inicializar();
	rocket->cargarContenido();

	listaWeapons = new Lista();
	listaWeapons->insertar(pistola);
	//listaWeapons->insertar(asalto);
	//listaWeapons->insertar(sniper);
	pistola->setEquipada(true);

}


void WeaponSystem::Equipar(std::string weapon) {
	GetCurrentWeapon()->setEquipada(false);
	listaWeapons->Equipar(weapon);
	GetCurrentWeapon()->setEquipada(true);

}

void WeaponSystem::AddNoiseToAim(Vec3<float>& AimingPos)const {



	Vec3<float> toPos;

	toPos.setX(AimingPos.getX() + Randf(-m_dAimAccuracy, m_dAimAccuracy));
	toPos.setY(AimingPos.getY() + Randf(-m_dAimAccuracy, m_dAimAccuracy));
	toPos.setZ(AimingPos.getZ() + Randf(-m_dAimAccuracy, m_dAimAccuracy));

	AimingPos = toPos;



}

void WeaponSystem::setWeapon(int newWeapon){

	switch (newWeapon) {
	case LANZACOHETES:
		if (!buscar("RocketLauncher")) {
			listaWeapons->insertar(rocket);
		}
		else {
			rocket->resetAmmoTotal();
		}
		break;
	case ASALTO:
		if (!buscar("Asalto")) {
			listaWeapons->insertar(asalto);
		}
		else {
			asalto->resetAmmoTotal();
		}
		break;
	case PISTOLA:
		if (!buscar("Pistola")) {
			listaWeapons->insertar(pistola);
		}
		else {
			pistola->resetAmmoTotal();
		}
		break;
	case SNIPER:
		if (!buscar("Sniper")) {
			listaWeapons->insertar(sniper);
		}
		else {
			sniper->resetAmmoTotal();
		}
		break;
	}

}

void WeaponSystem::TakeAimAndShoot()const
{
	//aim the weapon only if the current target is shootable or if it has only
	//very recently gone out of view (this latter condition is to ensure the 
	//weapon is aimed at the target even if it temporarily dodges behind a wall
	//or other cover)

	//IF ORIGINAL
	/*	if (m_pOwner->getTargetSys()->isTargetShootable() ||
		(m_pOwner->getTargetSys()->GetTimeTargetHasBeenOutOfView() <
			m_dAimPersistance))
	{*/

	

	if (m_pOwner->getTargetSys()->isTargetWithinFOV())
	{

		m_pOwner->lookAt(vec3ToVec2(m_pOwner->getTargetSys()->GetTarget()->getRenderState()->getPosition()));


		//the position the weapon will be aimed at
		Vec3<float> AimingPos = m_pOwner->getTargetBot()->getRenderState()->getPosition();

		float DistToTarget=Vec3<float>::getDistance(m_pOwner->getRenderState()->getPosition(), AimingPos);

		m_pOwner->elegirWeapon(DistToTarget);


		//if the current weapon is not an instant hit type gun the target position
		//must be adjusted to take into account the predicted movement of the 
		//target

		if (GetCurrentWeapon()->getClassName() == "RocketLauncher")
		{
		//	AimingPos = PredictFuturePositionOfTarget();

			//if the weapon is aimed correctly, there is line of sight between the
			//bot and the aiming position and it has been in view for a period longer
			//than the bot's reaction time, shoot the weapon

			//IF ORIGINAL
			/*if (m_pOwner->RotateFacingTowardPosition(AimingPos) &&
				(m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >
					m_dReactionTime) &&
				m_pOwner->hasLOSto(AimingPos))
			{*/

			//if (m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >m_dReactionTime)
		//	{
			
			
			AddNoiseToAim(AimingPos);

				GetCurrentWeapon()->shoot(AimingPos);
		//	}
		}

		//no need to predict movement, aim directly at target
		else
		{
			//if the weapon is aimed correctly and it has been in view for a period
			//longer than the bot's reaction time, shoot the weapon


			//IF ORIGINAL
			/*			if (m_pOwner->RotateFacingTowardPosition(AimingPos) &&
				(m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >
					m_dReactionTime))
			{*/


			if (m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >m_dReactionTime)
			{
				
				AddNoiseToAim(AimingPos);
				GetCurrentWeapon()->shoot(AimingPos);

			}
		}

	}

	//no target to shoot at so rotate facing to be parallel with the bot's
	//heading direction
	else
	{
		//m_pOwner->RotateFacingTowardPosition(m_pOwner->getRenderPosition() + m_pOwner->Heading());
	}
}
