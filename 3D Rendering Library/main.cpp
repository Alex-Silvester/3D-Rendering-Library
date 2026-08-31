
#include <iostream>

#include "src/Testing/Game3D/Game3D.h"
#include "src/Testing/Game2D/Game2D.h"

int main()
{
	Game* game = new Game2D();

	game->run();

	delete game;

	return 0;
}
