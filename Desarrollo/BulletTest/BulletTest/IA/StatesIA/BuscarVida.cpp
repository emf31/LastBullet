#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>



void BuscarVida::Enter(Enemy_Bot* pEnemy) {
	pEnemy->createPathToItem("LifeObject");

}

void BuscarVida::Execute(Enemy_Bot* pEnemy) {

	pEnemy->updateFacing();

}

void BuscarVida::Exit(Enemy_Bot* pEnemy) {

}