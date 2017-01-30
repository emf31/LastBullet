
#include <iostream>
#include <string>
#include <chrono>
#include <RakNetTime.h>
#include <RakSleep.h>
#include "Cliente.h"
#include "Estructuras.h"
#include <EntityManager.h>
#include "../Entities/Entity.h"
#include "../Entities/Enemy.h"
#include <Player.h>
#include <Message.h>
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include "../Entities/GunBullet.h"
#include "../Entities/LifeObject.h"
#include "../Entities/WeaponDrops/WeaponDrop.h"
#include "../Entities/WeaponDrops/AsaltoDrop.h"
#include "../Entities/RocketBulletEnemy.h"
#include <events/PlayerEvent.h>
#include <events/KillEvent.h>
#include <events/MuerteEvent.h>
#include <GetTime.h>

Cliente::Cliente() /*: lobby(peer)*/
{
}



void Cliente::update(Time elapsedTime) {

	
	TPing ping;
	//cogemos el tiempo cuando enviamos para restar el tiempo de cuando recibimos-enviamos y a esto le restamos el tiempo del update y tendriamos el ping
	duracionFor = timeFor.getElapsedTime().asMilliseconds();
	timeFor.restart();
	ping.ping = RakNet::GetTimeMS();
	//Enviamos ping cada update
	dispatchMessage(ping, PING);

	//pingServer();

	if (resetBarTime.getElapsedTime().asSeconds() >= 5) {
		resetBar();
		resetBarTime.restart();
		//pingServer();
	}
	countMovimiento = 0;
	for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
		
		
		// Recibimos un paquete, tenemos que obtener el tipo de mensaje
		mPacketIdentifier = getPacketIdentifier(packet);


		switch (mPacketIdentifier) {
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
			servidorAdr = packet->systemAddress;


			//Esta variable indica que el servidor a aceptado la conexion
			conectado = true;


		}
											 break;

		case NUEVO_PLAYER:
		{
			//un player nuevo se ha conectado, y recibo sus datos, tengo que ponerlo en la lista de jugadores

			TPlayer p = *reinterpret_cast<TPlayer*>(packet->data);

			Enemy *e = new Enemy(p.name, p.guid);
			e->inicializar();
			e->cargarContenido();
			e->setPosition(p.position);
			EntityManager::i().mostrarClientes();


		}
		break;

		case NUEVO_CLIENTE:
		{
			//eres un player nuevo, te envian todos los clientes que habian en el server para que tu tambien los tengas

			TPlayer p = *reinterpret_cast<TPlayer*>(packet->data);


			Enemy *e = new Enemy(p.name, p.guid);
			e->inicializar();
			e->cargarContenido();
			e->setPosition(p.position);
			EntityManager::i().mostrarClientes();

			
			
			

		}
		break;
		case MOVIMIENTO:
		{
			TMovimiento m = *reinterpret_cast<TMovimiento*>(packet->data);

			//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
			Enemy *e = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(m.guid));

			if (e != NULL) {
				e->encolaMovimiento(m);
			}
			countMovementPacketsIn++;
			sendSyncPackage(m.guid, mPacketIdentifier);
		}
		break;


		case DESCONECTADO:
		{
			RakID rakID = *reinterpret_cast<RakID*>(packet->data);

			EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(rakID.guid));


		}
		break;

		case DISPARAR_BALA:
		{
			TBala balaDisparada = *reinterpret_cast<TBala*>(packet->data);

			GunBullet* bala = new GunBullet(balaDisparada.position, balaDisparada.direction, balaDisparada.finalposition, balaDisparada.rotation);
			bala->cargarContenido();

			sendSyncPackage(balaDisparada.guid, mPacketIdentifier);
		}
		break;
		case IMPACTO_BALA:
		{

			TImpactoBala bala = *reinterpret_cast<TImpactoBala*>(packet->data);

			//nos guardamos el guid de quien dispara por si mata al jugador poder actualizar la tabla

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent().restaVida(bala.damage, bala.guid);
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojSangre.restart();

			sendSyncPackage(bala.guid, mPacketIdentifier);

		}
		break;

		case DISPARAR_ROCKET:
		{
			TBala balaDisparada = *reinterpret_cast<TBala*>(packet->data);

			RocketBulletEnemy* balaRocket = new RocketBulletEnemy(balaDisparada.position, balaDisparada.direction, balaDisparada.rotation);

			sendSyncPackage(balaDisparada.guid, mPacketIdentifier);

		}
		break;

		case IMPACTO_ROCKET:
		{
			TImpactoRocket impacto = *reinterpret_cast<TImpactoRocket*>(packet->data);

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			//le pasamos el damage causado por el rocket y el guid del jugador que lo disparo, para que si lo mata pueda apuntarse un punto
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent().restaVida(impacto.damage, impacto.guidDisparado);
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojSangre.restart();

			sendSyncPackage(impacto.guidDisparado, mPacketIdentifier);
		}
		break;

		case LANZAR_GRANADA:
		{
			TGranada granada = *reinterpret_cast<TGranada*>(packet->data);

			Enemy* ent = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(granada.guid));
			ent->lanzarGranada(granada);

			sendSyncPackage(granada.guid, mPacketIdentifier);
		}
		break;

		case APLICAR_IMPULSO:
		{

			TImpulso imp = *reinterpret_cast<TImpulso*>(packet->data);

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			Player* player = (Player*)EntityManager::i().getEntity(PLAYER);
			player->impulsar(imp.fuerza);

			sendSyncPackage(imp.guid, mPacketIdentifier);
		}
		break;

		case NUEVA_VIDA:
		{
			TDropServer vidaServer = *reinterpret_cast<TDropServer*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			LifeObject *v = static_cast<LifeObject*>(EntityManager::i().getEntity(vidaServer.id));
			v->asignaTiempo(vidaServer.tiempo);


		}
		break;

		case NUEVA_ARMA:
		{
			TDropServer armaServer = *reinterpret_cast<TDropServer*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			WeaponDrop *v = static_cast<WeaponDrop*>(EntityManager::i().getEntity(armaServer.id));
			v->asignaTiempo(armaServer.tiempo);

		}
		break;

		case ARMA_COGIDA:
		{
			TId idArma = *reinterpret_cast<TId*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			WeaponDrop *w = static_cast<WeaponDrop*>(EntityManager::i().getEntity(idArma.id));
			w->ArmaCogida();

			sendSyncPackage(idArma.guid, mPacketIdentifier);
		}
		break;

		case VIDA_COGIDA:
		{

			TId idVida = *reinterpret_cast<TId*>(packet->data);
			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			//TODO esto peta por todos lados, enviar un mensaje a la entity y que haga ella el reesto
			LifeObject *v = static_cast<LifeObject*>(EntityManager::i().getEntity(idVida.id));
			v->VidaCogida();

			sendSyncPackage(idVida.guid, mPacketIdentifier);
		}
		break;

		case MUERTE:
		{
			TPlayer nuevoplayer = *reinterpret_cast<TPlayer*>(packet->data);

			if (EntityManager::i().getRaknetEntity(nuevoplayer.guid)->getID() == PLAYER) {
				//es el player
				Player* player = (Player*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
				player->resetAll();

			}
			else {
				//es un enemigo
				Enemy* enemigo = (Enemy*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);

			}
			sendSyncPackage(nuevoplayer.guid, mPacketIdentifier);
		}
		break;
		case ACTUALIZA_TABLA:
		{
			TFilaTabla nuevaFila = *reinterpret_cast<TFilaTabla*>(packet->data);

			PlayerEvent evento(nuevaFila);

			notify(evento);

			//EntityManager::i().cambiaTabla(nuevaFila);

		}
		break;
		case AUMENTA_KILL:
		{
			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			KillEvent evento(guidTabla.guid);

			notify(evento);

			sendSyncPackage(guidTabla.guid, mPacketIdentifier);

			//EntityManager::i().aumentaKill(guidTabla.guid);

		}
		break;

		case AUMENTA_MUERTE:
		{

			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			MuerteEvent evento(guidTabla.guid);

			notify(evento);

			sendSyncPackage(guidTabla.guid, mPacketIdentifier);
			//EntityManager::i().aumentaMuerte(guidTabla.guid);

		}
		break;


		case CAMBIO_ARMA:
		{
			TCambioArma t_cambioArma = *reinterpret_cast<TCambioArma*>(packet->data);

			if (t_cambioArma.cambio == 1) {
				Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMAUP", NULL);
				MessageHandler::i().sendMessage(msg1);
			}
			else {
				Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMADOWN", NULL);
				MessageHandler::i().sendMessage(msg1);
			}

		}
		break;


		case FIN_PARTIDA:
		{

			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			Event ev;
			ev.event_type = E_FIN_PARTIDA;

			//Notificamos al HUD que es el fin de la partida
			notify(ev);


		}
		break;

		case ID_UNCONNECTED_PONG:
		{
			RakNet::TimeMS time;
			RakNet::BitStream bsIn(packet->data, packet->length, false);
			bsIn.IgnoreBytes(1);
			bsIn.Read(time);
			//printf("Got pong from %s with time %i\n", packet->systemAddress.ToString(), RakNet::GetTimeMS() - time);
			break;
		}

		case SYNC:
		{
			//Sync
			TSyncMessage sync = *reinterpret_cast<TSyncMessage*>(packet->data);
			/*std::cout << "Sync packet from: " << RakNet::RakNetGUID::ToUint32(sync.origen) << std::endl;
			std::cout << "Message type: " << (unsigned int)sync.packageType << std::endl;*/
			//std::cout << windowsPacketOpen << std::endl;

			Enemy *e = dynamic_cast<Enemy*> (EntityManager::i().getRaknetEntity(sync.origen));
			if (e != NULL){
				e->lastSyncPacket.restart();
				if (sync.packageType != MOVIMIENTO && windowsPacketOpen) {
					e->setVisibilidadBilboardSync();
				}
			}
			
			switch (sync.packageType) {
			case MOVIMIENTO:
			{
				countMovimiento++;
				break;
			}
			case DISPARAR_BALA:
			{
				countDisparo++;
				break;
			}
			case DISPARAR_ROCKET:
			{
				countDisparo++;
				break;
			}
			case IMPACTO_BALA:
			{
				countImpacto++;

				break;
			}
			case IMPACTO_ROCKET:
			{
				countImpacto++;
				break;
			}
			case VIDA_COGIDA:
			{
				countDropVida++;
				break;
			}
			case ARMA_COGIDA:
			{
				countDropArma++;
				break;
			}
			case MUERTE:
			{
				countMuerte++;
				break;
			}
			case LANZAR_GRANADA:
			{
				countGranada++;
				break;
			}
			case AUMENTA_KILL:
			{
				countAumentaKill++;
				break;
			}
			case AUMENTA_MUERTE:
			{
				countAumentaMuerte++;
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case PING:
		{
			//Ping
			
			TPing pingStruct = *reinterpret_cast<TPing*>(packet->data);
			//+1 milisegundo que tarda en hacer el for
			pingMS = RakNet::GetTimeMS() - pingStruct.ping - duracionFor+1;

			break;
		}
		default:
			printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
			break;

		}
		if (mPacketIdentifier != MOVIMIENTO && mPacketIdentifier != SYNC && mPacketIdentifier != PING)
			countPacketsIn++;

		//std::cout << (unsigned int)mPacketIdentifier << std::endl;

	}
	
	
	countPacketsTotal = countPacketsIn + countPacketsOut;
	countMovementPacketsTotal = countMovementPacketsIn + countMovementPacketsOut;
	duracionFor = timeFor.getElapsedTime().asMilliseconds();
	//pingMS = pingMS - (elapsedTime.asMilliseconds() - duracionFor);
	//pingMS = duracionFor;
	timeFor.restart();

}

void Cliente::inicializar() {
	conectado = false;
	char eleccion;
	int elec;
	std::string str;
	resetBarTime.restart();

	do {
		searchServersOnLAN();

		//Lista de servidores en la red
		std::cout << m_servers.size() << " servidor(es) encontrado(s): " << std::endl;
		for (std::size_t i = 0; i < m_servers.size(); ++i) {
			std::cout << "\t[" << i << "] - " << m_servers.at(i) << std::endl;
		}
		std::cout << "\t[a] - Actualizar" << std::endl;
		std::cout << "\t[m] - Introducir IP manualmente" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> eleccion;
		if (eleccion != 'a' && eleccion != 'm') {
			elec = eleccion - '0';
			std::string ipConPuerto = m_servers.at((elec));
			std::string ip = ipConPuerto.substr(0, ipConPuerto.find("|"));
			str = ip;
		}
		else if (eleccion == 'm') {
			printf("Introduce la IP \n");
			std::cin >> str;
			if (str != "a") {
				break;
			}
			else {
				eleccion = 'a';
			}
		}
	} while (eleccion == 'a');


	//Nos conectamos a la lobby del servidor
	//lobby.join(str, SERVER_PORT);

	conectar(str, SERVER_PORT);

}

void Cliente::conectar(std::string address, int port) {
	peer = RakNet::RakPeerInterface::GetInstance();
	peer->AllowConnectionResponseIPMigration(false);
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);
	peer->SetOccasionalPing(true);

}

Player* Cliente::createPlayer() {



	printf("Introduce un nombre \n");
	std::cin >> str;


	Player *player = new Player(str, peer->GetMyGUID());
	player->inicializar();
	player->cargarContenido();

	TPlayer nuevoplayer;
	nuevoplayer.guid = player->getGuid();
	nuevoplayer.name = player->getName();

	dispatchMessage(nuevoplayer, NUEVO_PLAYER);
	//peer->Send((const char*)&nuevoplayer, sizeof(nuevoplayer), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, servidor, false);

	return player;

}



void Cliente::searchServersOnLAN() {
	//Creo un RakPeer para lanzar un paquete de b�squeda
	RakNet::RakPeerInterface *client;
	client = RakNet::RakPeerInterface::GetInstance();

	RakNet::SocketDescriptor socketDescriptor(65534, 0);
	socketDescriptor.socketFamily = AF_INET;

	client->Startup(1, &socketDescriptor, 1);

	//Hacemos ping a bradcast en el puerto en el que sabemos que est� escuchando el server
	client->Ping("255.255.255.255", 65535, false);
	std::cout << "Buscando servidores en la red local..." << std::endl;
	RakSleep(1000);
	RakNet::Packet *packet;
	//Limpiamos la lista de servidores primero.
	m_servers.clear();

	for (packet = client->Receive(); packet; client->DeallocatePacket(packet), packet = client->Receive()) {
		if (packet == 0) {
			RakSleep(1000);
			continue;
		}
		if (packet->data[0] == ID_UNCONNECTED_PONG) {
			RakNet::TimeMS time;
			RakNet::BitStream bsIn(packet->data, packet->length, false);

			bsIn.IgnoreBytes(1);
			bsIn.Read(time);
			//printf("Ping is %i\n", (unsigned int)(RakNet::GetTimeMS() - time));
			m_servers.push_back(packet->systemAddress.ToString());
		}

		RakSleep(1000);
	}
	//Destruyo el RakPeer. Ya no hace falta
	RakNet::RakPeerInterface::DestroyInstance(client);
}


void Cliente::apagar() {

	conectado = false;

	//shut down the client
	peer->Shutdown(300);
	//and end the connection
	RakNet::RakPeerInterface::DestroyInstance(peer);

}

unsigned char Cliente::getPacketIdentifier(RakNet::Packet * pPacket)
{
	if (pPacket == 0)
		return 255;

	return (unsigned char)pPacket->data[0];
}

void Cliente::sendSyncPackage(RakNet::RakNetGUID guidDestino, unsigned char type) {
	TSyncMessage sync;
	sync.destino = guidDestino;
	sync.origen = EntityManager::i().getEntity(PLAYER)->getGuid();
	sync.packageType = type;
	/*std::cout << "Enviando paquete de sincronizacion..." << std::endl;
	std::cout << "Paquete: " << std::endl << "Origen: " << RakNet::RakNetGUID::ToUint32(sync.origen) << std::endl << "Destino: " << RakNet::RakNetGUID::ToUint32(sync.destino) << std::endl << "Tipo: " << (unsigned int)sync.packageType << std::endl;
	*/

	dispatchMessage(sync, SYNC);
}
void Cliente::pingServer() {

	peer->Ping(servidorAdr.ToString(false), 65535, false);
}

void Cliente::resetBar() {



	countDisparo = 0;
	countImpacto = 0;
	countDropVida = 0;
	countDropArma = 0;
	countMuerte = 0;
	countGranada = 0;
	countAumentaKill = 0;
	countAumentaMuerte = 0;

}


void Cliente::resetBar(unsigned char tipo) {

	switch (tipo) {
	case MOVIMIENTO: {

		break;
	}
	case DISPARAR_BALA:
	{
		countDisparo = 0;
		break;
	}
	case DISPARAR_ROCKET:
	{
		countDisparo = 0;
		break;
	}
	case IMPACTO_BALA:
	{
		countImpacto = 0;

		break;
	}
	case IMPACTO_ROCKET:
	{
		countImpacto = 0;
		break;
	}
	case VIDA_COGIDA:
	{
		countDropVida = 0;
		break;
	}
	case ARMA_COGIDA:
	{
		countDropArma = 0;
		break;
	}
	case MUERTE:
	{
		countMuerte = 0;
		break;
	}
	case LANZAR_GRANADA:
	{
		countGranada = 0;
		break;
	}
	case AUMENTA_KILL:
	{
		countAumentaKill = 0;
		break;
	}
	case AUMENTA_MUERTE:
	{
		countAumentaMuerte = 0;
		break;
	}
	default:
	{
		break;
	}
	}
}