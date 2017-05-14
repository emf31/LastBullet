#pragma once

#include "Character.h"
#include "AnimationCharacter.h"

class AnimationMachine
{
public:

	AnimationMachine(Character* owner) :m_pOwner(owner) {}
	~AnimationMachine();

private:

	//a pointer to the agent that owns this instance
	Character* m_pOwner;

	AnimationCharacter* m_pCurrentAnimation;

	AnimationCharacter* m_pPreviousAnimation;


};

