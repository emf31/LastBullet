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
	EntityManager::i().removeEntity(asalto);
	EntityManager::i().removeEntity(pistola);
	EntityManager::i().removeEntity(rocket);
	EntityManager::i().removeEntity(sniper);
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
	//listaWeapons->insertar(rocket);
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

	toPos.setX(AimingPos.getX() + Randf((float)-m_dAimAccuracy, (float)m_dAimAccuracy));
	toPos.setY(AimingPos.getY() + Randf((float)-m_dAimAccuracy, (float)m_dAimAccuracy));
	toPos.setZ(AimingPos.getZ() + Randf((float)-m_dAimAccuracy, (float)m_dAimAccuracy));

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


	/*	if (m_pOwner->getTargetSys()->isTargetShootable() ||
		(m_pOwner->getTargetSys()->GetTimeTargetHasBeenOutOfView() <
			m_dAimPersistance))
	{*/


	if (GetCurrentWeapon()->canShoot()) {

		if (m_pOwner->getTargetSys()->isTargetWithinFOV())
		{

			if (!m_pOwner->getTargetBot()->isDying() && !m_pOwner->isDying()) {

				if (m_pOwner->getTargetSys()->GetTimeTargetHasBeenVisible() > m_dReactionTime) {

					//m_pOwner->lookAt(vec3ToVec2(m_pOwner->getTargetSys()->GetTarget()->getRenderState()->getPosition()));

					Vec3<float> AimingPos = m_pOwner->getTargetBot()->getRenderState()->getPosition();

					float DistToTarget = Vec3<float>::getDistance(m_pOwner->getRenderState()->getPosition(), AimingPos);

					m_pOwner->elegirWeapon(DistToTarget);

					AddNoiseToAim(AimingPos);

				
					GetCurrentWeapon()->shoot(AimingPos);
				
				}

			}
		
		}
	}

}



/*
Vec3<float> WeaponSystem::PredictFuturePositionOfTarget()const {

	double MaxSpeed = 160;//160 es la velocidad que ponemos a nuestros RocketBullets

	//if the target is ahead and facing the agent shoot at its current pos
	float DistToEnemy = Vec3<float>::getDistance(m_pOwner->getTargetBot()->getRenderState()->getPosition(), m_pOwner->getRenderState()->getPosition());
	
	//the lookahead time is proportional to the distance between the enemy
	//and the pursuer; and is inversely proportional to the sum of the
	//agent's velocities
	double LookAheadTime = DistToEnemy /
		(MaxSpeed + 2);//2 es la velocidad del player

	//return the predicted future position of the enemy
	return m_pOwner->getTargetBot()->getRenderState()->getPosition() +
		2 * LookAheadTime;
}
*/

void WeaponSystem::WeaponSystemResetAll() {

	listaWeapons->valorActual()->getNode()->setVisible(false);


	listaWeapons->Vaciar();

	asalto->inicializar();

	rocket->inicializar();

	pistola->inicializar();

	sniper->inicializar();


	listaWeapons->insertar(pistola);
	listaWeapons->valorActual()->getNode()->setVisible(true);

	rocket->setEquipada(false);
	asalto->setEquipada(false);
	sniper->setEquipada(false);

	pistola->setEquipada(true);

}

void WeaponSystem::vaciarArma(std::string arma) {

	if (arma == "Asalto")
		if (buscar("Asalto"))
			asalto->vaciar();


	if (arma == "RocketLauncher")
		if (buscar("RocketLauncher"))
			rocket->vaciar();


	if (arma == "Sniper")
		if (buscar("Sniper"))
			sniper->vaciar();

	if (arma == "Pistola")
		if (buscar("Pistola"))
			pistola->vaciar();

}

void WeaponSystem::InsertarArmaDebug(std::string arma) {


	if (arma == "Asalto") {
		if (!buscar("Asalto")) {
			listaWeapons->insertar(asalto);
		}
		else {
			asalto->resetAmmoTotal();
		}
	}


	if (arma == "RocketLauncher") {
		if (!buscar("RocketLauncher")) {
			listaWeapons->insertar(rocket);
		}
		else {
			rocket->resetAmmoTotal();
		}
	}

	if (arma == "Sniper") {
		if (!buscar("Sniper")) {
			listaWeapons->insertar(sniper);
		}
		else {
			sniper->resetAmmoTotal();
		}
	}

	if (arma == "Pistola") {
		if (!buscar("Pistola")) {
			listaWeapons->insertar(pistola);
		}
		else {
			pistola->resetAmmoTotal();
		}
	}


}