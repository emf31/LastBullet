#pragma once
#include "Command.h"
class ShootCommandGranada : public Command
{
public:
	void execute(Player *character) { character->shootGranada(); }
	InputType get_input_type() { return ACTION; }
};

