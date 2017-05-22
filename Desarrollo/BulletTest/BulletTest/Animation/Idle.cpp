#include "Idle.h"
#include <Death.h>
#include <Run.h>
#include <Character.h>
#include <Weapons/Weapon.h>
#include <AnimationMachine.h>

void Idle::Enter(Character * pEnemy)
{
	//Seteamos la animacion segun el arma actual
	setCurrentAnimationByWeapon(pEnemy);

	pEnemy->getAnimationMachine()->currWeapon = (Type::eWeapon)pEnemy->getCurrentWeaponType();

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
	
	//Si por alguna razon cambio de arma cambiamos de animacion al vuelo
	if (pCharacter->getCurrentWeaponType() != pCharacter->getAnimationMachine()->currWeapon) {
		setCurrentAnimationByWeapon(pCharacter);
	}

}

void Idle::setCurrentAnimationByWeapon(Character* pEnemy)
{
	if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Asalto) {
		pEnemy->getNode()->setCurrentAnimation("idleAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Rocket) {
		pEnemy->getNode()->setCurrentAnimation("idleRocket");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Pistola) {
		pEnemy->getNode()->setCurrentAnimation("idleAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Sniper) {
		pEnemy->getNode()->setCurrentAnimation("idleAsalto");
	}
}

Idle::~Idle()
{
}
