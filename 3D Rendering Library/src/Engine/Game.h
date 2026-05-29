#pragma once

#include "../Dependencies.h"
#include "Window/Window.h"
#include "Debugger/Debugger.h"
#include "Factory/Factory.h"

class Game
{
public:

	void run();

private:

	void windowInit();

	virtual void gameInit();
	virtual void update(float dt);
	//render before the default rendering loop
	virtual void preRender();
	//rener after the default rendering loop
	virtual void postRender();

	//renders objects created using default factories
	void defaultRender();

	void addKeys();

private:

	std::shared_ptr<Window> m_window = std::make_shared<Window>();
	
	Camera m_camera = Camera();
	
	Debugger debug_window = Debugger("test");
	
	std::shared_ptr<Shader> default_shader = std::make_shared<Shader>();
	
	Object* test_object = nullptr;
	Object* transparent_object = nullptr;

	std::vector<std::unique_ptr<Object>> m_object_list;

	Factory<Object> object_factory;
};