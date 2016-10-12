#pragma once

#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	MENSAJE_POSICION = ID_USER_PACKET_ENUM + 2,
	MENSAJE_NOMBRE = ID_USER_PACKET_ENUM + 3,
	OBJETO = ID_USER_PACKET_ENUM + 4
};

class RaknetStuff
{
public:
	RaknetStuff();
	~RaknetStuff();

	void Conectar(std::string address, int port);
private:
	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID *servidor;
	RakNet::RakPeerInterface *peer;
};