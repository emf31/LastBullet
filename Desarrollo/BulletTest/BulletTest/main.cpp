#include "Game.h"
#include <Windows.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(int, char const**)
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	

	Game *game = new Game();
	while (1) {
		game->run();
	}
	

	return 0;

}