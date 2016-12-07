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
	virtual void Enter(Entity* pEnemy) {
		std::cout << "ZIZU" << std::endl;
	}
	virtual void Execute(Entity* pEnemy) {
		std::cout << "ZIZU" << std::endl;

	}
	virtual void Exit(Entity* pEnemy) {
		std::cout << "ZIZU" << std::endl;

	}

private:
	Patrullar() {};

};

