#pragma once

#include "../Dependencies.h"
#include "Window/Window.h"
#include "Debugger/Debugger.h"
#include "Factory/Factory.h"
#include "Skybox/Skybox.h"
#include "Timer/Timer.h"

#include "Model/Model.h"

class Game
{
public:

	void run();

private:

	void windowInit();

	virtual void gameInit() {};
	virtual void update(float dt) {};
	//render before the default rendering loop
	virtual void preRender() {};
	//rener after the default rendering loop
	virtual void postRender() {};

	//renders objects created using default factories
	void defaultRender();

	void addKeys();

protected:

	std::shared_ptr<Window> m_window = std::make_shared<Window>();

	std::shared_ptr<Shader> default_shader = std::make_shared<Shader>();

	Factory<Object> object_factory;

	std::vector<std::unique_ptr<Object>> m_object_list;
	
	Camera m_camera = Camera();
	
	Debugger debug_window = Debugger("test");
};