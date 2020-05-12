#include "StateWorld.h"
#include "StateManager.h"

StateWorld::StateWorld(StateManager* stateManager):
StateBase (stateManager)
{ }

StateWorld::~StateWorld() {}

void StateWorld::create()
{
	m_test.setSize({162.f, 100.f});
	m_test.setOrigin(81.f, 50.f);
	m_test.setPosition(320.f, 240.f);
	m_test.setFillColor(sf::Color::Blue);
	
	m_velocity.x = 360.f;
	m_velocity.y = 240.f;
	
	m_holding = false;
	
	EventManager* evtMgr = m_stateManager->getContext()->m_eventManager;
	evtMgr->addCallback(StateName::World, "MoveTest", &StateWorld::moveTest, this);
	evtMgr->addCallback(StateName::World, "HoldTest", &StateWorld::capture, this);
	evtMgr->addCallback(StateName::World, "ThrowTest", &StateWorld::release, this); 
}

void StateWorld::destroy()
{
	EventManager* evtMgr = m_stateManager->getContext()->m_eventManager;
	evtMgr->removeCallback(StateName::World, "MoveTest");
	evtMgr->removeCallback(StateName::World, "HoldTest");
	evtMgr->removeCallback(StateName::World, "ThrowTest");
}

void StateWorld::activate() {}

void StateWorld::deactivate(){}

void StateWorld::update(sf::Time dt)
{
	sf::FloatRect rect = m_test.getGlobalBounds();
	
	if (rect.top < 0.f || rect.top + rect.height > 640.f)
	{
		m_velocity.y = -m_velocity.y;
	}
	if (rect.left < 0.f || rect.left + rect.width > 860.f)
	{
		m_velocity.x = -m_velocity.x;
	}
	
	m_test.move(m_velocity * dt.asSeconds());
}

void StateWorld::draw()
{
	Window* window = m_stateManager->getContext()->m_window;
	
	window->draw(m_test);
}

void StateWorld::moveTest(EventDetails* details)
{
	sf::Vector2i pos = EventManager::getMousePos(m_stateManager->getContext()->m_window->getRenderWindow());
	m_lastPos = m_pos;
	m_pos = pos;
	
	if (m_holding)
	{
		m_test.setPosition(pos.x, pos.y);
		
		sf::FloatRect rect = m_test.getGlobalBounds();
		
		if (rect.top <= 0.f)
		{
			m_test.move(0.f, -rect.top);
		}
		if (rect.top + rect.height >= 640.f)
		{
			m_test.move(0.f, 640.f - rect.top - rect.height);
		}
		if (rect.left <= 0.f)
		{
			m_test.move(-rect.left, 0.f);
		}
		if (rect.left + rect.width >= 860.f)
		{
			m_test.move(860.f - rect.left - rect.width, 0.f);
		}
	}
}

void StateWorld::capture(EventDetails* details)
{
	sf::Vector2f pos = details->m_position;
	
	sf::FloatRect rect = m_test.getGlobalBounds();
	
	if (pos.x >= rect.left && pos.x <= rect.left + rect.width && pos.y >= rect.top && pos.y <= rect.top + rect.height)
	{
		m_holding = true;
	}
}

void StateWorld::release(EventDetails* details)
{
	if (m_holding)
	{
		m_velocity.x = m_pos.x - m_lastPos.x;
		m_velocity.y = m_pos.y - m_lastPos.y;
		
		m_velocity *= 10.f;
		
		m_holding = false;
	}
}
