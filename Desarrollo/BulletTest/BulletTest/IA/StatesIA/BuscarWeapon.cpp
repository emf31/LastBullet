#include <StatesIA\BuscarWeapon.h>
#include <StatesIA\Disparar.h>
#include <StatesIA\Patrullar.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>
#include <PathPlanner.h>


void BuscarWeapon::Enter(Enemy_Bot* pEnemy) {

	std::list<Vec2f> m_camino;

	float best = 100000;
	float actual;
	std::string bestString = "Ninguno";

	if (!pEnemy->getWeaponSys()->buscar("Asalto")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("AsaltoDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "AsaltoDrop";
		}
		m_camino.clear();
	}


	if (!pEnemy->getWeaponSys()->buscar("Sniper")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("SniperDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "SniperDrop";
		}
		m_camino.clear();

	}

	if (!pEnemy->getWeaponSys()->buscar("RocketLauncher")) {
		actual = pEnemy->getPathPlanning()->CreatePathToItem("RocketLauncherDrop", m_camino);
		if (actual < best) {
			best = actual;
			bestString = "RocketLauncherDrop";
		}
		m_camino.clear();

	}
	
	if (bestString != "Ninguno") 
		pEnemy->createPathToItem(bestString);
	else {
		pEnemy->getMachineState()->ChangeState(&Patrullar::i());
	}
	


}

void BuscarWeapon::Execute(Enemy_Bot* pEnemy) {

	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if (!pEnemy->getMachineState()->isInState("BuscarVida")) {
			if (!pEnemy->getTargetBot()->isDying()) {
				pEnemy->getMachineState()->ChangeState(&Disparar::i());
			}
		}

	}

	pEnemy->updateFacing();

}

void BuscarWeapon::Exit(Enemy_Bot* pEnemy) {

}