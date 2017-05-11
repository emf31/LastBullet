#pragma once
#include <iostream>
#include <RakNetTypes.h>
#include <events/Event.h>
#include <Estructuras.h>
class GameStartEvent : public Event {
public:
	GameStartEvent(const TGameInfo& info) : Event(),
		m_info(info)
	{
		event_type = E_GAME_START;
	}

	~GameStartEvent() { }

	TGameInfo m_info;
}; 
