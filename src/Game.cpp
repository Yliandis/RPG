#include "Game.h"

Game::Game()
: m_window ("RPG", {640u, 480u})
{ }

void Game::run()
{
	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	m_window.processEvents();
}

void Game::update()
{
	m_window.update();
}

void Game::render()
{
	m_window.beginDraw();
	m_window.endDraw();
}
