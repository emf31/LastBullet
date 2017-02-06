#include "NetworkManager.h"


void NetworkManager::inicializar(const std::string& address)
{
	serverIP = address;
}

bool NetworkManager::removeNetObject(NetPtr netobj)
{
	m_netObjs.remove(netobj);

	//should check here if it's removed

	return true;
}

void NetworkManager::apagar()
{
	m_netObjs.clear();
}

NetPlayerPtr NetworkManager::createNetPlayer(Player* player)
{
	NetPlayer* netp = new NetPlayer(player);
	NetPlayerPtr ptr(netp);

	m_netObjs.push_back(ptr);

	return ptr;
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	std::list<NetPtr>::iterator it;
	for (it = m_netObjs.begin(); it != m_netObjs.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}
}
