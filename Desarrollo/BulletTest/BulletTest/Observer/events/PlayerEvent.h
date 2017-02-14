#pragma once
#include <events/Event.h>
#include <Player.h>

class PlayerEvent : public Event{
public:
	PlayerEvent(TFilaTabla& p) : Event(),
		m_fila(p)
	{
		event_type = E_NUEVO_PLAYER;
	}

	~PlayerEvent() { }

	TFilaTabla& m_fila;
};