#pragma once
#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <Time.hpp>
#include <Player.h>
#include <Lobby.h>
#include <Subject.h>

class Cliente : public Subject	//Para comunicarse con la partida
{
public:

	
	static Cliente& i() {
		static Cliente singleton;
		return singleton;
	}

	void update();

	void pingServer();

	Player* createPlayer();
	void inicializar();
	void conectar(std::string address, int port);

	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;
		if (messageType != SYNC) {
			resetBar(messageType);
		}
		if (messageType == MOVIMIENTO) {
			countMovementPacketsOut++;
		} else if(messageType != SYNC)
			countPacketsOut++;
		
		
		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, servidor, false);
	}

	void searchServersOnLAN();

	//Como si fuera el delete
	void apagar();


	bool isConected() const {
		return conectado;
	}

	std::string getServerIp() {
		return servidorAdr.ToString();
	}

	void sendSyncPackage(RakNet::RakNetGUID guid, unsigned char mPacketIdentifier);

	int countMovimiento=0, countDisparo=0, countImpacto=0, countDropArma=0, countDropVida=0, countMuerte=0, countGranada=0, countAumentaKill=0, countAumentaMuerte=0;

	int countPacketsIn = 0, countPacketsOut = 0, countPacketsTotal=0;
	int countMovementPacketsIn = 0, countMovementPacketsOut = 0, countMovementPacketsTotal = 0;
private:
	RakNet::Packet *packet;
	RakNet::RakPeerInterface *peer;

	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID servidor;
	RakNet::SystemAddress servidorAdr;
	
	//private constructor
	Cliente();

	bool conectado;

	std::string str;

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	//Lobby de la partida
	//LobbyClient lobby;

	Clock resetBarTime;
	unsigned char mPacketIdentifier;
	unsigned char getPacketIdentifier(RakNet::Packet* pPacket);


	void resetBar();
	void resetBar(unsigned char tipo);
};
