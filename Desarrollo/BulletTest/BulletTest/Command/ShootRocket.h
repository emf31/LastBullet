#pragma once
#include "Command.h"
class ShootRocket : public Command
{
public:
	void execute(Player *character) { character->shoot(); }
	InputType get_input_type() { return ACTION; }
};
