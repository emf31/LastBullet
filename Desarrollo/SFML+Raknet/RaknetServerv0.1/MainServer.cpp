#include <string.h>
#include <iostream>


#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID


#define MAX_CLIENTS 10
#define SERVER_PORT 65535
enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	MENSAJE_POSICION = ID_USER_PACKET_ENUM + 2,
	MENSAJE_NOMBRE = ID_USER_PACKET_ENUM + 3,
	OBJETO = ID_USER_PACKET_ENUM + 4
};

int main() {
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	RakNet::Packet *packet;

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
				case ID_CONNECTION_REQUEST_ACCEPTED:
					printf("Nuestra conexion se ha aceptado.\n");
					break;
				case ID_NEW_INCOMING_CONNECTION:
					printf("Conexion entrante...\n");
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

				case OBJETO:
				{
					typedef struct Entity
					{
						float x, y, z;
						int vida;
						int municion;
					} TEntity;

					TEntity player;
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					bsIn.Read(player);

					std::cout<< "Vida: " << player.vida << std::endl;
					std::cout << "Municion: " << player.municion << std::endl;
					std::cout << "Posicion: " << player.x << ", "<< player.y << ", "<< player.z << std::endl;
					std::cout << "" << std::endl;

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