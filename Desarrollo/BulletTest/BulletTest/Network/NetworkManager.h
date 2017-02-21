#pragma once
#include <NetObject.h>
#include <Time.h>
#include <list>
#include <memory>
#include <Player.h>
#include <Enemy_Bot.h>
#include <NetPlayer.h>
#include <NetBot.h>

static const int server_port = 65535;



class NetworkManager {

public:

	~NetworkManager();

	static NetworkManager& i() {
		static NetworkManager singleton;
		return singleton;
	}

	void createServer();
	bool removeNetBotObject(std::shared_ptr<NetBot> netobj);
	void apagar();
	
	//Creates a pointer of NetPlayer
	std::shared_ptr<NetPlayer> createNetPlayer(Player* player);
	std::shared_ptr<NetBot> createNetBot(Enemy_Bot* bot);

	//Call handle packets for every netobject
	void updateNetwork(Time elapsedTime);

	void startup(LPCTSTR lpApplicationName);


	//Send packet to server using netplayer peer (used for global messages like kills, deaths, life objects)
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {

		m_netPlayer->dispatchMessage(estructura, messageType);
	}

	bool isConnected() const { return m_netPlayer->isConnected(); }

	const std::vector<TPlayer>& getEnemies() const { return m_netPlayer->getEnemies(); }

private:

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE hJob;
	JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli;


	std::shared_ptr<NetPlayer> m_netPlayer;

	std::list<std::shared_ptr<NetBot>> m_netBots;

	std::string serverIP;

	NetworkManager() { }
};