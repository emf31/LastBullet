#pragma once
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <Time.hpp>
#include <Player.h>
#include <RakSleep.h>
#include <EventListener.h>


class NetObject {

public:
	NetObject();
	virtual ~NetObject();

	virtual void inicializar();

	virtual void conectar(const std::string& ip, int port);

	virtual void handlePackets(Time elapsedTime) = 0;


	virtual void apagar();


	bool isConnected() const { return connected; }
	const std::string& getServerIp() { return servidorAdr.ToString(); }
	const RakNet::RakNetGUID& getServerGUID() const { return servidor; }
	const RakNet::RakNetGUID& getMyGUID() const { return peer->GetMyGUID(); }


protected:
	RakNet::Packet *packet;
	RakNet::RakPeerInterface *peer;

	unsigned char mPacketIdentifier;
	unsigned char getPacketIdentifier(RakNet::Packet* pPacket);

	RakNet::RakNetGUID servidor;
	RakNet::SystemAddress servidorAdr;

	bool connected;

private:

	RakNet::SocketDescriptor sd;

	void searchServersOnLAN() {
		//Creo un RakPeer para lanzar un paquete de b�squeda
		RakNet::RakPeerInterface *client;
		client = RakNet::RakPeerInterface::GetInstance();

		RakNet::SocketDescriptor socketDescriptor(65534, 0);
		socketDescriptor.socketFamily = AF_INET;

		client->Startup(1, &socketDescriptor, 1);

		RakNet::RakNetGUID rakID = client->GetMyGUID();

		//Hacemos ping a bradcast en el puerto en el que sabemos que est� escuchando el server
		client->Ping("255.255.255.255", 65535, false);
		std::cout << "Buscando servidores en la red local..." << std::endl;
		RakSleep(1000);
		RakNet::Packet *packet;
		//Limpiamos la lista de servidores primero.
		m_servers.clear();

		for (packet = client->Receive(); packet; client->DeallocatePacket(packet), packet = client->Receive()) {
			if (packet == 0) {
				RakSleep(1000);
				continue;
			}
			if (packet->data[0] == ID_UNCONNECTED_PONG) {
				RakNet::TimeMS time;
				RakNet::BitStream bsIn(packet->data, packet->length, false);

				bsIn.IgnoreBytes(1);
				bsIn.Read(time);
				//printf("Ping is %i\n", (unsigned int)(RakNet::GetTimeMS() - time));
				m_servers.push_back(packet->systemAddress.ToString());
			}

			RakSleep(1000);
		}
		//Destruyo el RakPeer. Ya no hace falta
		RakNet::RakPeerInterface::DestroyInstance(client);
	}

	//Lista de servidores disponibles
	std::vector<std::string> m_servers;

	friend class NetworkManager;
};