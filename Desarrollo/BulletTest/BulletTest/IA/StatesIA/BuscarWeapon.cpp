#include <StatesIA\BuscarWeapon.h>
#include <StatesIA\Disparar.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>


void BuscarWeapon::Enter(Enemy_Bot* pEnemy) {
	pEnemy->createPathToItem("AsaltoDrop");

}

void BuscarWeapon::Execute(Enemy_Bot* pEnemy) {

		if (pEnemy->getTargetSys()->isTargetWithinFOV()) {

		if (!pEnemy->getMachineState()->isInState("BuscarVida"))
			pEnemy->getMachineState()->ChangeState(&Disparar::i());
	}

}

void BuscarWeapon::Exit(Enemy_Bot* pEnemy) {

}