#include "stdafx.h"
#include "ShootCommand.h"



ShootCommand::ShootCommand(Player& jugador) :player(jugador)
{
}


ShootCommand::~ShootCommand()
{
}

void ShootCommand::execute() {
	player.shoot();
}