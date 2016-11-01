
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Estructuras.h"
#include "../Entities/EntityManager.h"
#include "../Entities/Entity.h"
#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../Handlers/Message.h"
#include "../Handlers/MessageHandler.h"

Cliente::Cliente()
{
}

void Cliente::update() {
	RakNet::Packet *packet;
	RakNet::BitStream bsOut;
	std::string str;
	TPlayer nuevoplayer;
	RakNet::RakNetGUID desconectado;
	
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

				Player *player = new Player(str, peer->GetMyGUID());
				player->cargarContenido();

				nuevoplayer.guid = player->getGuid();
				nuevoplayer.name = player->getName();
				//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
				nuevoplayer.position = Vec3<float> (0,100,0);
				player->setPosition(nuevoplayer.position);

				bsOut.Write(nuevoplayer);
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
				bsOut.Reset();

			}
				break;

			case NUEVO_PLAYER:
			{
				//un player nuevo se ha conectado, y recibo sus datos, tengo que ponerlo en la lista de jugadores

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);

				Enemy *e = new Enemy(nuevoplayer.name, nuevoplayer.guid);
				e->cargarContenido();
				e->setPosition(nuevoplayer.position);
				






			}
			break;

			case NUEVO_CLIENTE:
			{
				//eres un player nuevo, te envian todos los clientes que habian en el server para que tu tambien los tengas

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);

				Enemy *e = new Enemy(nuevoplayer.name, nuevoplayer.guid);
				e->cargarContenido();
				e->setPosition(nuevoplayer.position);




			}
			break;

			case MOVIMIENTO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el player
				bsIn.Read(nuevoplayer);
				//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
				Enemy *e = (Enemy*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
				//e->updateEnemigo(nuevoplayer.position);
				//e = nullptr;

				Message msg1(e, "MOVE", (void*)&nuevoplayer);

				MessageHandler::i().sendMessage(msg1);

			}
			break;

			case DESCONECTADO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				
				bsIn.Read(desconectado);

				EntityManager::i().getRaknetEntity(desconectado)->borrarContenido();
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(desconectado));

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

void Cliente::enviarPos(Player* p) {

	RakNet::BitStream bsOut;
	TPlayer paquetemov;

	bsOut.Write((RakNet::MessageID)MOVIMIENTO);

	paquetemov.guid = p->getGuid();
	paquetemov.name = p->getName();
	//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
	paquetemov.position = p->getRenderState()->getPosition();
	

	bsOut.Write(paquetemov);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}