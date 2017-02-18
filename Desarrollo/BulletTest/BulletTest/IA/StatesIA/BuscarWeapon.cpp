#include <StatesIA\BuscarWeapon.h>
#include <StatesIA\Disparar.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>
#include <PathPlanner.h>


void BuscarWeapon::Enter(Enemy_Bot* pEnemy) {

	std::list<Vec2f> m_camino;

	std::cout << "Entro en BuscarWeapon" << std::endl;

	float best = 100000;
	float actual;
	std::string bestString = "Ninguno";

	if (!pEnemy->getWeaponSys()->buscar("Asalto")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("AsaltoDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "AsaltoDrop";
			m_camino.clear();
		}
	}


	if (!pEnemy->getWeaponSys()->buscar("Sniper")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("SniperDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "SniperDrop";
			m_camino.clear();
		}
	}

	if (!pEnemy->getWeaponSys()->buscar("RocketLauncher")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("RocketLauncherDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "RocketLauncherDrop";
			m_camino.clear();
		}
	}

	std::cout << "El mejor es: " << bestString << std::endl;
	
	if(bestString!="Ninguno")
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