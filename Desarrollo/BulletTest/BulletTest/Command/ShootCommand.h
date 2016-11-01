#pragma once
#include "Command.h"
class ShootCommand : public Command
{
public:
	void execute(Player *character) { character->move_up(); }
	InputType get_input_type() { return ACTION; }
};

