#pragma once
#include "Command.h"
class ListWeaponDown : public Command
{
public:
	void execute(Player *character) { character->DownWeapon(); }
	InputType get_input_type() { return ACTION; }
};