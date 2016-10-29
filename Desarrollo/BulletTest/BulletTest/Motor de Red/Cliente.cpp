
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Estructuras.h"
#include "../Entities/EntityManager.h"
#include "../Entities/Entity.h"


Cliente::Cliente()
{
}

void Cliente::update() {
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

			case ID_CONNECTION_REQUEST_ACCEPTED: {

				printf("Nuestra conexion se ha aceptado.\n");
				servidor = packet->guid;
				//Al conectarnos le enviamos nuestro objeto Player tal cual
				bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);

				printf("Introduce un nombre \n");
				std::cin >> str;

				Entity* ent = EntityManager::i().getEntity(1);
				ent->setGUID(peer->GetMyGUID());
				ent->setName(str);
				TPlayer nuevoplayer;

				nuevoplayer.guid = ent->getGuid();
				nuevoplayer.name = ent->getName();
				//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
				nuevoplayer.position = ent->getRenderState()->getPosition();

				bsOut.Write(nuevoplayer);
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
				bsOut.Reset();

			}
				break;
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;

			}
		}
		/*
		if (player->conectado) {
		//Actualizamos player en el getInput y luego lo enviamos actualizado al servidor.
		if (cont == 0) {
		int mov = 0;
		mov = player->getInput();
		if (mov != 0) {
		bsOut.Write((RakNet::MessageID)MOVIMIENTO);
		bsOut.Write(mov);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
		bsOut.Reset();
		player->restablecerMovimiento();
		}

		}
		cont++;

		if (cont >= 200000)
		cont = 0;
		}


		
		*/
	}

}

void Cliente::inicializar() {
	peer = RakNet::RakPeerInterface::GetInstance();

	printf("Introduce la IP \n");
	std::string str;
	std::cin >> str;
	std::cout << "Conectando al servidor " << str << ":" << SERVER_PORT << std::endl;

	conectar(str, SERVER_PORT);
}

void Cliente::conectar(std::string address, int port) {
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);
	//bucleCliente();
	//return std::thread(&Cliente::bucleCliente, this);
	hilo= new std::thread(&Cliente::update, this);
}

void Cliente::esperar() {
	hilo->join();
}