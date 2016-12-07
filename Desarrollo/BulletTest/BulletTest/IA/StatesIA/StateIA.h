#pragma once
#include "../../Entities/Entity.h"

class StateIA
{
public:

	virtual void Enter(Entity* e) = 0;
	virtual void Execute(Entity* e) = 0;
	virtual void Exit(Entity* e) = 0;

	StateIA() {};
};

