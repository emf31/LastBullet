
#include "PlayerEvent.h"


PlayerEvent::PlayerEvent(TFilaTabla& p) : Event(),
m_fila(p)
{
	event_type = E_NUEVO_PLAYER;
}

PlayerEvent::~PlayerEvent()
{
}
