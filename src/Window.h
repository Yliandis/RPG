#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SFML/Graphics.hpp>

#include "EventManager.h"

class Window : sf::NonCopyable
{
	public:
		
		Window();
		Window(const std::string&, sf::Vector2u);
		~Window();
		
		void processEvents();
		void update();
		
		void beginDraw();
		void draw(const sf::Drawable&);
		void endDraw();
		
		bool isOpen() const;
		sf::Vector2u getSize() const;
		
		sf::RenderWindow* getRenderWindow();
		EventManager* getEventManager();
		
	private:
		
		void setup(const std::string&, sf::Vector2u);
		
		void close(EventDetails*);
		
	private:
		
		sf::RenderWindow m_window;
		EventManager m_eventManager;
};

#endif // WINDOW_H
