#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>



void BuscarVida::Enter(Enemy_Bot* pEnemy) {
	pEnemy->createPathToItem("LifeObject");
	std::cout << "Entro en BuscarVida" << std::endl;

}

void BuscarVida::Execute(Enemy_Bot* pEnemy) {

	//std::cout << "BUSCANDO VIDA" << std::endl;

	pEnemy->updateFacing();

}

void BuscarVida::Exit(Enemy_Bot* pEnemy) {

}