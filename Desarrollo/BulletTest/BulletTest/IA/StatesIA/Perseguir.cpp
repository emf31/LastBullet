#include "Perseguir.h"
#include "Enemy_Bot.h"
#include <StatesIa/Patrullar.h>
#include <StatesIa/Disparar.h>

void Perseguir::Enter(Enemy_Bot* pEnemy) {

}

void Perseguir::Execute(Enemy_Bot* pEnemy) {

	std::cout << "Perseguir" << std::endl;

	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {
		if (!pEnemy->getMachineState()->isInState("BuscarVida"))

			pEnemy->getMachineState()->SetCurrentState(&Disparar::i());
	}

	try {
		Vec3<float> vec3 = pEnemy->getTargetSys()->GetLastRecordedPosition();
		Vec2f vec;
		vec.x = vec3.getX();
		vec.y = vec3.getZ();

		pEnemy->createPathToPosition(vec);
	}
	catch (std::runtime_error e) {
		pEnemy->getMachineState()->SetCurrentState(&Patrullar::i());
	}


}

void Perseguir::Exit(Enemy_Bot* pEnemy) {

}
