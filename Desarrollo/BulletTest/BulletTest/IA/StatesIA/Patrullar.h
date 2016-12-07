#pragma once
#include "StateIA.h"
class Patrullar :
	public StateIA
{
public:

	Patrullar* Patrullar::i()
	{
		static Patrullar instance;
		return &instance;
	}

	virtual void Enter(Entity* pEnemy);
	virtual void Execute(Entity* pEnemy);
	virtual void Exit(Entity* pEnemy);

private:
	Patrullar() {};


};

