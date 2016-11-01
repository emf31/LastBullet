#pragma once
#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
#include "../Otros/Time.hpp"
#include "../Entities/Player.h"


class Cliente
{
public:


	static Cliente& i() {
		static Cliente singleton;
		return singleton;
	}

	void update();

	void inicializar();
	void conectar(std::string address, int port);
	void esperar();
	void enviarPos(Player* p);
	void enviarDisparo(RakNet::RakNetGUID guid);

private:
	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID servidor;
	std::thread* hilo;
	RakNet::RakPeerInterface *peer;
	Cliente();

};

