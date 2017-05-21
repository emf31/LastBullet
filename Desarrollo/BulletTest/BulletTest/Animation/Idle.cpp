#include "Idle.h"
#include <Death.h>
#include <Run.h>
#include <Character.h>

void Idle::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("idle");
	pEnemy->getNode()->setFrameTime(milliseconds(29));
}

void Idle::Exit(Character * pEnemy)
{
}

void Idle::Execute(Character * pCharacter)
{
	//Muero y pongo animacion de correr
	if (pCharacter->getLifeComponent()->isDying()) {
		pCharacter->getAnimationMachine()->ChangeState(&Death::i());
	}

	//Compruebo si corro
	if (pCharacter->isMoving()) {
		pCharacter->getAnimationMachine()->ChangeState(&Run::i());
	}

}

Idle::~Idle()
{
}
