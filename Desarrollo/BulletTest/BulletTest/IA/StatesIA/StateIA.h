#pragma once
#include <string>

class Enemy_Bot;


class StateIA
{
public:

	virtual void Enter(Enemy_Bot* e) = 0;
	virtual void Execute(Enemy_Bot* e) = 0;
	virtual void Exit(Enemy_Bot* e) = 0;
	virtual std::string getStateName() = 0;

	StateIA() {};


};

