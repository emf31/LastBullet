#include "RaknetStuff.h"



RaknetStuff::RaknetStuff(){
	peer = RakNet::RakPeerInterface::GetInstance();
}


RaknetStuff::~RaknetStuff(){
	delete peer;
	delete servidor;
	peer = NULL;
	servidor = NULL;
}

void RaknetStuff::Conectar(std::string address, int port) {
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);
	//std::thread hilo1();
}
