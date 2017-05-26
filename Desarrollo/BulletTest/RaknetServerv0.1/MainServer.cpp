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
#include <NetworkLog.h>
#include <StringCompressor.h>
#include <PacketLogger.h>
#include <GetTime.h>
#include <Timer.h>

#define MAX_CLIENTS 10
#define SERVER_PORT 65535


TGameInfo gameinfo;
NetworkLog networkLog;
RakNet::RakPeerInterface *peer;
RakNet::Packet *packet;

//para controlar el update
Timer* timer;

//Identificador de paquete recibido
unsigned char mPacketIdentifier;



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

void enviarFilaTabla(RakNet::RakNetGUID& rakID, const std::string& name);



void getPackets() {
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
			break;
		}


		case ID_NEW_INCOMING_CONNECTION: {
			printf("Conexion entrante...\n");
			break;
		}


		case ID_DISCONNECTION_NOTIFICATION:
		{

			Entity* ent = EntityManager::i().getRaknetEntity(packet->guid);

			if (ent != nullptr) {
				printf("Un cliente se ha desconectado.\n");

				std::cout << "su nombre es:" << ent->getName() << std::endl;

				//enviamos a todos los clientes el cliente que se ha desconectado para que lo borren
				EntityManager::i().enviaDesconexion(packet->guid, peer);
				//lo borramos de los clientes actuales del servidor
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(packet->guid));

				if (ent->getGuid() == gameinfo.creador) {
					EntityManager::i().enviarTerminarPartida(gameinfo.creador, peer);
				}
			}

			

			break;
		}

		case NUEVO_PLAYER: {

			//Cuando se conecta un nuevo player se crea este en el servidor, se envía a todos los clientes conectados y se añade al vector de clientes

			TPlayer t_player = *reinterpret_cast<TPlayer*>(packet->data);

			//Enviamos el nuevo player a todos los players y le enviamos a ese nuevo player todos los anteriores
			EntityManager::i().sendPlayer(t_player, peer);

			Player *p = new Player(t_player.name, t_player.guid);
			p->setPosition(Vec3<float>(0, 0, 0));



			/*TFilaTabla filaTabla;
			//Cada vez que se conecta un nuevo player se añade una fila a la tabla de este player
			filaTabla.mID = ACTUALIZA_TABLA;
			filaTabla.guid = t_player.guid;
			filaTabla.name = t_player.name;
			filaTabla.kills = 0;
			filaTabla.deaths = 0;
			filaTabla.puntuacion = 0;
			EntityManager::i().enviaFila(peer, filaTabla);*/

			break;
		}


		case NUEVO_BOT: {

			TPlayer t_player = *reinterpret_cast<TPlayer*>(packet->data);

			enviarFilaTabla(t_player.guid, t_player.name);

			//Enviamos el nuevo bot a todos los players menos al host 
			//EntityManager::i().sendPlayer(t_player, peer);
			EntityManager::i().sendBot(t_player, gameinfo.creador, peer);

			Bot *bot = new Bot(t_player.name, t_player.guid);
			bot->setPosition(Vec3<float>(0, 0, 0));
			bot->setAvailable(true);

			break;
		}

		case MOVIMIENTO: {



			unsigned char useTimeStamp; // Assign this to ID_TIMESTAMP
			RakNet::Time timeStamp; // Put the system time in here returned by RakNet::GetTime()
			unsigned char typeId;
			bool isDying;
			bool isOnGround;
			int currentWeapon;
			bool isMoving;
			Vec3<float> position;
			Vec3<float> rotation;
			RakNet::RakNetGUID guid;

			RakNet::BitStream myBitStream(packet->data, packet->length, false); // The false is for efficiency so we don't make a copy of the passed data
			myBitStream.Read(useTimeStamp);
			myBitStream.Read(timeStamp);
			myBitStream.Read(typeId);
			myBitStream.Read(isDying);
			myBitStream.Read(isOnGround);
			myBitStream.Read(currentWeapon);
			myBitStream.Read(isMoving);
			myBitStream.Read(position);
			myBitStream.Read(rotation);
			myBitStream.Read(guid);

			EntityManager::i().enviaNuevaPos(myBitStream, packet->guid, gameinfo.creador, peer);


			

			break;
		}


		case LANZAR_GRANADA: {

			TGranada p_granada = *reinterpret_cast<TGranada*>(packet->data);


			EntityManager::i().lanzarGranda(p_granada, gameinfo.creador, peer);
			break;
		}


		case IMPACTO_BALA: {

			TImpactoBala imp_bala = *reinterpret_cast<TImpactoBala*>(packet->data);

			//notifico a ese cliente que ha sido disparado
			EntityManager::i().enviaDisparado(imp_bala, packet->guid, peer);
			break;

		}


		case APLICAR_IMPULSO: {

			TImpulso impulso = *reinterpret_cast<TImpulso*>(packet->data);

			EntityManager::i().enviaImpulso(impulso, peer);

			break;
		}


		case IMPACTO_ROCKET: {


			TImpactoRocket impact = *reinterpret_cast<TImpactoRocket*>(packet->data);

			//notifico a ese cliente que ha sido disparado
			EntityManager::i().enviaDisparadoRocket(impact, peer);
			break;
		}



		case DISPARAR_BALA: {

			TBala bala = *reinterpret_cast<TBala*>(packet->data);

			//notifico a ese cliente que ha sido disparado
			EntityManager::i().enviarDisparoCliente(bala, gameinfo.creador, peer);
			break;
		}



		case DISPARAR_ROCKET: {

			TBala p_bala = *reinterpret_cast<TBala*>(packet->data);

			//notifico a ese cliente que ha sido disparado
			EntityManager::i().enviarDisparoClienteRocket(p_bala, gameinfo.creador, peer);

			break;
		}

		case MUERTE: {

			RakID p_struct = *reinterpret_cast<RakID*>(packet->data);

			EntityManager::i().notificarMuerte(p_struct, peer);

			break;
		}



		case NUEVA_VIDA: {

			TId idVida = *reinterpret_cast<TId*>(packet->data);

			Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida.id));
			if (vida != NULL) {
				//existe esa vida ya (un cliente que se conecto antes ya la creo)

				//ACLARACION: la vida ya existe se le envia un mensaje a ese cliente de que esa vida ya ha sido creada y si ha sido cogida se le envia el tiempo que queda hasta reaparecer
				//si la vida no ha sida cogida aun no se hace nada porque cuando alguien la coja ya se enviaran los mensajes necesarios
				if (vida->disponible != true) {
					//enviamos un mensaje con el tiempo porque la vida ha sido cogida
					EntityManager::i().enviaTiempoActualVida(vida, packet->guid, peer);
				}


			}
			else {
				//no existe la vida aun (este es el primer cliente que se conecta)
				Life *l = new Life(idVida.id);
			}

			break;
		}

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


			break;
		}


		case VIDA_COGIDA: {

			TId idVida = *reinterpret_cast<TId*>(packet->data);

			idVida.guid = packet->guid;

			Life *vida = static_cast<Life*>(EntityManager::i().getEntityID(idVida.id));
			vida->resetTiempoRecargar();

			EntityManager::i().VidaCogida(idVida, peer);



			break;
		}


		case ARMA_COGIDA: {

			TId idArma = *reinterpret_cast<TId*>(packet->data);

			idArma.guid = packet->guid;

			DropObject *arma = static_cast<DropObject*>(EntityManager::i().getEntityID(idArma.id));
			arma->resetTiempoRecargar();

			EntityManager::i().ArmaCogida(idArma, peer);

			break;
		}


		case ACTUALIZA_TABLA: {

			TKill kill = *reinterpret_cast<TKill*>(packet->data);

			EntityManager::i().aumentaMuerte(kill, peer);

			if (kill.guidDeath != kill.guidKill) {
				//si el jugador que mata es distinto del que muere aumenta la kill, sino aumenta solo la muerte porque te has suicidado
				EntityManager::i().aumentaKill(kill, gameinfo.maxKills, peer);
			}


			break;
		}


		case MOSTRAR_TABLA: {
			break;
		}

		case ID_UNCONNECTED_PING: {
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


			//enviarFilaTabla(rak.creador, rak.name);

			rak.mID = EMPEZAR_PARTIDA;

			//Esto es temporal
			peer->Send((const char*)&rak, sizeof(rak), HIGH_PRIORITY, RELIABLE_ORDERED, 0, p->getGuid(), false);

			break;
		}

		case UNIRSE_PARTIDA:
		{
			TPlayer rak = *reinterpret_cast<TPlayer*>(packet->data);



			//Enviamos el nuevo player a todos los players y le enviamos a ese nuevo player todos los anteriores
			EntityManager::i().sendPlayer(rak, peer);

			Player *p = new Player(rak.name, rak.guid);

			//enviarFilaTabla(rak.guid, rak.name);

			TGameInfo info;
			info.mID = EMPEZAR_PARTIDA;
			info.creador = gameinfo.creador;
			info.map = gameinfo.map;
			info.gameMode = gameinfo.gameMode;
			info.numBots = gameinfo.numBots;
			info.playersTotales = EntityManager::i().getNumJugadores() - 1;
			info.maxKills = gameinfo.maxKills;

			//Esto es temporal
			peer->Send((const char*)&info, sizeof(info), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, p->getGuid(), false);

			break;
		}

		case CARGA_COMPLETA:
		{
			RakID rak = *reinterpret_cast<RakID*>(packet->data);

			Entity* p = EntityManager::i().getRaknetEntity(rak.guid);

			if (p != nullptr) {
				enviarFilaTabla(p->getGuid(), p->getName());

				p->setAvailable(true);
				EntityManager::i().notificarDisponibilidad(rak, peer);
			}


		}


		case SOLICITAR_INFO:
		{


			RakNet::RakString rakString = networkLog.updateAndGenerateTable().c_str();

			RakNet::BitStream w;
			w.Write((RakNet::MessageID)SOLICITAR_INFO);
			w.WriteCompressed(rakString);

			peer->Send(&w, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->guid, false);

			break;
		}
		default:
			printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
			break;
		}

	}
}

void update() {
	//obtener paquetes de los clientes
	getPackets();

	//other stuff
	
}

int main() {
	peer = RakNet::RakPeerInterface::GetInstance();
	//peer->AttachPlugin(&logger);
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	sd.socketFamily = AF_INET;
	timer = new Timer();

	peer->SetOccasionalPing(true);

	peer->Startup(MAX_CLIENTS, &sd, 1);

	std::cout << "Escuchando conexiones en el puerto: " << SERVER_PORT << "\nTu IP es: " << peer->GetLocalIP(0) << std::endl;
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);



	while (1) {
		if (timer->shouldUpdate()) {
			update();
		}
	}

	RakNet::RakPeerInterface::DestroyInstance(peer);
	delete timer;

	return 0;
}


void enviarFilaTabla(RakNet::RakNetGUID& rakID, const std::string& name) {
	TFilaTabla filaTabla;
	//Cada vez que se conecta un nuevo player se añade una fila a la tabla de este player
	filaTabla.mID = ACTUALIZA_TABLA;
	filaTabla.guid = rakID;
	filaTabla.name = name;
	filaTabla.kills = 0;
	filaTabla.deaths = 0;
	filaTabla.puntuacion = 0;

	EntityManager::i().enviaFila(peer, filaTabla);
}