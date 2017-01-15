#include <events/MuerteEvent.h>

MuerteEvent::MuerteEvent(RakNet::RakNetGUID guid) : Event(),
m_guid(guid)
{
	event_type = E_AUMENTA_MUERTE;
}

MuerteEvent::~MuerteEvent()
{
}
