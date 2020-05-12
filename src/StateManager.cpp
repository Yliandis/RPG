#include "StateManager.h"

StateManager::StateManager(SharedContext* sharedContext)
: m_sharedContext (sharedContext)
{
	//registerState<StateMainMenu>(StateName::MainMenu);
	registerState<StateWorld>(StateName::World);
	//registerState<StateInventory>(StateName::Inventory);
}

void StateManager::update(sf::Time dt)
{
	if (m_states.empty())
	{
		return;
	}
	
	auto it = m_states.end() - 1;
	while (it != m_states.begin())
	{
		if (it->second->isTranscendant())
		{
			--it;
		}
		else
		{
			break;
		}
	}
	
	for ( ; it != m_states.end() ; ++it)
	{
		it->second->update(dt);
	}
}

void StateManager::draw()
{
	if (m_states.empty())
	{
		return;
	}
	
	auto it = m_states.end() - 1;
	while (it != m_states.begin())
	{
		if (it->second->isTransparent())
		{
			--it;
		}
		else
		{
			break;
		}
	}
	
	for ( ; it != m_states.end() ; ++it)
	{
		it->second->draw();
	}
}

void StateManager::switchTo(StateName name)
{
	m_sharedContext->m_eventManager->switchTo(name);
	
	if (hasState(name))
	{
		auto found = std::find_if(m_states.begin(), m_states.end(), [name] (const auto& s) { return name == s.first; });
		
		m_states.back().second->deactivate();
		
		std::unique_ptr<StateBase> temp = std::move(found->second);
		m_states.erase(found);
		temp->activate();
		
		m_states.emplace_back(name, std::move(temp));
	}
	else
	{
		if (!m_states.empty())
		{
			m_states.back().second->deactivate();
		}
		
		createState(name);
		m_states.back().second->activate();
	}
}

void StateManager::remove(StateName name)
{
	if (hasState(name))
	{
		m_toRemove.push_back(name);
	}
}

bool StateManager::hasState(StateName name) const
{
	if (std::find(m_toRemove.begin(), m_toRemove.end(), name) == m_toRemove.end())
	{
		return false;
	}
	
	for (const auto& state : m_states)
	{
		if (state.first == name)
		{
			return true;
		}
	}
	
	return false;
}

void StateManager::lateUpdate()
{
	while (!m_toRemove.empty())
	{
		removeState(m_toRemove.back());
		m_toRemove.pop_back();
	}
}

SharedContext* StateManager::getContext()
{
	return m_sharedContext;
}

/*******************
 * Private methods *
 *******************/

void StateManager::createState(StateName name)
{
	auto found = m_factory.find(name);
	if (found == m_factory.end())
	{
		throw std::invalid_argument ("Unable to find state : " + std::to_string(static_cast<int>(name)));
	}
	
	m_states.emplace_back(name, found->second());
	m_states.back().second->create();
}

void StateManager::removeState(StateName name)
{
	auto found = std::find_if(m_states.begin(), m_states.end(), [name] (const auto& s) { return name == s.first; });
	if (found == m_states.end())
	{
		throw std::invalid_argument ("Unable to find state : " + std::to_string(static_cast<int>(name)));
	}
	
	found->second->destroy();
	m_states.erase(found);
}
