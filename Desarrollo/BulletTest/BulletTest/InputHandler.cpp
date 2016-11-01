#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler(Command& space, Command& move):ButtonSpace(space),ButtonMove(move)
{

}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput(){

	if (MastEventReceiver::i().keyPressed(KEY_SPACE)) {
		ButtonSpace.execute();
	}

	if (MastEventReceiver::i().keyDown(KEY_KEY_W)) {
		ButtonMove.execute();
	}
	else if (MastEventReceiver::i().keyDown(KEY_KEY_A)) {
		ButtonMove.execute();
	}
	else if (MastEventReceiver::i().keyDown(KEY_KEY_S)) {
		ButtonMove.execute();
	}
	else if (MastEventReceiver::i().keyDown(KEY_KEY_D)) {
		ButtonMove.execute();
	}
	else {
		ButtonMove.execute();
	}

}
