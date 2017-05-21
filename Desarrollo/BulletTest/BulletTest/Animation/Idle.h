#pragma once

#include "AnimationCharacter.h"


class Idle :
	public AnimationCharacter
{
public:

	static Idle& i() {
		static Idle singleton;
		return singleton;
	}	


	virtual void Enter(Character* pEnemy);
	virtual void Exit(Character* pEnemy);
	virtual void Execute(Character* pCharacter);

	virtual std::string getAnimationName() { return "Idle"; }


	~Idle();
};

