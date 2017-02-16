#pragma once
#include "Command.h"
#include <InGameHUD.h>

class Apuntar : public Command
{
public:
	void execute(Player *character) { character->apuntar();}
	InputType get_input_type() { return ACTION; }


};

