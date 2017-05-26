#include <StatesIA\BuscarWeapon.h>
#include <StatesIA\Disparar.h>
#include <StatesIA\Patrullar.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>
#include <PathPlanner.h>


void BuscarWeapon::Enter(Enemy_Bot* pEnemy) {

	//Si no necesitamos buscar armas
	//cambiamos de estado
	if (!NeedFindWeapon(pEnemy)) {
		pEnemy->getMachineState()->ChangeState(&Patrullar::i());
		return;
	}

	//0 - Asalto
	//1 - Sniper
	//2 - Rocket
	std::size_t numArmas = 3;

	std::string armas[] = { "Asalto", "Sniper", "RocketLauncher" };
	std::string drops[] = { "AsaltoDrop", "SniperDrop", "RocketLauncherDrop"};
	float distancias[] = { 0,0,0 };
	std::list<Vec3<float>> caminos[3];


	float best = std::numeric_limits<float>::max();
	std::size_t indice = 0;

	for (std::size_t i = 0; i < numArmas; i++) {
		//Comprobamos si necesito ese arma
		if (!pEnemy->getWeaponSys()->buscar(armas[i])) {
			distancias[i] = pEnemy->getPathPlanning()->CreatePathToItem(drops[i], caminos[i]);

			//Nos guardamos el mayor valor
			if (distancias[i] < best) {
				best = distancias[i];
				indice = i;
			}
		}
	}


	pEnemy->followPathAlreadyCreated(caminos[indice]);
	


}

bool BuscarWeapon::NeedFindWeapon(Enemy_Bot* pEnemy) {
	bool needIt = false;

	if (!pEnemy->getWeaponSys()->buscar("Asalto")) needIt = true;
	if (!pEnemy->getWeaponSys()->buscar("Sniper")) needIt = true;
	if (!pEnemy->getWeaponSys()->buscar("RocketLauncher")) needIt = true;

	return needIt;
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