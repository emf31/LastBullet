#include "Salto.h"
#include <Death.h>
#include <Run.h>
#include <Character.h>
#include <Idle.h>

void Salto::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("salto");
	pEnemy->getNode()->setFrameTime(milliseconds(27));
}

void Salto::Exit(Character * pEnemy)
{
}

void Salto::Execute(Character * pCharacter)
{
	//Muero y pongo animacion de correr
	if (pCharacter->getLifeComponent()->isDying()) {
		pCharacter->getAnimationMachine()->ChangeState(&Death::i());
	}

	//Compruebo si estoy quieto
	if (!pCharacter->isMoving()) {
		pCharacter->getAnimationMachine()->ChangeState(&Idle::i());
	}

	//Compruebo si salto
	if (pCharacter->isOnGround()) {
		pCharacter->getAnimationMachine()->ChangeState(&Run::i());
	}


}

Salto::~Salto()
{
}
