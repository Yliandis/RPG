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
	
	m_stateManager->getContext()->m_eventManager->addCallback(StateName::World, "MoveTest", &StateWorld::moveTest, this);
}

void StateWorld::destroy()
{
	m_stateManager->getContext()->m_eventManager->removeCallback(StateName::World, "MoveTest");
}

void StateWorld::activate() {}

void StateWorld::deactivate(){}

void StateWorld::update(sf::Time dt){}

void StateWorld::draw()
{
	Window* window = m_stateManager->getContext()->m_window;
	
	window->draw(m_test);
}

void StateWorld::moveTest(EventDetails* details)
{
	sf::Vector2i pos = EventManager::getMousePos(m_stateManager->getContext()->m_window->getRenderWindow());
	m_test.setPosition(pos.x, pos.y);
}
