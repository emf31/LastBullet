#pragma once
#include <NetObject.h>
#include <NetworkDebugger.h>
#include <memory>
#include <Windows.h>
#include <AsyncEnemyFactory.h>

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

	void crearLobby();

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

	RakNet::Time getConnectTime() { return connectTime; }
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

	RakNet::Time connectTime;

#ifdef NETWORK_DEBUG
	std::shared_ptr<NetworkDebugger> debugger;
#endif

};