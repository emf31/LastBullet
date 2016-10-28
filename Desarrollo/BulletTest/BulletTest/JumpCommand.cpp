#include "stdafx.h"
#include "JumpCommand.h"


JumpCommand::JumpCommand(Player& jugador) :player(jugador)
{
}


JumpCommand::~JumpCommand()
{
}

void JumpCommand::execute() {
	player.jump();
}