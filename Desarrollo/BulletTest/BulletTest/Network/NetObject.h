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

	virtual void inicializar() = 0;

	virtual void conectar(const std::string& ip, int port);

	virtual void handlePackets(Time elapsedTime) = 0;


	virtual void apagar();


	bool isConnected() const { return connected; }
	const std::string& getServerIp() { return servidorAdr.ToString(); }
	const RakNet::RakNetGUID& getServerGUID() const { return servidor; }
	const RakNet::RakNetGUID getMyGUID() const { return peer->GetMyGUID(); }

	RakNet::RakPeerInterface *peer;
protected:
	RakNet::Packet *packet;
	

	unsigned char mPacketIdentifier;
	unsigned char getPacketIdentifier(RakNet::Packet* pPacket);

	RakNet::RakNetGUID servidor;
	RakNet::SystemAddress servidorAdr;

	bool connected;
	RakNet::SocketDescriptor sd;
private:

	

	

	friend class NetworkManager;
};