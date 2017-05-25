#pragma once
#include <NetObject.h>
#include <NetworkDebugger.h>
#include <memory>
#include <Windows.h>
#include <AsyncEnemyFactory.h>
#include <Lobby2Client_Steam.h> // If Lobby2Client_Steam.h is included before SocketLayer.h, then it will use the steam send functions
#include <Lobby2Message_Steam.h>
#include <FullyConnectedMesh2.h>
#include <steam_api.h>
#include <RakNetTypes.h>
#include <SteamResults.h>
#include <GUIManager.h>
#include <MenuGUI.h>

//Forward declaration - prevents circular reference
class Player;
class World;

class NetPlayer : public NetObject {
public:
	NetPlayer();
	~NetPlayer();

	virtual void inicializar() override;

	virtual void handlePackets(Time elapsedTime) override;

	virtual void apagar();

	void crearPartida();

	void setPlayerObject(Player* player);

	uint64_t crearLobby();

	void unirseLobby(const std::string& str);

	//Send packet to server using netplayer peer 
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;

		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, getServerGUID(), false);
	}
	void searchServersOnLAN();

	std::vector<std::string> getServers() { return m_servers; }

	const std::vector<TPlayer>& getEnemies() const { return m_enemies; }

	const std::vector<TPlayer>& getBots() const { return m_bots; }

	AsyncEnemyFactory& getEnemyFactory() { return m_enemyFactory; }


	uint64_t getLobbyID();
	RakNet::Lobby2MessageFactory_Steam* getMessageFactory();
	RakNet::Lobby2Client_Steam* getLobby2Client();

	void joinSteamLobby(/*const std::string& ip,*/ uint64 lobbyID);

	void sendServerIPtoNewClient();
	
	void sendReadyPlayersToNewClient();

	void setReadyPlayers(int ready);

	void leaveLobby();

	void sendReadyStatus();

	void playerReadyCallback(const std::string& name);

	void comenzarPartida();

	void playerNotReadyCallback(const std::string& name);

	void receiveSteamPackets();

	void addPlayerInLobby(uint64_t steamID);

	void substractPlayerInLobby(uint64_t steamID);

	void setHostIp(const std::string& ip) { hostIp = ip; }

	void setLanServer(bool lan);

	bool isReady() const { return IamReady; }


private:

	Player* m_player;

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	//Almacena los player recibidos al empezar una partida
	//Lo hacemos para sincronizar la creacion de los enemigos del servidor
	//con las demas entities locales
	std::vector<TPlayer> m_enemies;

	std::vector<TPlayer> m_bots;

	TGameInfo m_info;

	World& m_world;


	AsyncEnemyFactory m_enemyFactory;

	RakNet::Lobby2MessageFactory_Steam *messageFactory;
	RakNet::Lobby2Client_Steam *lobby2Client;
	SteamResults steamResults;
	
	std::vector<uint64_t> SteamIDs;

	bool IamHost = false;
	std::string hostIp;
	int playersReady = 0;
	bool IamReady = false;

	bool inLobby = true;

	bool LanServer = true;

	

#ifdef NETWORK_DEBUG
	std::shared_ptr<NetworkDebugger> debugger;
#endif

};