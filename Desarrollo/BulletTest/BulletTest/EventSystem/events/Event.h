#pragma once

#include <EventListener.h>

enum EventType {
	E_NUEVO_PLAYER = 0,
	E_AUMENTA_MUERTE = 1,
	E_AUMENTA_KILL = 2,
	E_FIN_PARTIDA = 3,
	E_NETWORK_DEBUGGER = 4,
	E_GAME_START = 5,
	E_ALLPLAYERS_READY = 6
};

class Event
{

public:
	Event() { }
	virtual ~Event() { }

	EventType event_type;

	EventListener* sentBy;
};