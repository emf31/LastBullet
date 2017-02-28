#pragma once
#include "StateIA.h"
#include <Vec2f.h>

class Patrullar :
	public StateIA
{
public:

	static Patrullar& i() {
		static Patrullar singleton;
		return singleton;
	}
	virtual void Enter(Enemy_Bot* pEnemy);
	virtual void Execute(Enemy_Bot* pEnemy);
	virtual void Exit(Enemy_Bot* pEnemy);

	virtual std::string getStateName() { return "Patrullar"; }

private:
	Patrullar() {};

	Vec2f currTarget;
};

