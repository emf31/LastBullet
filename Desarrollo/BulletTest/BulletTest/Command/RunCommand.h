#pragma once
#include "Command.h"
class RunCommand : public Command
{
public:
	void execute(Player *character) { character->run(); }
	InputType get_input_type() { return STATE; }
};