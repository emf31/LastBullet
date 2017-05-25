#include "NetObject.h"
#include <NetworkManager.h>

NetObject::NetObject() : peer(nullptr)
{
	peer = RakNet::RakPeerInterface::GetInstance();
	peer->AllowConnectionResponseIPMigration(false);
	//RakNet::SocketDescriptor sdd(1234, 0);
	peer->Startup(1, &sd, 1);
	peer->SetMaximumIncomingConnections(8);
	RakNet::RakNetGUID guid = peer->GetMyGUID();

}

NetObject::~NetObject()
{

}


void NetObject::conectar(const std::string& ip, int port)
{
	
	peer->Connect(ip.c_str(), port, 0, 0);
	peer->SetOccasionalPing(true);

}

void NetObject::apagar()
{
	connected = false;


	//shut down the client
	peer->Shutdown(300);

	//and end the connection
	RakNet::RakPeerInterface::DestroyInstance(peer);

}

unsigned char NetObject::getPacketIdentifier(RakNet::Packet * pPacket)
{
	if (pPacket == 0)
		return 255;

	if ((unsigned char)pPacket->data[0] == ID_TIMESTAMP)
	{
		RakAssert(pPacket->length > sizeof(RakNet::MessageID) + sizeof(RakNet::Time));
		return (unsigned char)pPacket->data[sizeof(RakNet::MessageID) + sizeof(RakNet::Time)];
	}
	else
		return (unsigned char)pPacket->data[0];
}

