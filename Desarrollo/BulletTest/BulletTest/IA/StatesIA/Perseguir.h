#pragma once
#include "StateIA.h"
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

private:
	Perseguir() {};

};

