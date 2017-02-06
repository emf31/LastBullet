#include "NetworkManager.h"


void NetworkManager::inicializar(const std::string& address)
{
	serverIP = address;
}

/*bool NetworkManager::removeNetBotObject(NetPtr netobj)
{
	//m_netObjs.remove(netobj);

	//should check here if it's removed

	return true;
}*/

void NetworkManager::apagar()
{
	//m_netObjs.clear();

	//m_netPlayer.reset();

	m_netPlayer->apagar();

}

//Creates net player object and stores it in shared ptr
std::shared_ptr<NetPlayer> NetworkManager::createNetPlayer(Player* player)
{
	NetPlayer* netp = new NetPlayer(player);

	// takes ownership of pointer
	// if acquires new pointer, deletes managed object 
	m_netPlayer.reset(netp);
	
	return m_netPlayer;
	
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	/*std::list<NetPtr>::iterator it;
	for (it = m_netObjs.begin(); it != m_netObjs.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}*/

	//We call handle packets of netplayer too
	m_netPlayer->handlePackets(elapsedTime);
}
