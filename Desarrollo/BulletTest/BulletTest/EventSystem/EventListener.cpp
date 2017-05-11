#include "EventListener.h"
#include <events\Event.h>
#include <EventSystem.h>

EventListener::EventListener()
{
	EventSystem::i().registerListener(this);
}

EventListener::~EventListener()
{
}

void EventListener::setEventType(const int eventType)
{
	m_EventType = eventType;
}

int EventListener::getEventType() const
{
	return m_EventType;
}
