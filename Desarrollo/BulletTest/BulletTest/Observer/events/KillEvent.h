#pragma once
#include <RakNetTypes.h>
#include <events/Event.h>
class KillEvent : public Event {
public:
	KillEvent(RakNet::RakNetGUID guid);
	~KillEvent();

	RakNet::RakNetGUID m_guid;
};