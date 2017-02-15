#pragma once
#include <NetObject.h>
#include <NetworkDebugger.h>
#include <memory>
#include <Windows.h>

//Forward declaration - prevents circular reference
class Player;

class NetPlayer : public NetObject {
public:
	NetPlayer(Player* player);
	~NetPlayer();

	virtual void inicializar() override;

	virtual void handlePackets(Time elapsedTime) override;

	virtual void apagar();

	void crearPartida(const TGameInfo& gameinfo);


	void crearLobby();

	void unirseLobby();

	//Send packet to server using netplayer peer 
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;

		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, getServerGUID(), false);
	}

private:

	void startup(LPCTSTR lpApplicationName);

	Player* m_player;

	void searchServersOnLAN();

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

#ifdef NETWORK_DEBUG
	std::shared_ptr<NetworkDebugger> debugger;
#endif

};