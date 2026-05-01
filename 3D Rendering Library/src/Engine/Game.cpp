#include "Game.h"

void Game::run()
{
	while (m_window.isOpen())
	{
		m_window.pollEvents();

		m_window.processInputs();

		update();

		m_window.clear();

		render();

		m_window.display();
	}
}

void Game::update()
{

}

void Game::render()
{

}