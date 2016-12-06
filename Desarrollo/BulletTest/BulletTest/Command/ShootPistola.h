#pragma once
#include "Command.h"
class ShootPistola : public Command
{
public:
	void execute(Player *character) { character->shoot(); }
	InputType get_input_type() { return ACTION; }
};