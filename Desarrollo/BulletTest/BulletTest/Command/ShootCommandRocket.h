#pragma once
#include "Command.h"
class ShootCommandRocket : public Command
{
public:
	void execute(Player *character) { character->shootRocket(); }
	InputType get_input_type() { return ACTION; }
};

