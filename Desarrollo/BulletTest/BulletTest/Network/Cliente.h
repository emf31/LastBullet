#pragma once
#define SERVER_PORT 65535
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <Time.hpp>
#include <Player.h>
#include <Lobby.h>

class Cliente
{
public:

	Cliente();
	/*static Cliente& i() {
		static Cliente singleton;
		return singleton;
	}*/

	void update();

	void createPlayer(std::vector<Vec3<float>> &spawnPoints);
	void inicializar();
	void conectar(std::string address, int port);
	//void enviarMovimiento(Player* p); 
	//void vidaCogida(int id);
	//void nuevaVida(int id);
	//void armaCogida(int id);
	//void nuevaArma(int id);
	//void lanzarGranada(TGranada g);
	//void enviarDisparo(RakNet::RakNetGUID guid, float* damage);
	//void enviarDesconexion();
	//void dispararBala(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation);
	//void dispararRocket(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation);
	//void playerMuerto();
	//void impactoRocket(RakNet::RakNetGUID palayerDanyado, TImpactoRocket* impact);
	//void aplicarImpulso(Vec3<float> force, RakNet::RakNetGUID guid);
	//void cambioArma(int cambio, RakNet::RakNetGUID guid);
	//void actualizaTabla(RakNet::RakNetGUID guidKill, RakNet::RakNetGUID guidDeath);

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
	

	

	bool conectado;


	RakNet::BitStream bsOut;
	std::string str;
	//TMovimiento movimiento;
	TPlayer nuevoplayer;
	//TBala balaDisparada;
	//TGranada granada;
	//TCambioArma t_cambioArma;
	//TVidaServer vidaServer;
	//TImpactoRocket impacto;
	//TImpactoBala imp_bala;
	//RakNet::RakNetGUID desconectado;
	//RakNet::RakNetGUID guidDispara;
	//RakNet::RakNetGUID guidTabla;
	//TFilaTabla nuevaFila;
	int idVida;
	float danyo = 0.0f;
	Vec3<float> fuerza;

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	//Lobby de la partida
	//LobbyClient lobby;
};

