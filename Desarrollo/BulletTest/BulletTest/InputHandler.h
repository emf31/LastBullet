#pragma once
#include "Command.h"
#include "MastEventReceiver.hpp"

#define Derecha 1
#define Izquierda 2
#define Arriba 3
#define Abajo 4



class InputHandler
{
public:
	InputHandler(Command& space, Command& move);
	~InputHandler();

	void handleInput();

private:

	Command& ButtonSpace;
	Command& ButtonMove;
};

