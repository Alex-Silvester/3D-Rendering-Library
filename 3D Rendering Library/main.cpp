
#include <iostream>

#include "src/Testing/Game3D.h"

int main()
{
	Game* game = new Game3D();

	game->run();

	delete game;

	return 0;
}
