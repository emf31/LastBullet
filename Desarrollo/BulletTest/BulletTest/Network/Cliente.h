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
	void enviarMovimiento(Player* p); 
	void dispararBala(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation);
	void enviarDesconexion();
	void enviarDisparo(RakNet::RakNetGUID guid, float* damage);
	void dispararRocket(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation);
	void impactoRocket(RakNet::RakNetGUID palayerDanyado, TImpactoRocket& impact);
	void lanzarGranada(TGranada& g);
	void aplicarImpulso(Vec3<float> force, RakNet::RakNetGUID guid);
	void playerMuerto();
	void actualizaTabla(RakNet::RakNetGUID guidKill, RakNet::RakNetGUID guidDeath);
	void vidaCogida(int id);
	void armaCogida(int id);
	void nuevaVida(int id);
	void nuevaArma(int id);
	void cambioArma(int cambio, RakNet::RakNetGUID guid);



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

