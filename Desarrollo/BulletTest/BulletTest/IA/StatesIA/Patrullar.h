#pragma once
#include "StateIA.h"
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

private:
	Patrullar() {};

};

