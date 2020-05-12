#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <memory>
#include <stdexcept>

#include "StateWorld.h"
#include "SharedContext.h"

enum class StateName
{
	MainMenu = 1,
	World,
	Inventory
};

using NameContainer = std::vector<StateName>;
using StateContainer = std::vector<std::pair<StateName, std::unique_ptr<StateBase>>>;
using StateFactory = std::unordered_map<StateName, std::function<StateBase*(void)>>;

class StateManager
{
	public:
		
		StateManager(SharedContext*);
		
		void update(sf::Time);
		void draw();
		
		void switchTo(StateName);
		void remove(StateName);
		
		bool hasState(StateName) const;
		void lateUpdate();
		
		SharedContext* getContext();
		
	private:
		
		void createState(StateName);
		void removeState(StateName);
		
		template <typename T>
		void registerState(StateName);
		
	private:
		
		StateContainer m_states;
		NameContainer m_toRemove;
		StateFactory m_factory;
		
		SharedContext* m_sharedContext;
};

template <typename T>
void StateManager::registerState(StateName name)
{
	m_factory[name] = [this] () -> StateBase*
	{
		return new T (this);
	};
}

#endif // STATEMANAGER_H
