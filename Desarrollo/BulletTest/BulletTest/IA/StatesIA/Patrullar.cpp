#include "Patrullar.h"
#include "Enemy_Bot.h"
#include <StatesIA/Disparar.h>


void Patrullar::Enter(Enemy_Bot* pEnemy) {
	currTarget = pEnemy->createRandomPath();
}

void Patrullar::Execute(Enemy_Bot* pEnemy) {

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

}