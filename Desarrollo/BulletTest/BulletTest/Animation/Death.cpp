#include "Death.h"
#include <Run.h>
#include <Character.h>
#include <AnimationMachine.h>

void Death::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("muerte");
	pEnemy->getNode()->setFrameTime(milliseconds(24));
	
}

void Death::Exit(Character * pEnemy)
{
	
}

void Death::Execute(Character * pCharacter)
{
	//Muero y pongo animacion de correr
	if (!pCharacter->getLifeComponent()->isDying()) {
		pCharacter->getAnimationMachine()->ChangeState(&Run::i());
	}
}

Death::~Death()
{
}
