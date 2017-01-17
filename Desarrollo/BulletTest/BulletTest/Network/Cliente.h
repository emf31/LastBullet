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

	Player* createPlayer();
	void inicializar();
	void conectar(std::string address, int port);

	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;
		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, servidor, false);
	}

	void searchServersOnLAN();

	//Como si fuera el delete
	void apagar();


	bool isConected() const {
		return conectado;
	}

private:
	RakNet::Packet *packet;
	RakNet::RakPeerInterface *peer;

	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID servidor;
	
	//private constructor
	Cliente();

	bool conectado;

	std::string str;

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	//Lobby de la partida
	//LobbyClient lobby;


	unsigned char mPacketIdentifier;
	unsigned char getPacketIdentifier(RakNet::Packet* pPacket);

};
