#pragma once
#include <list>
#include <Estructuras.h>
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h> 

class LobbyClient {
	//Para que solo se puedan añadir jugadores a la sala desde la clase Cliente
	friend class Cliente;
public:
	LobbyClient(RakNet::RakPeerInterface *peer);
	~LobbyClient();

	//Llama al objeto cliente para conectarse al servidor
	void join(const std::string& address, int port);

	void disconnect();
	
	int getMaxPlayers() const;
private:

	bool addPlayer(const TPlayer& p);

	int maxPlayers;
	//Para enviar mensajes
	RakNet::RakPeerInterface *m_peer;
	//Guardamos los clientes conectados a la sala, 
	//el primer cliente siempre será el local
	std::list<TPlayer> clients;
};