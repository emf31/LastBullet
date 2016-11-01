#pragma once
#include "Command.h"
class MoveDown : public Command
{
public:
	void execute(Player *character) { character->move_down(); }
	InputType get_input_type() { return STATE; }
};