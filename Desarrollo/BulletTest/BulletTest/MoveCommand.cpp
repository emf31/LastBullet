#include "stdafx.h"
#include "MoveCommand.h"
#include "MastEventReceiver.hpp"


MoveCommand::MoveCommand(Player& jugador) :player(jugador)
{
}


MoveCommand::~MoveCommand()
{
}

void MoveCommand::execute() {
	bool arriba, abajo, izq, der;
	arriba = abajo = izq = der = false;

	arriba = MastEventReceiver::i().keyDown(KEY_KEY_W);
	abajo = MastEventReceiver::i().keyDown(KEY_KEY_S);
	izq = MastEventReceiver::i().keyDown(KEY_KEY_A);
	der = MastEventReceiver::i().keyDown(KEY_KEY_D);

	player.move(arriba, abajo, izq, der);
}