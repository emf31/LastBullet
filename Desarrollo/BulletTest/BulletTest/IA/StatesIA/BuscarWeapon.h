#pragma once
#include "StateIA.h"
class BuscarWeapon : public StateIA
{
public:

	static BuscarWeapon& i() {
		static BuscarWeapon singleton;
		return singleton;
	}
	virtual void Enter(Enemy_Bot* pEnemy);
	virtual void Execute(Enemy_Bot* pEnemy);
	virtual void Exit(Enemy_Bot* pEnemy);

	virtual std::string getStateName() { return "BuscarWeapon"; }

private:
	BuscarWeapon() {};

	bool NeedFindWeapon(Enemy_Bot* pEnemy);
};

