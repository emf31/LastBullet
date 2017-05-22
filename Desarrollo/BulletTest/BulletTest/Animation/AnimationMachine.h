#pragma once


#include "AnimationCharacter.h"
#include <Weapons/Weapon.h>

class Character;

class AnimationMachine
{
public:

	AnimationMachine(Character* owner) :m_pOwner(owner), currWeapon(Type::eWeapon::Asalto){}
	~AnimationMachine() { }

	void Update() const;

	void SetCurrentAnimation(AnimationCharacter* s);

	void ChangeState(AnimationCharacter* pNewState);

	Type::eWeapon currWeapon;

private:

	//a pointer to the agent that owns this instance
	Character* m_pOwner;

	AnimationCharacter* m_pCurrentAnimation;

	AnimationCharacter* m_pPreviousAnimation;

	
};

