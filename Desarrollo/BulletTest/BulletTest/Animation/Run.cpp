#include "Run.h"
#include <Death.h>
#include <Character.h>
#include <Salto.h>
#include <Idle.h>
#include <SoundManager.h>
#include <Settings.h>

void Run::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("correr");
	pEnemy->getNode()->setFrameTime(milliseconds(28));

	if (pEnemy->footsteps == nullptr) {
		pEnemy->footsteps = SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("footsteps.wav", "sounds"), pEnemy->getRenderState()->getPosition(), true);
	}
	
	pEnemy->footsteps->setIsPaused(false);
}

void Run::Exit(Character * pEnemy)
{

	if (pEnemy->footsteps != nullptr) {
		pEnemy->footsteps->setIsPaused(true);
	}
	
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

	//Compruebo si salto
	if (!pCharacter->isMoving()) {
		pCharacter->getAnimationMachine()->ChangeState(&Idle::i());
	}

}

Run::~Run()
{
}
