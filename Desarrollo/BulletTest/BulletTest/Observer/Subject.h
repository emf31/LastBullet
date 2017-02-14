#pragma once
#include <list>
#include <Observer.h>
class Subject
{
public:
	void addObserver(Observer* observer);

	void removeObserver(Observer* observer);

protected:
	void notify(Event& event);

private:
	std::list<Observer*> m_observers;
};