#include <string.h>
#include <string>
#include <iostream>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID

#include "Entities\Player.h"
#include "Estructuras.h"
#include "Entities\EntityManager.h"

#define MAX_CLIENTS 10
#define SERVER_PORT 65535



void muestraPlayer(Player *p) {

	std::cout << "Nombre del player: " << p->getName() << std::endl;

	//std::cout << "Vida: " << p->vida << std::endl;
	//std::cout << "Municion: " << p->municion << std::endl;
	std::cout << "Posicion: " << p->getRenderState()->getPosition().getX() << ", " << p->getRenderState()->getPosition().getY() << std::endl;
	std::cout << "" << std::endl;
}

/*void updatePlayer(int movimiento, Player *p) {
	//si esto no funciona, es decir, el player no se mueve tendriamos que hacerlos con setPosition para que se actualizaran las variables del player 
	if (movimiento == 1) {
		p->posicion.y = p->posicion.y -2.f;
	}
	if (movimiento == 2) {
		p->posicion.x = p->posicion.x - 2.f;
	}
	if (movimiento == 3) {
		p->posicion.x = p->posicion.x + 2.f;
	}
	if (movimiento == 4) {
		p->posicion.y = p->posicion.y + 2.f;
	}
}*/

int main() {
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	RakNet::Packet *packet;
	//std::vector<Player*> clientArray;

	peer->Startup(MAX_CLIENTS, &sd, 1);

	std::cout << "Creando el servidor en el puerto "<< SERVER_PORT << std::endl;
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);

	while (1) {
		//el for recibe un primer paquete, una vez que ya se lo ha guardado tiene que desasignarlo para poder recibir el siguiente por eso el deallocate, luego recibe el siguiente
		//Si no se recibe nada packet = 0 y no se entra al bucle
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			switch (packet->data[0])
			{
			case ID_REMOTE_DISCONNECTION_NOTIFICATION:
				printf("vfdvdvdAnother client has disconnected.\n");
				break;
			case ID_REMOTE_CONNECTION_LOST:
				printf("vfdvdvdOtro cliente ha perdido la conexion.\n");
				break;
			case ID_REMOTE_NEW_INCOMING_CONNECTION:
				printf("vdfvdvOtro cliente se ha conectado.\n");
				break;
			case ID_CONNECTION_REQUEST_ACCEPTED: {
				printf("vfdvdvdNuestra conexion se ha aceptado.\n");


			}
												 break;
												 /*case NUEVO_PLAYER: {

													 //Cuando se conecta un nuevo player se crea este en el servidor, se envía a todos los clientes conectados y se añade al vector de clientes

													 RakNet::BitStream bsIn(packet->data,packet->length,false);
													 bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
													 Player *p = new Player();
													 bsIn.Read(*p);
													 muestraPlayer(p);
													 RakNet::BitStream bsOut;
													 for (int i = 0; i < clientArray.size(); i++) {
														 bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);
														 bsOut.Write(*p);
														 peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, clientArray.at(i)->getGuid(), false);
														 bsOut.Reset();
													 }
													 bsOut.Write((RakNet::MessageID)LISTA_CLIENTES);
													 bsOut.Write(clientArray);
													 peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p->getGuid(), false);
													 bsOut.Reset();

													 clientArray.push_back(p);
												 }
													 break;*/
			case NUEVO_PLAYER: {

				//Cuando se conecta un nuevo player se crea este en el servidor, se envía a todos los clientes conectados y se añade al vector de clientes

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				/*TODO*///////////////////////////////////////////////////////////////////////////////////////////
				//Desde el cliente enviar la misma estructura cuando envie un mensaje con nuevo player al servidor
				/////////////////////////////////////////////////////////////////////////////////////////////////
				TPlayer p_struct;
				bsIn.Read(p_struct);
				//muestraPlayer(p);
				RakNet::BitStream bsOut;

				EntityManager::i().sendPlayer(p_struct, peer);

				Player *p = new Player();
				p->setGUID(p_struct.guid);
			}
							   break;
			case ID_NEW_INCOMING_CONNECTION: {
				printf("Conexion entrante...\n");

				//TODO: aqui podriamos ponerle la nueva posicion al cliente.
				/*RakNet::BitStream bsOut;
				bsOut.Write((RakNet::MessageID)GUID_NUESTRO);
				bsOut.Write(packet->guid);
				peer->Send(&bsOut, HIGH_PRIORITY,RELIABLE_ORDERED,0,packet->guid,false);
				bsOut.Reset();*/
			}

											 break;
			case ID_DISCONNECTION_NOTIFICATION:
				printf("Un cliente se ha desconectado.\n");
				break;
			case ID_CONNECTION_LOST: {
				/*printf("Un cliente ha perdido la conexión.\n");
				RakNet::BitStream bsOut;
				Player *p = new Player();
				int i = 0;
				for (i = 0; i < clientArray.size(); i++) {
					if (clientArray.at(i)->getGuid() == packet->guid) {
						p = clientArray.at(i);

						break;
					}
				}
				for (int j = 0; j < clientArray.size(); j++) {
					if (j!=i) {
						bsOut.Write((RakNet::MessageID)ELIMINAR_CLIENTE);
						bsOut.Write(*p);
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, clientArray.at(j)->getGuid(), false);
						bsOut.Reset();
					}
				}
				clientArray.erase(clientArray.begin()+i);

				std::cout << "" << std::endl;
				std::cout << "LISTA DE CLIENTES" << std::endl;
				std::cout << "Num.Clientes: " << clientArray.size() << std::endl;
				for (int i = 0; i < clientArray.size(); i++) {
					std::cout << "Cliente " << i << ": " << clientArray.at(i)->nombre << std::endl;
					std::cout << "Pos: " << clientArray.at(i)->getPos().x << ", " << clientArray.at(i)->getPos().y << std::endl;
				}

				//delete p;
			}
				*/
				break;
			case ID_GAME_MESSAGE_1:
			{
				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				RakNet::RakString stringEntrante;
				bsIn.Read(stringEntrante);

				std::cout << stringEntrante.C_String() << std::endl;
			}
			break;
			case MENSAJE_POSICION:
			{
				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				float x, y, z;
				bsIn.ReadFloat16(x, 0, 9);
				bsIn.ReadFloat16(y, 0, 9);
				bsIn.ReadFloat16(z, 0, 9);
				std::cout << x << ", " << y << ", " << z << std::endl;
			}

			break;
			case MENSAJE_NOMBRE:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				RakNet::RakString stringEntrante;
				bsIn.Read(stringEntrante);

				std::cout << stringEntrante.C_String() << std::endl;
			}
			break;
			case MOVIMIENTO: {

				/*RakNet::BitStream bsIn(packet->data, packet->length, false);
				RakNet::BitStream bsOut;
				int movimiento = 0;
				int pos=0;
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(movimiento);
				if (movimiento!=0) {

					for (int i = 0; i < clientArray.size(); i++) {
						if (packet->guid == clientArray.at(i)->getGuid()) {
							pos = i;
							break;
						}
					}
					//Player *p = new Player();
					//p = clientArray.at(pos);

					updatePlayer(movimiento, clientArray.at(pos));

					Tposicion posicionEnviar = clientArray.at(pos)->getPos();
					RakNet::RakNetGUID elguid = clientArray.at(pos)->getGuid();

					for (int i = 0; i < clientArray.size(); i++) {
						//Enviamos una copia del player a todos los demas
						bsOut.Write((RakNet::MessageID)ACTUALIZA_CLIENTE);

						//UPDATE
						bsOut.Write(elguid);
						bsOut.Write(posicionEnviar);
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, clientArray.at(i)->getGuid(), false);
						bsOut.Reset();
					}
					clientArray.at(pos)->restablecerMovimiento();
				}*/

			}

							 break;
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;
			}
			}
		}
	}

	RakNet::RakPeerInterface::DestroyInstance(peer);
	return 0;
}