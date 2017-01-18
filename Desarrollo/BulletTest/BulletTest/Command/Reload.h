#pragma once
#include "Command.h"
class Reload : public Command
{
public:
	void execute(Player *character) { character->reload(); }
	InputType get_input_type() { return ACTION; }
};