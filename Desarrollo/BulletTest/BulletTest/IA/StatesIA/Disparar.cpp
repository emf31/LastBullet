#include <StatesIA\Disparar.h>
#include <StatesIA\Perseguir.h>
#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>


void Disparar::Enter(Enemy_Bot* pEnemy) {

}

void Disparar::Execute(Enemy_Bot* pEnemy) {


	pEnemy->getPathFollow()->FollowOff();

	if (!pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if (!pEnemy->getMachineState()->isInState("BuscarVida"))
		pEnemy->getMachineState()->ChangeState(&Perseguir::i());

	}
	else {

		if (pEnemy->getTargetSys()->GetTarget()->isDying()) {
			pEnemy->getTargetSys()->ClearTarget();

			pEnemy->getMachineState()->RevertToPreviousState();
		}

	}

}

void Disparar::Exit(Enemy_Bot* pEnemy) {

}
