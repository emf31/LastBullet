#include <StatesIA\Disparar.h>
#include <StatesIA\Perseguir.h>
#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>


void Disparar::Enter(Enemy_Bot* pEnemy) {
	std::cout << "Entro en Disparar" << std::endl;

}

void Disparar::Execute(Enemy_Bot* pEnemy) {


	pEnemy->getPathFollow()->FollowOff();

	//std::cout << "Disparar" << std::endl;



	if (!pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if(!pEnemy->getMachineState()->isInState("BuscarVida"))
		pEnemy->getMachineState()->ChangeState(&Perseguir::i());

	}

}

void Disparar::Exit(Enemy_Bot* pEnemy) {

}
