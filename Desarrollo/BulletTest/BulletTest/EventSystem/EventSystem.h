#pragma once

#include <events\Event.h>
#include <list>
#include <queue>
#include <memory>

class EventSystem {

public:

	static EventSystem& i() {
		static EventSystem singleton;
		return singleton;
	}


	//Add an event to the queue
	void dispatch(Event* e);

	//Dispatch an event immediately.
	void dispatchNow(Event* e);

	//Loop through events and dispatch to handlers. We call this from main loop
	void update(void);

	//Release the list of events
	void borrarContenido();

	void releaseEvent(Event* e);

	// Event listeners
	void registerListener(EventListener* e);
	void removeListener(EventListener* e);


private:
	//Event Listeners
	std::list<EventListener*> m_EventListeners;

	//Event queue
	std::queue<Event*> m_EventList;

	EventSystem() { }
};