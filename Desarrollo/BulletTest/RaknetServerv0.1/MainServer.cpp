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
	std::cout << "GUID: " << RakNet::RakNetGUID::ToUint32(p->getGuid()) << std::endl;
	std::cout << "ID: " << p->getID() << std::endl;
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
	RakNet::RakNetGUID guid_Pdisparado;
	TPlayer p_struct;
	
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

			case NUEVO_PLAYER: {

				//Cuando se conecta un nuevo player se crea este en el servidor, se envía a todos los clientes conectados y se añade al vector de clientes

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				
				bsIn.Read(p_struct);
				
				//RakNet::BitStream bsOut;
				
				EntityManager::i().sendPlayer(p_struct, peer);

				Player *p = new Player(p_struct.name, p_struct.guid);
				p->getRenderState()->setPosition(p_struct.position);
				EntityManager::i().mostrarClientes();
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
				std::cout << "su nombre es:" << EntityManager::i().getRaknetEntity(packet->guid)->getName() << std::endl;
				break;
			case ID_CONNECTION_LOST: {

				printf("Un cliente se ha desconectado.\n");
				std::cout << "su nombre es:" << EntityManager::i().getRaknetEntity(packet->guid)->getName() << std::endl;
				//enviamos a todos los clientes el cliente que se ha desconectado para que lo borren
				EntityManager::i().enviaDesconexion(packet->guid, peer);
				//lo borramos de los clientes actuales del servidor
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(packet->guid));

			}
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
			case DESCONECTADO:
			{

				/*RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				std::cout << "HOLAAAAAAAAA ME VOY" << std::endl;
				printf("Un cliente se ha desconectado.\n");
				std::cout << "su nombre es:" << EntityManager::i().getRaknetEntity(packet->guid)->getName() << std::endl;
				//enviamos a todos los clientes el cliente que se ha desconectado para que lo borren
				EntityManager::i().enviaDesconexion(packet->guid, peer);
				//lo borramos de los clientes actuales del servidor
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(packet->guid));*/
			}
			break;
			case MOVIMIENTO: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				RakNet::BitStream bsOut;
				
				
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(p_struct);

				EntityManager::i().enviaNuevaPos(p_struct, peer);
				EntityManager::i().getRaknetEntity(p_struct.guid)->getRenderState()->setPosition(p_struct.position);

				

			}

							 break;

			case IMPACTO_BALA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				RakNet::BitStream bsOut;


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(guid_Pdisparado);
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaDisparado(guid_Pdisparado, peer);

			}

							 break;


			case MUERTE: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				RakNet::BitStream bsOut;


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo la estructura del cliente que ha muerto
				bsIn.Read(p_struct);
				//primero le cambio la posicion a ese player (le respawneo)
				//TODO:aqui le asigno una posicion en una esquina del tablero ese raro que tenemos pero luego el servidor se tendra que encargar de poner posicion de respawneo buenas.
				p_struct.position = Vec3<float>(900.f, 100.f, 900.f);
				//notifico a todos que ese cliente a muerto
				EntityManager::i().notificarMuerte(p_struct, peer);

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