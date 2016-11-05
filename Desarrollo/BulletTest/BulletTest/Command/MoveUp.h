#pragma once
#include "Command.h"
class MoveUp : public Command
{
public:
	void execute(Player *character) { character->move_up(); }
	InputType get_input_type() { return STATE; }
};