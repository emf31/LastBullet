#pragma once
#include <RakNetTypes.h>
#include <events/Event.h>
class MuerteEvent : public Event {
public:
	MuerteEvent(RakNet::RakNetGUID guid);
	~MuerteEvent();

	RakNet::RakNetGUID m_guid;
};