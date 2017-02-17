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

		pEnemy->createPathToPosition(vec);
	}
	catch (std::runtime_error e) {
		pEnemy->getMachineState()->ChangeState(&Patrullar::i());
	}

}

void Perseguir::Execute(Enemy_Bot* pEnemy) {

	//std::cout << "Perseguir" << std::endl;

	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {
		if (!pEnemy->getMachineState()->isInState("BuscarVida"))

			pEnemy->getMachineState()->ChangeState(&Disparar::i());
	}


}

void Perseguir::Exit(Enemy_Bot* pEnemy) {

}
