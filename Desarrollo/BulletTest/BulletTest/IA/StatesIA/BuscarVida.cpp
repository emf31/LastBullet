#include <StatesIA\BuscarVida.h>
#include <Enemy_Bot.h>
#include <PathFollow.h>


void BuscarVida::Enter(Enemy_Bot* pEnemy) {

}

void BuscarVida::Execute(Enemy_Bot* pEnemy) {

	std::cout << "BUSCANDO VIDA" << std::endl;
	if (k == 0) {
		pEnemy->createPathToItem("LifeObject");
		k++;
	}

}

void BuscarVida::Exit(Enemy_Bot* pEnemy) {

}