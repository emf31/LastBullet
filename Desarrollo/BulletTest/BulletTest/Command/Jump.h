#pragma once
#include "Command.h"
class Jump : public Command
{
public:
	void execute(Player *character) { character->jump();}
	InputType get_input_type() { return ACTION; }

};