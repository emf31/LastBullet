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
	std::shared_ptr<NetPlayer> createNetPlayer();
	std::shared_ptr<NetBot> createNetBot();

	//Call handle packets for every netobject
	void updateNetwork(Time elapsedTime);

	void configureNetwork();

	//Solicita al servidor informacion de la conexión
	std::string serverLogInfo();

	//Send packet to server using netplayer peer (used for global messages like kills, deaths, life objects)
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {

		m_netPlayer->dispatchMessage(estructura, messageType);
	}

	bool isConnected() const { return m_netPlayer->isConnected(); }

	const std::vector<TPlayer>& getEnemies() const { return m_netPlayer->getEnemies(); }
	const std::vector<TPlayer>& getBots() const { return m_netPlayer->getBots(); }
	std::shared_ptr<NetPlayer> getNetPlayer() const { return m_netPlayer; }


	bool isMovementPrediction() const { return movementPrediction; }
	void setMovementPrediction(bool a) { movementPrediction = a; }

	std::list<std::shared_ptr<NetBot>>& getNetBots() {
		return m_netBots;
	}
	
private:

	void startup(LPCTSTR lpApplicationName);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE hJob;
	JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli;


	std::shared_ptr<NetPlayer> m_netPlayer;

	std::list<std::shared_ptr<NetBot>> m_netBots;

	

	std::string serverIP;

	bool movementPrediction;

	NetworkManager() { }
};