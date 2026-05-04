#pragma once

#include "../Dependencies.h"
#include "Window/Window.h"

class Game
{
public:

	void run();

private:

	void init();

	void update();
	void render();

	void addKeys();

private:

	std::shared_ptr<Window> m_window = std::make_shared<Window>();

	Camera m_camera = Camera();

};