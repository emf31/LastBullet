#include "Game.h"
#include "global.h"

bool USING_STEAM;

int main(int argc, char* argv[])
{
	bool steam = true;
	if (argc > 1) {
		if (strcmp(argv[1], "-nosteam") == 0) {
			steam = false;
		} else {
			std::cout << "Wrong arguments. Using Steam..." << std::endl;
		}
	}
	USING_STEAM = steam;
	
	Game *game = new Game();

	game->run();

	delete game;


	return 0;

}
