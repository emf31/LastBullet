#include "Patrullar.h"
#include "Enemy_Bot.h"
#include <StatesIA/Disparar.h>


void Patrullar::Enter(Enemy_Bot* pEnemy) {
	//std::cout << "Zizu" << std::endl;
}

void Patrullar::Execute(Enemy_Bot* pEnemy) {
	//std::cout << "Zizu" << std::endl;
	//std::cout << "Patrullar" << std::endl;
	if (pEnemy->getTargetSys()->isTargetWithinFOV()) {
		if (!pEnemy->getMachineState()->isInState("BuscarVida"))

		pEnemy->getMachineState()->ChangeState(&Disparar::i());
	}

}

void Patrullar::Exit(Enemy_Bot* pEnemy) {
	//std::cout << "Zizu" << std::endl;

}