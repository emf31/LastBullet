#include "stdafx.h"
#include <iostream>

#include "Game.h"
#include "Otros/Timer.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::run()
{
	Timer timer(true);

	for (int i = 0; i < 1000000000; i++);

	auto elapsed1 = timer.ElapsedMilliseconds();

	std::cout << "Elapsed time: " << std::fixed << elapsed1.count() << "ms\n";

	timer.Reset();

	for (int i = 0; i < 1000000000; i++);

	auto elapsed2 = timer.ElapsedMilliseconds();

	std::cout << "Elapsed time: " << std::fixed << elapsed2.count() << "ms\n";

	if (elapsed1.count() >= elapsed2.count()) {
		std::cout << "mayor";
	}

	std::getchar();
}
