#pragma once
#include <events/Event.h>
#include <RakNetTypes.h>

class EndGameEvent : public Event{
public:
	EndGameEvent(RakNet::RakNetGUID& p) : Event(),
		guid(p)
	{
		event_type = E_FIN_PARTIDA;
	}

	~EndGameEvent() { }

	RakNet::RakNetGUID& guid;
};