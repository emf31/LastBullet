#include "NetworkManager.h"


void NetworkManager::inicializar(const std::string& address)
{
	serverIP = address;
}

bool NetworkManager::removeNetBotObject(std::shared_ptr<NetBot> netobj)
{
	m_netBots.remove(netobj);

	//should check here if it's removed

	return true;
}

void NetworkManager::apagar()
{
	m_netBots.clear();

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

std::shared_ptr<NetBot> NetworkManager::createNetBot(Enemy_Bot * bot)
{
	NetBot* netp = new NetBot(bot);

	std::shared_ptr<NetBot> ptr(netp);

	m_netBots.push_back(ptr);

	return ptr;
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	std::list<std::shared_ptr<NetBot>>::iterator it;
	for (it = m_netBots.begin(); it != m_netBots.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}

	//We call handle packets of netplayer too
	m_netPlayer->handlePackets(elapsedTime);
}
