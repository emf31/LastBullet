#pragma once
#include "Command.h"
class ShootSniper : public Command
{
public:
	void execute(Player *character) { character->shoot(); }
	InputType get_input_type() { return ACTION; }
};

