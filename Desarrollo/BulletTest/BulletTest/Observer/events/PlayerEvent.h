#pragma once
#include <events/Event.h>
#include <Player.h>

class PlayerEvent : public Event{
public:
	PlayerEvent(TFilaTabla& p);
	~PlayerEvent();

	TFilaTabla& m_fila;
};