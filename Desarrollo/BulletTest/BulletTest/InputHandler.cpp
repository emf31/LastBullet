#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler(Command& space):ButtonSpace(space)
{

}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput(){

	if (MastEventReceiver::i().keyDown(KEY_SPACE)) {
		ButtonSpace.execute();
	}
}
