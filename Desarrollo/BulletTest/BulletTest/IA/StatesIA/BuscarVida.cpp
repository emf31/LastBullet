#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>


void BuscarVida::Enter(Enemy_Bot* pEnemy) {

}

void BuscarVida::Execute(Enemy_Bot* pEnemy) {

	std::cout << "BUSCANDO VIDA" << std::endl;
	pEnemy->createPathToItem("LifeObject");

}

void BuscarVida::Exit(Enemy_Bot* pEnemy) {

}
