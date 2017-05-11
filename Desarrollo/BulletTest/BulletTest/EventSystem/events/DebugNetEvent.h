#pragma once
#include <RakNetTypes.h>
#include <events/Event.h>
#include <NetworkDebugger.h>

class DebugNetEvent : public Event {
public:
	DebugNetEvent(NetworkDebugger* deb) : Event(),
		m_debugger(deb)
	{
		event_type = E_NETWORK_DEBUGGER;
	}

	~DebugNetEvent(){ }

	NetworkDebugger* m_debugger;
};