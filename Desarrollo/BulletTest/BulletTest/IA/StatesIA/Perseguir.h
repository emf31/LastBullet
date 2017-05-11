#pragma once
#include "StateIA.h"
#include <Vec2f.h>


class Perseguir :
	public StateIA
{
public:

	static Perseguir& i() {
		static Perseguir singleton;
		return singleton;
	}
	virtual void Enter(Enemy_Bot* pEnemy);
	virtual void Execute(Enemy_Bot* pEnemy);
	virtual void Exit(Enemy_Bot* pEnemy);

	virtual std::string getStateName() { return "Perseguir"; }



private:
	Perseguir() {};

	Vec2f currTarget;
};

