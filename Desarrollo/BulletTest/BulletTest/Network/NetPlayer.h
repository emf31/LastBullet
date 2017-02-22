#pragma once
#include <NetObject.h>
#include <NetworkDebugger.h>
#include <memory>
#include <Windows.h>


//Forward declaration - prevents circular reference
class Player;
class World;

class NetPlayer : public NetObject {
public:
	NetPlayer(Player* player);
	~NetPlayer();

	virtual void inicializar() override;

	virtual void handlePackets(Time elapsedTime) override;

	virtual void apagar();

	void crearPartida();


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


private:

	Player* m_player;
	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	//Almacena los player recibidos al empezar una partida
	//Lo hacemos para sincronizar la creacion de los enemigos del servidor
	//con las demas entities locales
	std::vector<TPlayer> m_enemies;

	TGameInfo m_info;

	World& m_world;

#ifdef NETWORK_DEBUG
	std::shared_ptr<NetworkDebugger> debugger;
#endif

};