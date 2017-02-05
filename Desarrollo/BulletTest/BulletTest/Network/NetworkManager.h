#pragma once
#include <NetObject.h>
#include <Time.h>
#include <list>
#include <memory>
#include <Player.h>
#include <NetPlayer.h>

static const int SERVER_PORT = 65535;

class NetworkManager {
public:

	//Easy access to pointers
	typedef std::shared_ptr<NetPlayer> NetPlayerPtr;
	//typedef std::shared_ptr<NetBot> NetBotPtr;
	typedef std::shared_ptr<NetObject> NetPtr;

public:

	static NetworkManager& i() {
		static NetworkManager singleton;
		return singleton;
	}

	void inicializar(const std::string& address);
	bool removeNetObject(NetPtr netobj);
	void apagar();
	
	//Creates a pointer of NetPlayer
	std::shared_ptr<NetObject> createNetPlayer(Player* player);

	//Call handle packets for every netobject
	void updateNetwork(Time elapsedTime);

private:
	std::list<NetPtr> m_netObjs;

	std::string serverIP;

	NetworkManager() { }
};