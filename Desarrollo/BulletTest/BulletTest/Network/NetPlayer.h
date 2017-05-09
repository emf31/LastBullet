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

	struct SteamResults : public RakNet::Lobby2Callbacks {
		virtual void MessageResult(RakNet::Notification_Console_MemberJoinedRoom *message) {
			RakNet::Notification_Console_MemberJoinedRoom_Steam *msgSteam = (RakNet::Notification_Console_MemberJoinedRoom_Steam *) message;
			RakNet::RakString msg;
			msgSteam->DebugMsg(msg);
			printf("%s\n", msg.C_String());
			// Guy with the lower ID connects to the guy with the higher ID
			uint64_t mySteamId = SteamUser()->GetSteamID().ConvertToUint64();
			if (mySteamId < msgSteam->srcMemberId) {
				// Steam's NAT punch is implicit, so it takes a long time to connect. Give it extra time
				unsigned int sendConnectionAttemptCount = 24;
				unsigned int timeBetweenSendConnectionAttemptsMS = 500;
				RakNet::ConnectionAttemptResult car = RakNet::RakPeerInterface::GetInstance()->Connect(msgSteam->remoteSystem.ToString(false), msgSteam->remoteSystem.GetPort(), 0, 0, 0, 0, sendConnectionAttemptCount, timeBetweenSendConnectionAttemptsMS);
				RakAssert(car == CONNECTION_ATTEMPT_STARTED);
			}
		}

		virtual void MessageResult(RakNet::Console_SearchRooms *message) {
			RakNet::Console_SearchRooms_Steam *msgSteam = (RakNet::Console_SearchRooms_Steam *) message;
			RakNet::RakString msg;
			msgSteam->DebugMsg(msg);
			printf("%s\n", msg.C_String());
			if (msgSteam->roomIds.GetSize()>0) {
				lastRoom = msgSteam->roomIds[0];
			}
		}

		virtual void ExecuteDefaultResult(RakNet::Lobby2Message *message) {
			RakNet::RakString out;
			message->DebugMsg(out);
			printf("%s\n", out.C_String());
		}
		uint64_t lastRoom;
	};
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