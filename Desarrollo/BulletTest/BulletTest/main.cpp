#include "stdafx.h"
#include "Game.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(int, char const**)
{
	Game *game = new Game();
	game->run();

	return 0;

}