#include "Salto.h"
#include <Death.h>
#include <Run.h>
#include <Character.h>
#include <Idle.h>
#include <Weapons/Weapon.h>
#include <AnimationMachine.h>

void Salto::Enter(Character * pEnemy)
{
	//Seteamos la animacion segun el arma actual
	setCurrentAnimationByWeapon(pEnemy);

	pEnemy->getAnimationMachine()->currWeapon = (Type::eWeapon)pEnemy->getCurrentWeaponType();

	pEnemy->getNode()->setFrameTime(milliseconds(27));
}

void Salto::Exit(Character * pEnemy)
{
}

void Salto::Execute(Character * pCharacter)
{
	//Muero y pongo animacion de muerte
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

	//Si por alguna razon cambio de arma cambiamos de animacion al vuelo
	if (pCharacter->getCurrentWeaponType() != pCharacter->getAnimationMachine()->currWeapon) {
		setCurrentAnimationByWeapon(pCharacter);
	}
}

void Salto::setCurrentAnimationByWeapon(Character * pEnemy)
{
	if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Asalto) {
		pEnemy->getNode()->setCurrentAnimation("saltoAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Rocket) {
		pEnemy->getNode()->setCurrentAnimation("saltoRocket");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Pistola) {
		pEnemy->getNode()->setCurrentAnimation("saltoAsalto");
	}
	else if (pEnemy->getCurrentWeaponType() == Type::eWeapon::Sniper) {
		pEnemy->getNode()->setCurrentAnimation("saltoAsalto");
	}
}

Salto::~Salto()
{
}
