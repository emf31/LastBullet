#pragma once
#include "Command.h"
class ShootCommand :
	public Command
{
public:
	ShootCommand(Player& jugador);
	~ShootCommand();


	virtual void execute() override;

private:

	Player& player;

};

