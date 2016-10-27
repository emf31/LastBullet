#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler(Command& space):ButtonSpace(space)
{
	space.execute();
}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput(){

	if (MastEventReceiver::i().keyDown(KEY_SPACE)) {
		ButtonSpace.execute();
		//printf("Entra en el handleInput pero no en el execute\n");

	}
}