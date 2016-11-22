#pragma once
#include "Command.h"
class Exit : public Command
{
public:
	void execute(Player *character) { character->exit(); }
	InputType get_input_type() { return ACTION; }
};