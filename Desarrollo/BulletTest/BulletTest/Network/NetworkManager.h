#pragma once
#include <NetObject.h>
#include <Time.h>
#include <list>
#include <memory>
#include <Player.h>
#include <NetPlayer.h>

static const int server_port = 65535;

//Easy access to pointers
typedef std::shared_ptr<NetPlayer> NetPlayerPtr;
//typedef std::shared_ptr<NetBot> NetBotPtr;
typedef std::shared_ptr<NetObject> NetPtr;

class NetworkManager {


public:

	static NetworkManager& i() {
		static NetworkManager singleton;
		return singleton;
	}

	void inicializar(const std::string& address);
	bool removeNetObject(NetPtr netobj);
	void apagar();
	
	//Creates a pointer of NetPlayer
	NetPlayerPtr createNetPlayer(Player* player);

	//Call handle packets for every netobject
	void updateNetwork(Time elapsedTime);

private:
	std::list<NetPtr> m_netObjs;

	std::string serverIP;

	NetworkManager() { }
};