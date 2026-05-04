#include "Game.h"

void Game::run()
{
	init();

	while (m_window->isOpen())
	{
		m_window->pollEvents();

		m_window->processInputs();

		debug_window.startFrame();

		update();

		m_window->clear();

		render();

		debug_window.renderFrame();

		m_window->display();
	}
}

void Game::init()
{
	debug_window.init(*m_window);

	addKeys();

	m_window->changeCamera(m_camera);
}

void Game::update()
{
	ImGui::ShowDemoWindow();
}

void Game::render()
{
	
}

//This could be made more efficient with, maybe, preprocessor stuff
void Game::addKeys()
{

		Key<GLFW_KEY_ESCAPE      >::addWindow(m_window);
		Key<GLFW_KEY_W					 >::addWindow(m_window);
		Key<GLFW_KEY_S					 >::addWindow(m_window);
		Key<GLFW_KEY_A					 >::addWindow(m_window);
		Key<GLFW_KEY_D					 >::addWindow(m_window);
		Key<GLFW_KEY_SPACE			 >::addWindow(m_window);
		Key<GLFW_KEY_LEFT_SHIFT	 >::addWindow(m_window);
		Key<GLFW_KEY_LEFT_CONTROL>::addWindow(m_window);
}
