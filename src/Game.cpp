#include "Game.h"

const sf::Time Game::updateTime = sf::seconds(1.f / 60.f);

Game::Game()
: m_window ("RPG", {860u, 640u})
, m_stateManager(&m_sharedContext)
{
	m_sharedContext.m_window = &m_window;
	m_sharedContext.m_eventManager = m_window.getEventManager();
	
	m_stateManager.switchTo(StateName::World);
}

void Game::run()
{
	sf::Time elapsed = sf::Time::Zero;
	sf::Clock clock;
	
	while (m_window.isOpen())
	{
		processEvents();
		
		elapsed += clock.restart();
		while (elapsed > updateTime)
		{
			elapsed -= updateTime;
			
			processEvents();
			update(updateTime);
		}
		
		render();
		
		lateUpdate();
	}
}

void Game::processEvents()
{
	m_window.processEvents();
}

void Game::update(sf::Time dt)
{
	m_stateManager.update(dt);
	m_window.update();
}

void Game::render()
{
	m_window.beginDraw();
	m_stateManager.draw();
	m_window.endDraw();
}

void Game::lateUpdate()
{
	m_stateManager.lateUpdate();
}
