#include <string.h>
#include <string>
#include <iostream>


#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID


#define MAX_CLIENTS 10
#define SERVER_PORT 65535
typedef struct Entity
{
	std::string nombre;
	float x, y, z;
	int vida;
	int municion;

} TEntity;

enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	MENSAJE_POSICION = ID_USER_PACKET_ENUM + 2,
	MENSAJE_NOMBRE = ID_USER_PACKET_ENUM + 3,
	OBJETO = ID_USER_PACKET_ENUM + 4,
	MOVIMIENTO = ID_USER_PACKET_ENUM + 5
};

int main() {
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	RakNet::Packet *packet;
	int num_conexiones = 0;


	TEntity player1;
	TEntity player2;
	TEntity player3;
	TEntity player4;
	//los guid no pueden estar dentro de la estructura de entity porque luego cuando envies otro paquete desde el cliente se cambia y ya no lo reconoce.
	RakNet::RakNetGUID player1guid;
	RakNet::RakNetGUID player2guid;
	RakNet::RakNetGUID player3guid;
	RakNet::RakNetGUID player4guid;


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
					if (num_conexiones == 0) {
						player1guid = packet->guid;
					}
					else if (num_conexiones == 1) {
						player2guid = packet->guid;
					}
					else if (num_conexiones == 2) {
						player3guid = packet->guid;
					}
					else if (num_conexiones == 3) {
						player4guid = packet->guid;
					}
					num_conexiones++;
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


					
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					if (packet->guid == player1guid) {
						TEntity leido;
						
						bsIn.Read(player1);
						std::cout << "Paquete recibido del PLAYER 1 " << std::endl;
						
						std::cout << "Nombre del player 1: "<< player1.nombre<<std::endl;
						
						std::cout << "Vida: " << player1.vida << std::endl;
						std::cout << "Municion: " << player1.municion << std::endl;
						std::cout << "Posicion: " << player1.x << ", " << player1.y << ", " << player1.z << std::endl;
						std::cout << "" << std::endl;
						
					}
					else if (packet->guid == player2guid) {
						bsIn.Read(player2);
						std::cout << "Paquete recibido del PLAYER 2 " << std::endl;

						std::cout << "Nombre del player 2: " << player2.nombre << std::endl;
						std::cout << "Vida: " << player2.vida << std::endl;
						std::cout << "Municion: " << player2.municion << std::endl;
						std::cout << "Posicion: " << player2.x << ", " << player2.y << ", " << player2.z << std::endl;
						std::cout << "" << std::endl;

					}
					else if (packet->guid == player3guid) {
						bsIn.Read(player3);
						std::cout << "Paquete recibido del PLAYER 3 " << std::endl;
						std::cout << "Nombre del player 3: " << player3.nombre << std::endl;
						std::cout << "Vida: " << player3.vida << std::endl;
						std::cout << "Municion: " << player3.municion << std::endl;
						std::cout << "Posicion: " << player3.x << ", " << player3.y << ", " << player3.z << std::endl;
						std::cout << "" << std::endl;

					}
					else if (packet->guid == player4guid) {
						bsIn.Read(player4);
						std::cout << "Paquete recibido del PLAYER 4 " << std::endl;
						std::cout << "Nombre del player 4: " << player4.nombre << std::endl;
						std::cout << "Vida: " << player4.vida << std::endl;
						std::cout << "Municion: " << player4.municion << std::endl;
						std::cout << "Posicion: " << player4.x << ", " << player4.y << ", " << player4.z << std::endl;
						std::cout << "" << std::endl;

					}else {
						std::cout << "Los guid no coinciden: " << std::endl;
					}
				}
				break;

				case MOVIMIENTO: {
					RakNet::BitStream bsIn(packet->data, packet->length, false);
					RakNet::BitStream bsOut;
					bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
					if (packet->guid == player1guid) {

						//si me llega un movimiento del player 1, actualizo el player uno con el read, y se lo envio al player 2 con el write y el send
						bsIn.Read(player1);

						bsOut.Write((RakNet::MessageID)OBJETO);
						bsOut.Write(player1);
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, player2guid, false);
						//peer->Send((const char*)&player, sizeof(player), HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
						bsOut.Reset();
					}
					if (packet->guid == player2guid) {
						bsIn.Read(player2);

						bsOut.Write((RakNet::MessageID)OBJETO);
						bsOut.Write(player2);
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, player1guid, false);
						//peer->Send((const char*)&player, sizeof(player), HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
						bsOut.Reset();
					}
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