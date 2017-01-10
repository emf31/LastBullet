#include "Game.h"



int main(int, char const**)
{
	/*AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	*/

	Game *game = new Game();
	//while (1) {
		game->run();
	//}
	delete game;

	return 0;

}