#ifndef STATEBASE_H
#define STATEBASE_H

#include <SFML/System/Time.hpp>

class StateManager;

class StateBase
{
	public:
		
		StateBase(StateManager* stateManager)
		: m_stateManager (stateManager)
		, m_isTranscendant (false)
		, m_isTransparent (false)
		{ }
		
		virtual ~StateBase()
		{ }
		
		virtual void create() = 0;
		virtual void destroy() = 0;
		
		virtual void activate() = 0;
		virtual void deactivate() = 0;
		
		virtual void update(sf::Time) = 0;
		virtual void draw() = 0;
		
		void setTranscendant(bool flag)
		{
			m_isTranscendant = flag;
		}
		
		bool isTranscendant() const
		{
			return m_isTranscendant;
		}
		
		void setTransparent(bool flag)
		{
			m_isTransparent = flag;
		}
		
		bool isTransparent() const
		{
			return m_isTransparent;
		}
		
	protected:
		
		StateManager* m_stateManager;
		
	private:
		
		bool m_isTranscendant;
		bool m_isTransparent;
};

#endif // STATEBASE_H
