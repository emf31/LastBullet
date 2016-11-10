#pragma once
#include "Command.h"
class ShootCommand : public Command
{
public:
	void execute(Player *character) { character->shoot(); }
	InputType get_input_type() { return STATE; }
};

