#include "Run.h"
#include <Death.h>
#include <Character.h>
#include <Salto.h>

void Run::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("correr");
}

void Run::Exit(Character * pEnemy)
{
}

void Run::Execute(Character * pCharacter)
{
	//Muero y pongo animacion de correr
	if (pCharacter->getLifeComponent()->isDying()) {
		pCharacter->getAnimationMachine()->ChangeState(&Death::i());
	}

	//Compruebo si salto
	if (!pCharacter->isOnGround()) {
		pCharacter->getAnimationMachine()->ChangeState(&Salto::i());
	}

}

Run::~Run()
{
}
