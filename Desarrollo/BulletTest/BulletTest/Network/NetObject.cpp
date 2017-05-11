#include "NetObject.h"
#include <NetworkManager.h>

NetObject::NetObject()
{
	peer = RakNet::RakPeerInterface::GetInstance();
	peer->AllowConnectionResponseIPMigration(false);
	RakNet::SocketDescriptor sdd(1234, 0);
	peer->Startup(8, &sdd, 1);
	peer->SetMaximumIncomingConnections(8);

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

	return (unsigned char)pPacket->data[0];
}

