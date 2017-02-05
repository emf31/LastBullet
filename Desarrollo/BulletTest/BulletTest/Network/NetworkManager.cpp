#include "NetworkManager.h"


void NetworkManager::inicializar(const std::string& address)
{
	serverIP = address;
}

void NetworkManager::createNetObject(NetObject * netobj)
{
	if (netobj != NULL) {
		m_netobjs.push_back(netobj);
	}
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	std::list<NetObject*>::iterator it;
	for (it = m_netobjs.begin(); it != m_netobjs.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}
}
