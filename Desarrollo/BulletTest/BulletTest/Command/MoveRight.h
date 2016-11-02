#pragma once
#include "Command.h"
class MoveRight : public Command
{
public:
	void execute(Player *character) { character->move_right(); }
	InputType get_input_type() { return STATE; }
};