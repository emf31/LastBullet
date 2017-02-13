#include "NetObject.h"
#include <NetworkManager.h>

NetObject::NetObject()
{
}

NetObject::~NetObject()
{

}


void NetObject::conectar(const std::string& ip, int port)
{
	peer = RakNet::RakPeerInterface::GetInstance();
	peer->AllowConnectionResponseIPMigration(false);
	peer->Startup(1, &sd, 1);
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

