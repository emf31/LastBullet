#pragma once
#include "Command.h"
class Jump : public Command
{
public:
	void execute(Player *character) { character->jump(); character->resetAll(); }
	InputType get_input_type() { return ACTION; }

};