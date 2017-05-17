#pragma once


#include "AnimationCharacter.h"

class Character;

class AnimationMachine
{
public:

	AnimationMachine(Character* owner) :m_pOwner(owner) {}
	~AnimationMachine() { }

	void Update() const;

	void SetCurrentAnimation(AnimationCharacter* s);

	void ChangeState(AnimationCharacter* pNewState);

private:

	//a pointer to the agent that owns this instance
	Character* m_pOwner;

	AnimationCharacter* m_pCurrentAnimation;

	AnimationCharacter* m_pPreviousAnimation;


};

