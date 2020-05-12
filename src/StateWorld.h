#ifndef STATEWORLD_H
#define STATEWORLD_H

#include "StateBase.h"
#include "EventManager.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

class StateWorld : public StateBase
{
	public:
		
		StateWorld(StateManager* stateManager);
		~StateWorld();
		
		void create();
		void destroy();
		
		void activate();
		void deactivate();
		
		void update(sf::Time);
		void draw();
		
	private:
		
		void moveTest(EventDetails*);
		void capture(EventDetails*);
		void release(EventDetails*);
		
	private:
		
		sf::RectangleShape m_test;
		sf::Vector2f m_velocity;
		sf::Vector2i m_lastPos;
		sf::Vector2i m_pos;
		bool m_holding;
};

#endif // STATEWORLD_H
