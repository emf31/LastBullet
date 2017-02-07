#pragma once

class Event;

class EventListener {

public:
	EventListener();
	virtual ~EventListener();

	virtual void handleEvent(Event* ev) = 0;

	void setEventType(const int eventType);
	int getEventType() const;

private:

	int m_EventType;

};