#pragma once

#include <EventListener.h>

enum EventType {
	E_NUEVO_PLAYER = 0,
	E_AUMENTA_MUERTE = 1,
	E_AUMENTA_KILL = 2,
	E_FIN_PARTIDA = 3
};

class Event
{

public:
	Event() { }
	virtual ~Event() { }

	EventType event_type;

	EventListener* sentBy;
};