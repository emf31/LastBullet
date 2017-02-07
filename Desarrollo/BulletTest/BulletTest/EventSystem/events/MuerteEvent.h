#pragma once
#include <RakNetTypes.h>
#include <events/Event.h>
class MuerteEvent : public Event {
public:
	MuerteEvent(RakNet::RakNetGUID guid) : Event(),
		m_guid(guid)
	{
		event_type = E_AUMENTA_MUERTE;
	}

	~MuerteEvent(){ }

	RakNet::RakNetGUID m_guid;
};