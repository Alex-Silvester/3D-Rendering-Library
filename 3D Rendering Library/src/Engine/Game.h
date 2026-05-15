#pragma once

#include "../Dependencies.h"
#include "Window/Window.h"
#include "Debugger/Debugger.h"

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
	
	Debugger debug_window = Debugger("test");
	
	std::shared_ptr<Shader> default_shader = std::make_shared<Shader>();
	
	Object test_object;


};