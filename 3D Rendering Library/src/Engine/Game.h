#pragma once

#include "../Dependencies.h"
#include "Window.h"

class Game
{
public:

	void run();

private:

	void update();
	void render();

private:

	Window m_window = Window();

};