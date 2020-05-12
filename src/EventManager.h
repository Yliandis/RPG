#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <functional>
#include <memory>
#include <stdexcept>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/System/Vector2.hpp>

enum class EventType
{
	Closed = sf::Event::Closed, // 0
	Resized = sf::Event::Resized, // 1
	LostFocus = sf::Event::LostFocus, // 2
	GainedFocus = sf::Event::GainedFocus, // 3
	// Text = sf::Event::TextEntered, // 4 // TODO handle this event
	KeyDown = sf::Event::KeyPressed, // 5
	KeyUp = sf::Event::KeyReleased, // 6
	MouseDown = sf::Event::MouseButtonPressed, // 9
	MouseUp = sf::Event::MouseButtonReleased, // 10
	MouseEntered = sf::Event::MouseEntered, // 12
	MouseLeft = sf::Event::MouseLeft, // 13
	
	Keyboard = sf::Event::Count + 1, // 24
	Mouse // 25
};

struct Event
{
	Event(EventType type, int code)
	: m_type (type)
	, m_code (code)
	{ }
	
	EventType m_type;
	int m_code;
};

struct EventDetails
{
	EventDetails(const std::string& name)
	: m_name (name)
	, m_position ()
	, m_size ()
	{ }
	
	std::string m_name;
	
	sf::Vector2f m_position;
	sf::Vector2u m_size;
};

using Events = std::vector<Event>;

struct Binding
{
	Binding(const std::string& name)
	: m_details (name)
	, m_count (0)
	{ }
	
	void reset()
	{
		m_count = 0;
	}
	
	Events m_events;
	EventDetails m_details;
	std::size_t m_count;
};

using Bindings = std::unordered_map<std::string, std::unique_ptr<Binding>>;
using CallbackContainer = std::unordered_map<std::string, std::function<void(EventDetails*)>>;
enum class StateName;
using Callbacks = std::unordered_map<StateName, CallbackContainer>;

class EventManager
{
	public:
		
		void loadFromFile(const std::string&);
		
		void switchTo(StateName);
		
		void handleEvent(sf::Event);
		void update();
		
		template <typename T>
		void addCallback(StateName, const std::string&, void(T::*)(EventDetails*), T*);
		void removeCallback(StateName, const std::string&);
		
		static sf::Vector2i getMousePos(sf::Window* = nullptr);
		
	private:
		
		Bindings m_bindings;
		Callbacks m_callbacks;
		
		StateName m_currentState;
};

template <typename T>
void EventManager::addCallback(StateName state, const std::string& bindName, void(T::*function)(EventDetails*), T* instance)
{
	auto it = m_callbacks.emplace(state, CallbackContainer ()).first;
	
	auto callback = std::bind(function, instance, std::placeholders::_1);
	if (!it->second.emplace(bindName, callback).second)
	{
		throw std::logic_error ("Callback already added : " + bindName);
	}
}

#endif // EVENTMANAGER_H
