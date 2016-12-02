#pragma once
#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
#include <atomic>
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

	void createPlayer() {
		RakNet::BitStream bsOut;
		std::string str;
		TPlayer nuevoplayer;

		
		//Al conectarnos le enviamos nuestro objeto Player tal cual
		bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);

		printf("Introduce un nombre \n");
		std::cin >> str;


		Player *player = new Player(str, peer->GetMyGUID());
		player->inicializar();
		player->cargarContenido();


		nuevoplayer.guid = player->getGuid();
		nuevoplayer.name = player->getName();
		//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
		nuevoplayer.position = Vec3<float>(0, 100, 0);
		player->setPosition(nuevoplayer.position);



		bsOut.Write(nuevoplayer);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
		bsOut.Reset();

	}
	void inicializar();
	void conectar(std::string address, int port);
	void esperar();
	void enviarMovimiento(Player* p); 
	void vidaCogida(int id);
	void nuevaVida(int id);
	void armaCogida(int id);
	void nuevaArma(int id);
	void lanzarGranada(TGranada g);
	void enviarDisparo(RakNet::RakNetGUID guid);
	void enviarDesconexion();
	void dispararBala(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation);
	void dispararRrocket(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation);
	void playerMuerto();
	void impactoRocket(RakNet::RakNetGUID palayerDanyado, int danyo);
	void aplicarImpulso(Vec3<float> force, RakNet::RakNetGUID guid);

	//Como si fuera el delete
	void apagar();


	bool isConected() {
		return conectado;
	}

private:
	RakNet::Packet *packet;
	RakNet::RakPeerInterface *peer;

	RakNet::SocketDescriptor sd;
	RakNet::RakNetGUID servidor;
	std::thread* hilo;

	std::mutex m;
	
	Cliente();

	std::atomic<bool> conectado;
	std::atomic<bool> shutdown;


	RakNet::BitStream bsOut;
	std::string str;
	TPlayer nuevoplayer;
	TBala balaDisparada;
	TGranada granada;
	TVidaServer vidaServer;
	RakNet::RakNetGUID desconectado;
	int idVida;
	float danyo = 0.0f;
	Vec3<float> fuerza;
};

