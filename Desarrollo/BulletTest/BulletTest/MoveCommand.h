#pragma once
#include "Command.h"

class MoveCommand :
	public Command
{
public:
	MoveCommand(Player& player);
	~MoveCommand();

	virtual void execute() override;

private:

	Player& player;

};

