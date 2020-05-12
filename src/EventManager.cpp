#include "EventManager.h"

void EventManager::loadFromFile(const std::string& filename)
{
	std::ifstream file (filename);
	if (!file.is_open())
	{
		throw std::runtime_error ("Failed to load " + filename);
	}
	
	std::string delimiter = ":";
	
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		std::istringstream lineStream (line);
		
		std::string bindName;
		lineStream >> bindName;
		
		Events bindEvents;
		while (!lineStream.eof())
		{
			std::string event;
			lineStream >> event;
			
			std::size_t delimPos = event.find(delimiter);
			EventType type;
			int code;
			try
			{
				type = static_cast<EventType>(std::stoi(event.substr(0, delimPos)));
				code = std::stoi(event.substr(delimPos + delimiter.size()));
			}
			catch (std::exception& err)
			{
				throw std::runtime_error ("Corrupted file : " + filename);
			}
			
			bindEvents.emplace_back(type, code);
		}
		
		std::unique_ptr<Binding> binding (new Binding (bindName));
		binding->m_events = bindEvents;
		m_bindings.emplace(bindName, std::move(binding));
	}
	
	file.close();
}

void EventManager::switchTo(StateName state)
{
	m_currentState = state;
}

void EventManager::handleEvent(sf::Event sfmlEvent)
{
	for (const auto& binding : m_bindings)
	{
		Events& events = binding.second->m_events;
		EventDetails& details = binding.second->m_details;
		std::size_t& count = binding.second->m_count;
		
		for (auto& event : events)
		{
			EventType type = event.m_type;
			
			if (type == static_cast<EventType>(sfmlEvent.type))
			{
				if ((type == EventType::KeyDown || type == EventType::KeyUp) && sfmlEvent.key.code == event.m_code)
				{
					++count;
				}
				else if ((type == EventType::MouseDown || type == EventType::MouseUp) && sfmlEvent.mouseButton.button == event.m_code)
				{
					details.m_position.x = sfmlEvent.mouseButton.x;
					details.m_position.y = sfmlEvent.mouseButton.y;
					
					++count;
				}
				else if (type == EventType::Resized)
				{
					details.m_size.x = sfmlEvent.size.width;
					details.m_size.y = sfmlEvent.size.height;
					
					++count;
				}
				else
				{
					++count;
				}
			}
		}
	}
}

void EventManager::update()
{
	for (const auto& binding : m_bindings)
	{
		Events& events = binding.second->m_events;
		EventDetails& details = binding.second->m_details;
		std::size_t& count = binding.second->m_count;
		
		for (auto& event : events)
		{
			EventType type = event.m_type;
			
			if (type == EventType::Keyboard && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(event.m_code)))
			{
				++count;
			}
			
			if (type == EventType::Mouse && sf::Mouse::isButtonPressed(sf::Mouse::Button(event.m_code)))
			{
				++count;
			}
		}
		
		if (count == events.size())
		{
			auto foundState = m_callbacks.find(m_currentState);
			auto permanentState = m_callbacks.find(static_cast<StateName>(0));
			
			if (foundState != m_callbacks.end())
			{
				auto found = foundState->second.find(binding.first);
				if (found != foundState->second.end())
				{
					found->second(&details);
					binding.second->reset();
				}
			}
			
			if (permanentState != m_callbacks.end())
			{
				auto found = permanentState->second.find(binding.first);
				if (found != permanentState->second.end())
				{
					found->second(&details);
					binding.second->reset();
				}
			}
		}
	}
}

void EventManager::removeCallback(StateName state, const std::string& bindName)
{
	auto foundState = m_callbacks.find(state);
	if (foundState == m_callbacks.end())
	{
		throw std::invalid_argument ("Unable to find state name : " + std::to_string(static_cast<int>(state)));
	}
	
	auto found = foundState->second.find(bindName);
	if (found == foundState->second.end())
	{
		throw std::invalid_argument ("Unable to find callback name : " + bindName);
	}
	
	foundState->second.erase(found);
}

sf::Vector2i EventManager::getMousePos(sf::Window* window)
{
	if (window)
	{
		return sf::Mouse::getPosition(*window);
	}
	else
	{
		return sf::Mouse::getPosition();
	}
}
