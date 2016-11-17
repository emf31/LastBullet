#pragma once
#include "Command.h"
class ListWeaponUp : public Command
{
public:
	void execute(Player *character) { character->UpWeapon(); }
	InputType get_input_type() { return ACTION; }
};