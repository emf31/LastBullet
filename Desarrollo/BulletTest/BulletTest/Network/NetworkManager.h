#pragma once
#include <NetObject.h>
#include <Time.h>
#include <list>
#include <memory>
#include <Player.h>
#include <NetPlayer.h>

static const int server_port = 65535;



class NetworkManager {

public:
	//Easy access to pointers
	/*typedef std::shared_ptr<NetPlayer> NetPlayerPtr;
	//typedef std::shared_ptr<NetBot> NetBotPtr;
	typedef std::shared_ptr<NetObject> NetPtr;*/


	static NetworkManager& i() {
		static NetworkManager singleton;
		return singleton;
	}

	void inicializar(const std::string& address);
	//bool removeNetBotObject(std::shared_ptr<NetPlayer> netobj);
	void apagar();
	
	//Creates a pointer of NetPlayer
	std::shared_ptr<NetPlayer> createNetPlayer(Player* player);

	//Call handle packets for every netobject
	void updateNetwork(Time elapsedTime);


	//Send packet to server using netplayer peer (used for global messages like kills, deaths, life objects)
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;
			
		m_netPlayer->peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, m_netPlayer->getServerGUID(), false);
	}



private:

	std::shared_ptr<NetPlayer> m_netPlayer;

	//std::list<NetObject> m_netObjs;

	//std::string serverIP;

	NetworkManager() { }
};