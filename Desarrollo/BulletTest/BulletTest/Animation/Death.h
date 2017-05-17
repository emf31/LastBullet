#pragma once

#include "AnimationCharacter.h"

class Death :
	public AnimationCharacter
{
public:

	static Death& i() {
		static Death singleton;
		return singleton;
	}	


	virtual void Enter(Character* pEnemy);
	virtual void Exit(Character* pEnemy);
	virtual void Execute(Character* pCharacter);

	virtual std::string getAnimationName() { return "Death"; }


	~Death();
};

