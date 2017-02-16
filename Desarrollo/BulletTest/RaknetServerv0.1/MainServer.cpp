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
#include <Bot.h>

#define MAX_CLIENTS 10
#define SERVER_PORT 65535


TGameInfo gameinfo;


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

	

	peer->Startup(MAX_CLIENTS, &sd, 1);

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

			case ID_NEW_INCOMING_CONNECTION: {
				printf("Conexion entrante...\n");

			}

			break;
			case ID_DISCONNECTION_NOTIFICATION:
			{

				Entity* ent = EntityManager::i().getRaknetEntity(packet->guid);

				printf("Un cliente se ha desconectado.\n");

				std::cout << "su nombre es:" << ent->getName() << std::endl;

				//enviamos a todos los clientes el cliente que se ha desconectado para que lo borren
				EntityManager::i().enviaDesconexion(packet->guid, peer);
				//lo borramos de los clientes actuales del servidor
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(packet->guid));

				break;
			}

			case NUEVO_PLAYER: {

				//Cuando se conecta un nuevo player se crea este en el servidor, se envía a todos los clientes conectados y se añade al vector de clientes

				TPlayer t_player = *reinterpret_cast<TPlayer*>(packet->data);

				//Enviamos el nuevo player a todos los players y le enviamos a ese nuevo player todos los anteriores
				EntityManager::i().sendPlayer(t_player, peer);

				Player *p = new Player(t_player.name, t_player.guid);
				p->setPosition(t_player.position);

				EntityManager::i().mostrarClientes();

				TFilaTabla filaTabla;
				//Cada vez que se conecta un nuevo player se añade una fila a la tabla de este player
				filaTabla.mID = ACTUALIZA_TABLA;
				filaTabla.guid = t_player.guid;
				filaTabla.name = t_player.name;
				filaTabla.kills = 0;
				filaTabla.deaths = 0;
				filaTabla.puntuacion = 0;
				EntityManager::i().enviaFila(peer, filaTabla);


			}
			break;

			case NUEVO_BOT: {

				TPlayer t_player = *reinterpret_cast<TPlayer*>(packet->data);

				//Enviamos el nuevo bot a todos los players menos al host y le enviamos a ese nuevo player todos los anteriores
				//EntityManager::i().sendPlayer(t_player, peer);
				EntityManager::i().sendBot(t_player, gameinfo.creador, peer);

				Bot *bot = new Bot(t_player.name, t_player.guid);
				bot->setPosition(t_player.position);

				break;
			}

			case MOVIMIENTO: {

				TMovimiento mov = *reinterpret_cast<TMovimiento*>(packet->data);
				EntityManager::i().enviaNuevaPos(mov, gameinfo.creador, peer);
				Entity* ent = EntityManager::i().getRaknetEntity(mov.guid);

				if (ent != NULL) {
					ent->setPosition(mov.position);
				}
				

			}
			break;

			case LANZAR_GRANADA: {

				TGranada p_granada = *reinterpret_cast<TGranada*>(packet->data);


				EntityManager::i().lanzarGranda(p_granada, gameinfo.creador, peer);

			}
			break;

			case IMPACTO_BALA: {

				TImpactoBala imp_bala = *reinterpret_cast<TImpactoBala*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaDisparado(imp_bala, packet->guid, peer);

			}
			break;

			case APLICAR_IMPULSO: {

				TImpulso impulso = *reinterpret_cast<TImpulso*>(packet->data);

				EntityManager::i().enviaImpulso(impulso, peer);

			}
			break;

			case IMPACTO_ROCKET: {


				TImpactoRocket impact = *reinterpret_cast<TImpactoRocket*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaDisparadoRocket(impact, peer);

			}
			break;


			case DISPARAR_BALA: {

				TBala bala = *reinterpret_cast<TBala*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviarDisparoCliente(bala, gameinfo.creador, peer);

			}
			break;


			case DISPARAR_ROCKET: {

				TBala p_bala = *reinterpret_cast<TBala*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviarDisparoClienteRocket(p_bala, gameinfo.creador, peer);

			}
			break;
			case MUERTE: {

				TPlayer p_struct = *reinterpret_cast<TPlayer*>(packet->data);

				EntityManager::i().notificarMuerte(p_struct, peer);


			}
			break;


			case NUEVA_VIDA: {

				TId idVida = *reinterpret_cast<TId*>(packet->data);

				Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida.id));
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
					Life *l = new Life(idVida.id);
				}
			}
			break;
			case NUEVA_ARMA: {

				TId idArma = *reinterpret_cast<TId*>(packet->data);


				DropObject *arma = static_cast<DropObject*>(EntityManager::i().getEntityID(idArma.id));
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
					DropObject *d = new DropObject(idArma.id);
				}



			}
			break;

			case VIDA_COGIDA: {

				TId idVida = *reinterpret_cast<TId*>(packet->data);

				idVida.guid = packet->guid;

				Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida.id));
				vida->resetTiempoRecargar();

				EntityManager::i().VidaCogida(idVida, peer);




			}
			break;

			case ARMA_COGIDA: {

				TId idArma = *reinterpret_cast<TId*>(packet->data);

				idArma.guid = packet->guid;

				DropObject *arma = static_cast<DropObject*>(EntityManager::i().getEntityID(idArma.id));
				arma->resetTiempoRecargar();

				EntityManager::i().ArmaCogida(idArma, peer);
			}
			break;

			case CAMBIO_ARMA: {

				TCambioArma cambioArma = *reinterpret_cast<TCambioArma*>(packet->data);

				//notifico a ese cliente que ha sido disparado
				EntityManager::i().enviaCambioArma(cambioArma, peer);

			}
			break;
			

			case ACTUALIZA_TABLA: {

				TKill kill = *reinterpret_cast<TKill*>(packet->data);

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

			case SYNC:
			{
				TSyncMessage sync = *reinterpret_cast<TSyncMessage*>(packet->data);
				
				EntityManager::i().enviaSync(peer, sync);
				break;
			}
			case PING:
			{
				TPing ping = *reinterpret_cast<TPing*>(packet->data);
				peer->Send((const char*)&ping, sizeof(ping), HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->guid, false);

				break;
			}
			case CREAR_PARTIDA:
			{
				TGameInfo rak = *reinterpret_cast<TGameInfo*>(packet->data);

				gameinfo = rak;


				Player *p = new Player(rak.name, rak.creador);


				EntityManager::i().empezarPartida(peer, rak);

				break;
			}

			case UNIRSE_PARTIDA:
			{
				TPlayer rak = *reinterpret_cast<TPlayer*>(packet->data);

				Player *p = new Player(rak.name, rak.guid);

				//Enviamos el nuevo player a todos los players y le enviamos a ese nuevo player todos los anteriores
				EntityManager::i().sendPlayer(rak, peer);

				TGameInfo info;
				info.mID = EMPEZAR_PARTIDA;
				info.creador = gameinfo.creador;
				info.map = gameinfo.map;
				info.gameMode = gameinfo.gameMode;
				info.numBots = gameinfo.numBots;
			

				//Esto es temporal
				peer->Send((const char*)&info, sizeof(info), HIGH_PRIORITY, RELIABLE_ORDERED, 0, p->getGuid(), false);

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
