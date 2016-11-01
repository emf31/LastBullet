#pragma once
#include "Command.h"
class MoveLeft : public Command
{
public:
	void execute(Player *character) { character->move_left(); }
	InputType get_input_type() { return STATE; }
};