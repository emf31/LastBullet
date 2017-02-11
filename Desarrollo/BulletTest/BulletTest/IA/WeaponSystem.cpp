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

void WeaponSystem::TakeAimAndShoot()const
{
	//aim the weapon only if the current target is shootable or if it has only
	//very recently gone out of view (this latter condition is to ensure the 
	//weapon is aimed at the target even if it temporarily dodges behind a wall
	//or other cover)
	/*if (m_pOwner->getTargetSys()->isTargetShootable() ||
		(m_pOwner->getTargetSys()->GetTimeTargetHasBeenOutOfView() <
			m_dAimPersistance))
	{
		//the position the weapon will be aimed at
		Vec3<float> AimingPos = m_pOwner->getTargetBot()->getRenderPosition();

		//if the current weapon is not an instant hit type gun the target position
		//must be adjusted to take into account the predicted movement of the 
		//target

		if (GetCurrentWeapon()->getClassName() == "RocketLauncher")
		{
			AimingPos = PredictFuturePositionOfTarget();

			//if the weapon is aimed correctly, there is line of sight between the
			//bot and the aiming position and it has been in view for a period longer
			//than the bot's reaction time, shoot the weapon
			if (m_pOwner->RotateFacingTowardPosition(AimingPos) &&
				(m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >
					m_dReactionTime) &&
				m_pOwner->hasLOSto(AimingPos))
			{
				AddNoiseToAim(AimingPos);

				GetCurrentWeapon()->ShootAt(AimingPos);
			}
		}

		//no need to predict movement, aim directly at target
		else
		{
			//if the weapon is aimed correctly and it has been in view for a period
			//longer than the bot's reaction time, shoot the weapon
			if (m_pOwner->RotateFacingTowardPosition(AimingPos) &&
				(m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() >
					m_dReactionTime))
			{
				AddNoiseToAim(AimingPos);

				GetCurrentWeapon()->ShootAt(AimingPos);
			}
		}

	}

	//no target to shoot at so rotate facing to be parallel with the bot's
	//heading direction
	else
	{
		m_pOwner->RotateFacingTowardPosition(m_pOwner->getRenderPosition() + m_pOwner->Heading());
	}*/
}
