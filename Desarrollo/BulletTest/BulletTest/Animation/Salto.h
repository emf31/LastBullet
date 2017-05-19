#pragma once

#include "AnimationCharacter.h"


class Salto :
	public AnimationCharacter
{
public:

	static Salto& i() {
		static Salto singleton;
		return singleton;
	}	


	virtual void Enter(Character* pEnemy);
	virtual void Exit(Character* pEnemy);
	virtual void Execute(Character* pCharacter);

	virtual std::string getAnimationName() { return "Salto"; }


	~Salto();
};

