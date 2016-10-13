#include <string.h>
#include <string>
#include <iostream>


#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID
#include "../SFML+Raknet/Player.h"

#define MAX_CLIENTS 10
#define SERVER_PORT 65535
enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	MENSAJE_POSICION = ID_USER_PACKET_ENUM + 2,
	MENSAJE_NOMBRE = ID_USER_PACKET_ENUM + 3,
	NUEVO_PLAYER = ID_USER_PACKET_ENUM + 4,
	GUID_NUESTRO = ID_USER_PACKET_ENUM + 5,
	MOVIMIENTO = ID_USER_PACKET_ENUM + 6,
	LISTA_CLIENTES = ID_USER_PACKET_ENUM + 7
};
void muestraPlayer(Player *p) {

	std::cout << "Nombre del player: " << p->nombre << std::endl;

	std::cout << "Vida: " << p->vida << std::endl;
	std::cout << "Municion: " << p->municion << std::endl;
	std::cout << "Posicion: " << p->posX << ", " << p->posY  << std::endl;
	std::cout << "" << std::endl;
}
int main() {
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	RakNet::Packet *packet;

	std::vector<Player> clientArray;

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
					printf("Another client has disconnected.\n");
					break;
				case ID_REMOTE_CONNECTION_LOST:
					printf("Otro cliente ha perdido la conexion.\n");
					break;
				case ID_REMOTE_NEW_INCOMING_CONNECTION:
					printf("Otro cliente se ha conectado.\n");
					break;
				case ID_CONNECTION_REQUEST_ACCEPTED: {
					printf("Nuestra conexion se ha aceptado.\n");

					
				}
					break;
				case NUEVO_PLAYER: {

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
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, clientArray.at(i).getGuid(), false);
						bsOut.Reset();
					}
					bsOut.Write((RakNet::MessageID)LISTA_CLIENTES);
					bsOut.Write(clientArray);
					peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p->getGuid(), false);
					bsOut.Reset();

					clientArray.push_back(*p);
				}
					break;
				case ID_NEW_INCOMING_CONNECTION:{
					printf("Conexion entrante...\n");

					RakNet::BitStream bsOut;
					bsOut.Write((RakNet::MessageID)GUID_NUESTRO);
					bsOut.Write(packet->guid);
					peer->Send(&bsOut, HIGH_PRIORITY,RELIABLE_ORDERED,0,packet->guid,false);
					bsOut.Reset();
				}

					break;
				case ID_DISCONNECTION_NOTIFICATION:
					printf("Un cliente se ha desconectado.\n");
					break;
				case ID_CONNECTION_LOST:
					printf("Un cliente ha perdido la conexión.\n");
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
				default:
					printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
					break;
			}
		}
	}

	RakNet::RakPeerInterface::DestroyInstance(peer);
	return 0;
}