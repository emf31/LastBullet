#pragma once
#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
#include <mutex>
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
	void enviarDesconexion();

	//Como si fuera el delete
	void apagar();


	bool isConected() {
		//m.lock();
		return conectado;
		//m.unlock();
	}

private:
	RakNet::Packet *packet;
	RakNet::RakPeerInterface *peer;

	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID servidor;
	std::thread* hilo;

	std::mutex m;
	
	Cliente();

	bool conectado;

};

