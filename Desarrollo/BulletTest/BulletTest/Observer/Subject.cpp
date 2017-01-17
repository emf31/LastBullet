#include "Subject.h"

void Subject::addObserver(Observer*observer)
{
	m_observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer)
{
	m_observers.remove(observer);
}

void Subject::notify(Event& event)
{
	std::list<Observer*>::iterator it;
	for (it = m_observers.begin(); it != m_observers.end(); ++it)
	{
		(*it)->onNotify(event);
	}
}
