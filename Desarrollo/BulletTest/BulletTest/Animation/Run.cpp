#include "Run.h"
#include <Death.h>
#include <Character.h>
#include <Salto.h>
#include <Idle.h>
#include <SoundManager.h>
#include <Settings.h>
#include "Run.h"
#include <Weapons/Weapon.h>
#include <AnimationMachine.h>
void Run::Enter(Character * pEnemy)
{
	//Seteamos la animacion segun el arma actual
	setCurrentAnimationByWeapon(pEnemy);

	pEnemy->getAnimationMachine()->currWeapon = (Type::eWeapon)pEnemy->getCurrentWeaponType();

	pEnemy->getNode()->setFrameTime(milliseconds(28));

	if (pEnemy->footsteps == nullptr) {
		pEnemy->footsteps = SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("footsteps.wav", "sounds"), pEnemy->getRenderState()->getPosition(), Sound::type::sound, true);
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
	//Muero y pongo animacion de muerte
	if (pCharacter->getLifeComponent()->isDying()) {
		pCharacter->getAnimationMachine()->ChangeState(&Death::i());
		return;
	}

	//Compruebo si salto
	if (!pCharacter->isOnGround()) {
		pCharacter->getAnimationMachine()->ChangeState(&Salto::i());
		return;
	}

	//Compruebo si me muevo
	if (!pCharacter->isMoving()) {
		pCharacter->getAnimationMachine()->ChangeState(&Idle::i());
		return;
	}

	//Si por alguna razon cambio de arma cambiamos de animacion al vuelo
	if (pCharacter->getCurrentWeaponType() != pCharacter->getAnimationMachine()->currWeapon) {
		//Continuamos la animacion por donde iba
		int currentFrame = pCharacter->getNode()->getCurrentFrame();
		setCurrentAnimationByWeapon(pCharacter);
		pCharacter->getNode()->setCurrentFrame(currentFrame);
	}

}

void Run::setCurrentAnimationByWeapon(Character * pEnemy)
{
	if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Asalto) {
		pEnemy->getNode()->setCurrentAnimation("correrAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Rocket) {
		pEnemy->getNode()->setCurrentAnimation("correrRocket");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Pistola) {
		pEnemy->getNode()->setCurrentAnimation("correrAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Sniper) {
		pEnemy->getNode()->setCurrentAnimation("correrAsalto");
	}
}

Run::~Run()
{
}
