#pragma once
#include "Command.h"

class JumpCommand :
	public Command
{
public:
	JumpCommand(Player& jugador);
	~JumpCommand();

	virtual void execute() override;

private:

	Player player;

};

