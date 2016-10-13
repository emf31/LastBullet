#include "RaknetStuff.h"
#include <iostream>
#include <string>


RaknetStuff::RaknetStuff(Player *p){
	peer = RakNet::RakPeerInterface::GetInstance();
	player = p;
}

RaknetStuff::~RaknetStuff(){
	delete peer;
	peer = NULL;
}

void RaknetStuff::bucleCliente() {
	RakNet::Packet *packet;
	RakNet::BitStream bsOut;
	std::string str;

	while (1) {
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			switch (packet->data[0]) {
				case ID_REMOTE_DISCONNECTION_NOTIFICATION:
					printf("Otro cliente se ha desconectado.\n");
					break;
				case 22:
					printf("EL SERVIDOR SE HA CAIDO.\n");
					break;
				case ID_REMOTE_CONNECTION_LOST:
					printf("Otro cliente ha perdido la conexion.\n");
					break;
				case ID_REMOTE_NEW_INCOMING_CONNECTION:
					printf("Otro cliente se ha conectado.\n");
					
					break;

				case ID_CONNECTION_REQUEST_ACCEPTED:
					printf("Nuestra conexion se ha aceptado.\n");
					servidor = packet->guid;
					//Al conectarnos le enviamos nuestro objeto Player tal cual
					bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);
					bsOut.Write(*player);
					peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
					bsOut.Reset();

					break;
				case LISTA_CLIENTES: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					bsIn.Read(clientArray);
				}
					break;
				case NUEVO_PLAYER: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					Player *p = new Player();

					bsIn.Read(*p);

					clientArray.push_back(p);
				}

					break;
				case GUID_NUESTRO: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					RakNet::RakNetGUID g;
					bsIn.Read(g);
					player->setGuid(g);
					player->conectado = 1;
				}
					break;

				default:
					printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
					break;

			}
		}
		if (player->conectado) {
			//Actualizamos player en el getInput y luego lo enviamos actualizado al servidor.
			player->getInput();
			bsOut.Write((RakNet::MessageID)MOVIMIENTO);
			bsOut.Write(*player);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
			bsOut.Reset();
			std::cout << "LISTA DE CLIENTES" << std::endl;
			std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
			for (int i = 0; i < clientArray.size(); i++) {
				std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
				std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
			}
		}

	}

}

void RaknetStuff::Conectar(std::string address, int port) {
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);
	bucleCliente();
	//std::thread hiloCliente(&RaknetStuff::bucleCliente,this);
}
