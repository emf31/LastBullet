#include "Run.h"
#include <Death.h>
#include <Character.h>
#include <Salto.h>
#include <SoundManager.h>
#include <Settings.h>

void Run::Enter(Character * pEnemy)
{
	pEnemy->getNode()->setCurrentAnimation("correr");
	pEnemy->getNode()->setFrameTime(milliseconds(30));

	if (pEnemy->footsteps == nullptr) {
		pEnemy->footsteps = SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("footsteps.wav", "sounds"), pEnemy->getRenderState()->getPosition(),Sound::type::sound, true);
	}
	
	pEnemy->footsteps->setIsPaused(false);
}

void Run::Exit(Character * pEnemy)
{

	if (pEnemy->footsteps != nullptr) {
		pEnemy->getNode()->setFrameTime(milliseconds(20));
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

}

Run::~Run()
{
}
