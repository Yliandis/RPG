#ifndef STATEWORLD_H
#define STATEWORLD_H

#include "StateBase.h"
#include "EventManager.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>

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
		
	private:
		
		sf::RectangleShape m_test;
};

#endif // STATEWORLD_H
