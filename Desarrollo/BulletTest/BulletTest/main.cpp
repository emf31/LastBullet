#include "Game.h"

int main()
{

	

	Game *game = new Game();
	//while (1) {
		game->run();
	//}
	delete game;

	

	std::exit(0);

	return 0;

}