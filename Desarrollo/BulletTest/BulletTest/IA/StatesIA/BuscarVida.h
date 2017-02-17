#pragma once
#include "StateIA.h"
class BuscarVida :
	public StateIA
{
public:

	static BuscarVida& i() {
		static BuscarVida singleton;
		return singleton;
	}
	virtual void Enter(Enemy_Bot* pEnemy);
	virtual void Execute(Enemy_Bot* pEnemy);
	virtual void Exit(Enemy_Bot* pEnemy);

	virtual std::string getStateName() { return "BuscarVida"; }

private:
	BuscarVida() {};
};

