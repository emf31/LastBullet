#pragma once

enum EventType {
	E_NUEVO_PLAYER = 0,
	E_AUMENTA_MUERTE = 1,
	E_AUMENTA_KILL = 2
};



class Event
{

public:
	Event() { }
	virtual ~Event() { }
	EventType event_type;

};