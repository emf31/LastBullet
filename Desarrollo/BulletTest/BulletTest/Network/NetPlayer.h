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

	uint64_t getLobbyID() {
		if (lobby2Client != nullptr) {
			return lobby2Client->GetRoomID();
		}
		return 0;
	}
	RakNet::Lobby2MessageFactory_Steam* getMessageFactory() {
		return messageFactory;
	}
	RakNet::Lobby2Client_Steam* getLobby2Client() {
		return lobby2Client;
	}

	void joinSteamLobby(/*const std::string& ip,*/ uint64 lobbyID) {
		RakNet::Console_JoinRoom_Steam* msg = (RakNet::Console_JoinRoom_Steam*) messageFactory->Alloc(RakNet::L2MID_Console_JoinRoom);
		msg->roomId = lobbyID;
		std::cout << "Joining Lobby: " << lobbyID << std::endl;
		lobby2Client->SendMsg(msg);
		messageFactory->Dealloc(msg);
		MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
		menu->setNameOnPlayerSlot(SteamFriends()->GetPersonaName());
		//conectar(ip, server_port);
	}

	void receiveSteamPackets() {
		RakNet::Packet *packet;
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			switch (packet->data[0]) {
			case ID_DISCONNECTION_NOTIFICATION:
				// Connection lost normally
				printf("ID_DISCONNECTION_NOTIFICATION\n");
				break;
			case ID_ALREADY_CONNECTED:
				// Connection lost normally
				printf("ID_ALREADY_CONNECTED\n");
				break;
			case ID_REMOTE_DISCONNECTION_NOTIFICATION: // Server telling the clients of another client disconnecting gracefully.  You can manually broadcast this in a peer to peer enviroment if you want.
				printf("ID_REMOTE_DISCONNECTION_NOTIFICATION\n");
				break;
			case ID_REMOTE_CONNECTION_LOST: // Server telling the clients of another client disconnecting forcefully.  You can manually broadcast this in a peer to peer enviroment if you want.
				printf("ID_REMOTE_CONNECTION_LOST\n");
				break;
			case ID_REMOTE_NEW_INCOMING_CONNECTION: // Server telling the clients of another client connecting.  You can manually broadcast this in a peer to peer enviroment if you want.
				printf("ID_REMOTE_NEW_INCOMING_CONNECTION\n");
				break;
			case ID_CONNECTION_BANNED: // Banned from this server
				printf("We are banned from this server.\n");
				break;
			case ID_CONNECTION_ATTEMPT_FAILED:
				printf("Connection attempt failed\n");
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				// Sorry, the server is full.  I don't do anything here but
				// A real app should tell the user
				printf("ID_NO_FREE_INCOMING_CONNECTIONS\n");
				break;
			case ID_INVALID_PASSWORD:
				printf("ID_INVALID_PASSWORD\n");
				break;

			case ID_CONNECTION_LOST:
				// Couldn't deliver a reliable packet - i.e. the other system was abnormally
				// terminated
				printf("ID_CONNECTION_LOST\n");
				break;

			case ID_CONNECTION_REQUEST_ACCEPTED:
				// This tells the client they have connected
				printf("ID_CONNECTION_REQUEST_ACCEPTED to %s with GUID %s\n", packet->systemAddress.ToString(), packet->guid.ToString());
				break;

			case ID_NEW_INCOMING_CONNECTION:
				printf("ID_NEW_INCOMING_CONNECTION\n");
				break;
			default:
				// It's a client, so just show the message
				printf("Unknown Message ID %i\n", packet->data[0]);
				break;
			}
		}
	}
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
	RakNet::FullyConnectedMesh2 *fcm2;
	SteamResults steamResults;
	
#ifdef NETWORK_DEBUG
	std::shared_ptr<NetworkDebugger> debugger;
#endif

};