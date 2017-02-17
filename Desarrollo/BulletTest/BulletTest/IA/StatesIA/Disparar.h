#pragma once
#include "StateIA.h"
class Disparar :
	public StateIA
{
public:

	static Disparar& i() {
		static Disparar singleton;
		return singleton;
	}
	virtual void Enter(Enemy_Bot* pEnemy);
	virtual void Execute(Enemy_Bot* pEnemy);
	virtual void Exit(Enemy_Bot* pEnemy);

	virtual std::string getStateName() { return "Disparar"; }

private:
	Disparar() {};
	

};

