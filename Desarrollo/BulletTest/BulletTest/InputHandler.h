#pragma once
#include "Command.h"
#include "MastEventReceiver.hpp"

class InputHandler
{
public:
	InputHandler(Command& space);
	~InputHandler();

	void handleInput();

private:

	Command& ButtonSpace;
};

