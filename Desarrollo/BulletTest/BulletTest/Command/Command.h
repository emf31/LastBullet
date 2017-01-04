#pragma once
#include <Player.h>
#include "../Handlers/input_constants.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Player *character) = 0;
	virtual InputType get_input_type() = 0;
};