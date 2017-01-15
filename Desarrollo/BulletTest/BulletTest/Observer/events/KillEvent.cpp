#include "KillEvent.h"

KillEvent::KillEvent(RakNet::RakNetGUID guid) : Event(),
m_guid(guid)
{
	event_type = E_AUMENTA_KILL;
}

KillEvent::~KillEvent()
{
}
