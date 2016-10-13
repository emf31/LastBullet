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
	int cont = 0;

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

					player->setGuid(peer->GetMyGUID());
					player->conectado = 1;

					bsOut.Write(*player);
					peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
					bsOut.Reset();
					

					break;
				case LISTA_CLIENTES: {

					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					bsIn.Read(clientArray);
					std::cout << "Creo mi lista de clientes (Soy el player nuevo)" << std::endl;

					std::cout << "LISTA DE CLIENTES" << std::endl;
					std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
					for (int i = 0; i < clientArray.size(); i++) {
						std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
						std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
					}
				}
				break;
				case NUEVO_CLIENTE: {
					//esto se da cuando se conecta un player por primera vez, que te envian todos los clientes que ya habian para que te hagas tu lista de clientes
					Player *nuevocliente = new Player();
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					bsIn.Read(*nuevocliente);

					clientArray.push_back(nuevocliente);
					std::cout << "Meto nuevo cliente en la lista de clientes (Soy el player nuevo)" << std::endl;
					std::cout << "" << std::endl;
					std::cout << "LISTA DE CLIENTES" << std::endl;
					std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
					for (int i = 0; i < clientArray.size(); i++) {
						std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
						std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
					}

				}
					break;
				case NUEVO_PLAYER: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					Player *p = new Player();

					bsIn.Read(*p);
					clientArray.push_back(p);

					std::cout << "Meto nuevo cliente en la lista de clientes (soy un player viejo)" << std::endl;
					std::cout << "" << std::endl;
					std::cout << "LISTA DE CLIENTES" << std::endl;
					std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
					for (int i = 0; i < clientArray.size(); i++) {
						std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
						std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
					}
					//delete p;
				}

					break;
				case GUID_NUESTRO: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					RakNet::RakNetGUID g;
					bsIn.Read(g);
					player->setGuid(peer->GetMyGUID());
					player->conectado = 1;
				}
					break;
				case ELIMINAR_CLIENTE: {
					RakNet::BitStream bsIn(packet->data,packet->length,false);
					Player *p = new Player();

					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					bsIn.Read(*p);
					for (int i = 0; i < clientArray.size(); i++) {
						if (clientArray.at(i)->getGuid() == p->getGuid()) {
							clientArray.erase(clientArray.begin() + i);
						}
					}

					std::cout << "Elimino al cliente que se ha desconectado..." << std::endl;
					std::cout << "" << std::endl;
					std::cout << "LISTA DE CLIENTES" << std::endl;
					std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
					for (int i = 0; i < clientArray.size(); i++) {
						std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
						std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
					}
					//delete p;
				}
				break;
				case ACTUALIZA_CLIENTE: {
					RakNet::BitStream bsIn;
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					Player *p = new Player();
					bsIn.Read(*p);

					if (p->getGuid() == player->getGuid()) {
						//SOY YO
						player = p;
					} else {
						//ES OTRA PERSONA
						for (int i = 0; i < clientArray.size(); i++) {
							if (clientArray.at(i)->getGuid() == p->getGuid()) {
								//Te actualizo
								clientArray.at(i) = p;
								break;
							}
						}
					}


				}
					break;

				default:
					printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
					break;

			}
		}
		if (player->conectado) {
			//Actualizamos player en el getInput y luego lo enviamos actualizado al servidor.
			if (cont == 0) {
				player->getInput();
				bsOut.Write((RakNet::MessageID)MOVIMIENTO);
				bsOut.Write(player->movimiento);
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
				bsOut.Reset();
			}
			cont++;

			if (cont >= 1000)
				cont = 0;
		}


	}

}

std::thread RaknetStuff::Conectar(std::string address, int port) {
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);
	//bucleCliente();
	return std::thread(&RaknetStuff::bucleCliente,this);
}
