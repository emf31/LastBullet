#include "Perseguir.h"
#include "Enemy_Bot.h"
#include <StatesIa/Patrullar.h>
#include <StatesIa/Disparar.h>

void Perseguir::Enter(Enemy_Bot* pEnemy) {

	try {
		Vec3<float> vec3 = pEnemy->getTargetSys()->GetLastRecordedPosition();
		Vec2f vec;
		vec.x = vec3.getX();
		vec.y = vec3.getZ();

		currTarget = pEnemy->createPathToPosition(vec3);
	}
	catch (std::runtime_error e) {
		pEnemy->getMachineState()->ChangeState(&Patrullar::i());
	}

}

void Perseguir::Execute(Enemy_Bot* pEnemy) {	

	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {
		if (!pEnemy->getMachineState()->isInState("BuscarVida")) {
			if (!pEnemy->getTargetBot()->isDying()) {
				pEnemy->getMachineState()->ChangeState(&Disparar::i());
			}
		}

	}
	else {
		if (pEnemy->isAtPosition(currTarget)) {
			pEnemy->getMachineState()->RevertToPreviousState();
		}
	}



	pEnemy->updateFacing();
}

void Perseguir::Exit(Enemy_Bot* pEnemy) {

}
