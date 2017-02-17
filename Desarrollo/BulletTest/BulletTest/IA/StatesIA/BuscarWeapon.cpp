#include <StatesIA\BuscarWeapon.h>
#include <StatesIA\Disparar.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>
#include <PathPlanner.h>


void BuscarWeapon::Enter(Enemy_Bot* pEnemy) {

	std::list<Vec2f> m_camino;

	

	float best = pEnemy->getPathPlanning()->CreatePathToItem("AsaltoDrop", m_camino);
	std::string bestString = "AsaltoDrop";

	m_camino.clear();

	/*if(!pEnemy->getWeaponSys()->buscar("RocketLauncher"))
	if (pEnemy->getPathPlanning()->CreatePathToItem("RocketLauncherDrop", m_camino) < best) {
		bestString = "RocketLauncherDrop";
	}*/

	if (!pEnemy->getWeaponSys()->buscar("Sniper"))
	if (pEnemy->getPathPlanning()->CreatePathToItem("SniperDrop", m_camino) < best) {
		bestString = "SniperDrop";
	}
	
	std::cout << "El mejor es: " << bestString << std::endl;

	pEnemy->createPathToItem(bestString);


}

void BuscarWeapon::Execute(Enemy_Bot* pEnemy) {

		if (pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if (!pEnemy->getMachineState()->isInState("BuscarVida"))
			pEnemy->getMachineState()->ChangeState(&Disparar::i());
	}

}

void BuscarWeapon::Exit(Enemy_Bot* pEnemy) {

}