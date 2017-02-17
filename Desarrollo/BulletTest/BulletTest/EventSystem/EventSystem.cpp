#include "EventSystem.h"

void EventSystem::dispatch(Event * e)
{
	//add the event to evenlist, we'll dispatch it later
	m_EventList.push(e);
}

void EventSystem::dispatchNow(Event * e)
{
	//dispatch the event now

	for (auto i = m_EventListeners.begin(); i != m_EventListeners.end(); i++)
	{
		EventListener* listener = (*i);

		if (listener)
		{
			// Don't dispatch event back to it dispatcher
			if (listener != e->sentBy) {
				listener->handleEvent(e);
			}

		}

	}

	releaseEvent(e);
}

void EventSystem::update(void)
{
	int a;
	a = 5;
}

void EventSystem::borrarContenido()
{
	while(!m_EventList.empty())
	{
		Event* e = m_EventList.front();
		m_EventList.pop();
		releaseEvent(e);
	}

	m_EventListeners.clear();
}

void EventSystem::releaseEvent(Event* e)
{
	delete e;
	e = nullptr;
}

void EventSystem::registerListener(EventListener * e)
{
	m_EventListeners.push_back(e);
}

void EventSystem::removeListener(EventListener * e)
{
	m_EventListeners.remove(e);
}
