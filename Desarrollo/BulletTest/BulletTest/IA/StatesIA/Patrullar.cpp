#include "Patrullar.h"
#include "Enemy_Bot.h"
#include <StatesIA/Disparar.h>


void Patrullar::Enter(Enemy_Bot* pEnemy) {
	std::cout << "Entro en Patrullar" << std::endl;
	currTarget = pEnemy->createRandomPath();
	//std::cout << "Zizu" << std::endl;
}

void Patrullar::Execute(Enemy_Bot* pEnemy) {
	//std::cout << "Zizu" << std::endl;
	//std::cout << "Patrullar" << std::endl;
	if (pEnemy->isAtPosition(currTarget)) {
		currTarget = pEnemy->createRandomPath();
	}
	
	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if (!pEnemy->getMachineState()->isInState("BuscarVida")) {
			if (!pEnemy->getTargetBot()->isDying()) {
				pEnemy->getMachineState()->ChangeState(&Disparar::i());
			}
		}

	}

	pEnemy->updateFacing();

}

void Patrullar::Exit(Enemy_Bot* pEnemy) {
	//std::cout << "Zizu" << std::endl;

}