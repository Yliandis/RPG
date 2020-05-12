#include "Window.h"

Window::Window()
{
	setup("Default window", {640u, 480u});
}

Window::Window(const std::string& name, sf::Vector2u size)
{
	setup(name, size);
}

Window::~Window()
{
	m_eventManager.removeCallback(static_cast<StateName>(0), "WindowClose");
}

/*******************
 * Running methods *
 *******************/

void Window::processEvents()
{
	sf::Event event;
	
	while (m_window.pollEvent(event))
	{
		m_eventManager.handleEvent(event);
	}
}

void Window::update()
{
	m_eventManager.update();
}

void Window::beginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::draw(const sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void Window::endDraw()
{
	m_window.display();
}

/***********
 * Getters *
 ***********/

bool Window::isOpen() const
{
	return m_window.isOpen();
}

sf::Vector2u Window::getSize() const
{
	return m_window.getSize();
}

sf::RenderWindow* Window::getRenderWindow()
{
	return &m_window;
}

EventManager* Window::getEventManager()
{
	return &m_eventManager;
}

/*******************
 * Private methods *
 *******************/

void Window::setup(const std::string& name, sf::Vector2u size)
{
	m_window.create(sf::VideoMode (size.x, size.y), name, sf::Style::Close);
	m_window.setKeyRepeatEnabled(false);
	
	m_eventManager.loadFromFile("Assets/keys.cfg");
	m_eventManager.addCallback(static_cast<StateName>(0), "WindowClose", &Window::close, this);
}

void Window::close(EventDetails*)
{
	m_window.close();
}
