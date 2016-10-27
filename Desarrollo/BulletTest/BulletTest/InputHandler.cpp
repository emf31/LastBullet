#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler(Command& space):ButtonSpace(space)
{
	ButtonSpace.execute();
}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput(){

	if (MastEventReceiver::i().keyDown(KEY_SPACE)) {
		ButtonSpace.execute();
	}
}