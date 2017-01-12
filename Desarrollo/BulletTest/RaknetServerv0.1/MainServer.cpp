#include <string.h>
#include <string>
#include <iostream>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID

#include "Entities/Player.h"
#include "Entities/Life.h"
#include "Estructuras.h"
#include "Entities/EntityManager.h"

#define MAX_CLIENTS 10
#define SERVER_PORT 65535



void muestraPlayer(Player *p) {

	std::cout << "Nombre del player: " << p->getName() << std::endl;

	//std::cout << "Vida: " << p->vida << std::endl;
	//std::cout << "Municion: " << p->municion << std::endl;
	std::cout << "Posicion: " << p->getPosition().getX() << ", " << p->getPosition().getY() << std::endl;
	std::cout << "GUID: " << RakNet::RakNetGUID::ToUint32(p->getGuid()) << std::endl;
	std::cout << "ID: " << p->getID() << std::endl;
}

unsigned char getPacketIdentifier(RakNet::Packet * pPacket)
{
	if (pPacket == 0)
		return 255;

	if ((unsigned char)pPacket->data[0] == ID_TIMESTAMP)
	{
		RakAssert(pPacket->length > sizeof(RakNet::MessageID) + sizeof(RakNet::Time));
		return (unsigned char)pPacket->data[sizeof(RakNet::MessageID) + sizeof(RakNet::Time)];
	}
	else
		return (unsigned char)pPacket->data[0];
}



int main() {
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	sd.socketFamily = AF_INET;
	RakNet::Packet *packet;
	RakNet::RakNetGUID guid_Pdisparado;
	TPlayer p_struct;
	TMovimiento movimiento;
	TBala p_bala;
	TImpactoRocket impact;
	TGranada p_granada;
	TImpulso impulso;
	TImpactoBala imp_bala;
	TCambioArma cambioArma;
	TFilaTabla filaTabla;
	Clock tiempoRestartVida;
	TKill kill;
	int idVida=0;
	float danyo = 0;
	

	peer->Startup(MAX_CLIENTS, &sd, 1)==RakNet::RAKNET_STARTED;
	std::cout << "Escuchando conexiones en el puerto: " << SERVER_PORT <<"\nTu IP es: "<< peer->GetLocalIP(0) << std::endl;
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);

	//Identificador de paquete recibido
	unsigned char mPacketIdentifier;

	while (1) {
		//el for recibe un primer paquete, una vez que ya se lo ha guardado tiene que desasignarlo para poder recibir el siguiente por eso el deallocate, luego recibe el siguiente
		//Si no se recibe nada packet = 0 y no se entra al bucle
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			// Recibimos un paquete, tenemos que obtener el tipo de mensaje
			mPacketIdentifier = getPacketIdentifier(packet);

			switch (mPacketIdentifier)
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

				//Cuando se conecta un nuevo player se crea este en el servidor, se env�a a todos los clientes conectados y se a�ade al vector de clientes

				TPlayer t_player = *reinterpret_cast<TPlayer*>(packet->data);
				
				//Enviamos el nuevo player a todos los players y le enviamos a ese nuevo player todos los anteriores
				EntityManager::i().sendPlayer(t_player, peer);

				Player *p = new Player(t_player.name, t_player.guid);
				p->setPosition(t_player.position);

				EntityManager::i().mostrarClientes();

				//Cada vez que se conecta un nuevo player se a�ade una fila a la tabla de este player
				/*filaTabla.guid = t_player.guid;
				filaTabla.name = t_player.name;
				filaTabla.kills = 0;
				filaTabla.deaths = 0;
				filaTabla.puntuacion = 0;
				EntityManager::i().enviaFila(peer, filaTabla);*/

				
			}
			break;
			case ID_NEW_INCOMING_CONNECTION: {
				printf("Conexion entrante...\n");

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
			case MOVIMIENTO: {

				TMovimiento mov = *reinterpret_cast<TMovimiento*>(packet->data);

				EntityManager::i().enviaNuevaPos(mov, peer);
				EntityManager::i().getRaknetEntity(mov.guid)->setPosition(mov.position);

				

			}
			break;

			case LANZAR_GRANADA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(p_granada);

				EntityManager::i().lanzarGranda(p_granada, peer);
				



			}
			break;

			case IMPACTO_BALA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(imp_bala);
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaDisparado(imp_bala, packet->guid, peer);

			}
			break;

			case APLICAR_IMPULSO: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(impulso);
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaImpulso(impulso, peer);

			}
			break;

			case IMPACTO_ROCKET: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				
				bsIn.Read(impact);
				
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaDisparadoRocket(impact, peer);

			}
			break;


			case DISPARAR_BALA: {

				TBala bala = *reinterpret_cast<TBala*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviarDisparoCliente(bala, peer);

			}
			break;


			case DISPARAR_ROCKET: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(p_bala);
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviarDisparoClienteRocket(p_bala, peer);

			}
			break;


			case NUEVA_VIDA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(idVida);
				Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida));
				if (vida != NULL) {
					//existe esa vida ya (un cliente que se conecto antes ya la creo)
					
					//ACLARACION: la vida ya existe se le envia un mensaje a ese cliente de que esa vida ya ha sido creada y si ha sido cogida se le envia el tiempo que queda hasta reaparecer
					//si la vida no ha sida cogida aun no se hace nada porque cuando alguien la coja ya se enviaran los mensajes necesarios
					if (vida->disponible != true) {
						//enviamos un mensaje con el tiempo porque la vida ha sido cogida
						EntityManager::i().enviaTiempoActualVida(vida, packet->guid,peer);		
					}


				}
				else {
					//no existe la vida aun (este es el primer cliente que se conecta)
					Life *l = new Life(idVida);
				}
			}
			break;
			case NUEVA_ARMA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(idVida);
				DropObject *arma = static_cast<DropObject*>(EntityManager::i().getEntityID(idVida));
				if (arma != NULL) {
					//existe esa vida ya (un cliente que se conecto antes ya la creo)

					//ACLARACION: la vida ya existe se le envia un mensaje a ese cliente de que esa vida ya ha sido creada y si ha sido cogida se le envia el tiempo que queda hasta reaparecer
					//si la vida no ha sida cogida aun no se hace nada porque cuando alguien la coja ya se enviaran los mensajes necesarios
					if (arma->disponible != true) {
						//enviamos un mensaje con el tiempo porque la vida ha sido cogida
						EntityManager::i().enviaTiempoActualArma(arma, packet->guid, peer);
					}


				}
				else {
					//no existe la vida aun (este es el primer cliente que se conecta)
					DropObject *d = new DropObject(idVida);
				}



			}
			break;

			case VIDA_COGIDA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(idVida);
				Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida));
				vida->resetTiempoRecargar();

				EntityManager::i().VidaCogida(idVida, peer);




			}
			break;
			case ARMA_COGIDA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);

				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(idVida);
				DropObject *arma = static_cast<DropObject*>(EntityManager::i().getEntityID(idVida));
				EntityManager::i().ArmaCogida(idVida, peer);
			}
			break;
			case CAMBIO_ARMA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(cambioArma);
				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaCambioArma(cambioArma, peer);

			}
			break;
			case MUERTE: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo la estructura del cliente que ha muerto
				bsIn.Read(p_struct);
				//notifico a todos que ese cliente a muerto
				EntityManager::i().notificarMuerte(p_struct, peer);

			}
			break;

			case ACTUALIZA_TABLA: {

				RakNet::BitStream bsIn(packet->data, packet->length, false);


				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el guid del cliente que ha sido disparado
				bsIn.Read(kill);
				EntityManager::i().aumentaMuerte(kill.guidDeath, peer);
				if (kill.guidDeath != kill.guidKill) {
					//si el jugador que mata es distinto del que muere aumenta la kill, sino aumenta solo la muerte porque te has suicidado
					EntityManager::i().aumentaKill(kill.guidKill, peer);	
				}
				
				

			}
			break;

			case MOSTRAR_TABLA: {

			}
			break;
			case ID_UNCONNECTED_PING:{
				printf("Ping...Pong\n");
				break;
			}
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;
			}
			
		}
	}

	RakNet::RakPeerInterface::DestroyInstance(peer);
	return 0;
}
