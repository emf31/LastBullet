#pragma once
#include <RakNetTypes.h>
#include <events/Event.h>
class KillEvent : public Event {
public:
	KillEvent(RakNet::RakNetGUID guid) : Event(),
		m_guid(guid)
	{
		event_type = E_AUMENTA_KILL;
	}

	~KillEvent() { }

	RakNet::RakNetGUID m_guid;
};