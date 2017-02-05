#pragma once
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <Time.hpp>
#include <Player.h>
#include <Subject.h>


class NetObject {

public:
	NetObject();
	virtual ~NetObject();

	virtual void inicializar();

	virtual void conectar(const std::string& ip, int port);

	virtual void handlePackets(Time elapsedTime) = 0;

	bool isConnected() const { return connected; }
	const std::string& getServerIp() { return servidorAdr.ToString(); }
	const RakNet::RakNetGUID& getServerGUID() const { return servidor; }


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
	
};