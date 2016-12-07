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
	void impactoRocket(RakNet::RakNetGUID palayerDanyado, int danyo, RakNet::RakNetGUID guidKill);
	void aplicarImpulso(Vec3<float> force, RakNet::RakNetGUID guid);
	void cambioArma(int cambio, RakNet::RakNetGUID guid);
	void actualizaTabla(RakNet::RakNetGUID guidKill, RakNet::RakNetGUID guidDeath);

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
	std::unordered_map <unsigned long, TFilaTabla> tablaProvisional;

	std::mutex m;
	
	Cliente();

	bool conectado;

};

