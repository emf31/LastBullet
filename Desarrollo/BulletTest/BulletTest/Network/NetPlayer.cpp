#include <NetPlayer.h>
#include <Estructuras.h>
#include <EntityManager.h>
#include <Enemy.h>
#include <LifeObject.h>
#include <WeaponDrops/WeaponDrop.h>
#include <RocketBulletEnemy.h>
#include <Player.h>
#include <EventSystem.h>
#include <events/PlayerEvent.h>
#include <events/MuerteEvent.h>
#include <events/KillEvent.h>
#include <events\GameStartEvent.h>
#include <NetworkManager.h>
#include <Settings.h>
#include <Map.h>
#include <World.h>
#include <StateStack.h>
#include <thread>
#include <Settings.h>
#include <DebugMenuGUI.h>
#include <GUIManager.h>
#include <SoundManager.h>

NetPlayer::NetPlayer() : NetObject(), m_player(nullptr), m_world(World::i())
{

#ifdef NETWORK_DEBUG
	debugger.reset(new NetworkDebugger());
#endif

}

NetPlayer::~NetPlayer()
{

}

void NetPlayer::inicializar()
{
	messageFactory = new RakNet::Lobby2MessageFactory_Steam;
	//fcm2 = RakNet::FullyConnectedMesh2::GetInstance();
	lobby2Client = RakNet::Lobby2Client_Steam::GetInstance();

	lobby2Client->AddCallbackInterface(&steamResults);
	lobby2Client->SetMessageFactory(messageFactory);

	peer->AttachPlugin(lobby2Client);
	//peer->AttachPlugin(fcm2);


	//fcm2->SetConnectOnNewRemoteConnection(false, "");

	RakNet::Lobby2Message* msg = messageFactory->Alloc(RakNet::L2MID_Client_Login);
	lobby2Client->SendMsg(msg);
	messageFactory->Dealloc(msg);


	/*RakNet::Console_SearchRooms *msgSteam = (RakNet::Console_SearchRooms *) messageFactory->Alloc(RakNet::L2MID_Console_SearchRooms);

	lobby2Client->SendMsg(msgSteam);

	messageFactory->Dealloc(msgSteam);*/
}


void NetPlayer::crearPartida()
{
	NetworkManager::i().createServer();
	RakSleep(1000);
	int a = 1;
	conectar("127.0.0.1", server_port);

	while (isConnected() == false) {
		NetworkManager::i().updateNetwork(Time::Zero);
	}

	//Hasta aqui se ha creado la sala y el server. Parar hasta que se una la gente
	/*TGameInfo gameinfo;
	gameinfo.creador = getMyGUID();
	gameinfo.name = Settings::i().GetValue("name");
	gameinfo.gameMode = std::stoi(Settings::i().GetValue("gamemode"));
	gameinfo.map = Settings::i().GetValue("mapa");
	gameinfo.numBots = std::stoi(Settings::i().GetValue("bots"));
	gameinfo.maxKills = std::stoi(Settings::i().GetValue("maxkills"));

	dispatchMessage(gameinfo, CREAR_PARTIDA);
	//dispatchMessage(gameinfo, UNIRSE_PARTIDA);
	*/
	/*TPlayer p;
	p.name = "Nixon";

	m_bots.push_back(p);*/
	//m_bots.push_back(p2);


	//Enemy_Bot *bot2 = new Enemy_Bot("Washington", RakNet::UNASSIGNED_RAKNET_GUID);
	//bot2->m_network->inicializar();


	
	//Enemy_Bot *bot3 = new Enemy_Bot("Kennedy", RakNet::UNASSIGNED_RAKNET_GUID);
	//bot3->m_network->inicializar();
	
	/*Enemy_Bot *bot4 = new Enemy_Bot("Obama", RakNet::UNASSIGNED_RAKNET_GUID);
	bot4->m_network->inicializar();*/


}

void NetPlayer::setPlayerObject(Player * player)
{
	m_player = player;
}


uint64_t NetPlayer::crearLobby()
{
	if (lobby2Client->GetRoomID() != 0) {
		printf("Already in a room\n");

	} else {
		RakNet::Console_CreateRoom_Steam* msg = (RakNet::Console_CreateRoom_Steam*) messageFactory->Alloc(RakNet::L2MID_Console_CreateRoom);
		char rgchLobbyName[256];
		msg->roomIsPublic = true;
		_snprintf(rgchLobbyName, sizeof(rgchLobbyName), "Sala de %s", SteamFriends()->GetPersonaName());
		msg->roomName = rgchLobbyName;
		msg->publicSlots = 4;
		lobby2Client->SendMsg(msg);
		messageFactory->Dealloc(msg);
		IamHost = true;

		MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
		if (menu != nullptr) {
			MenuGUI::PlayerSlot* playerSlot;
			playerSlot = menu->setNameOnPlayerSlot(SteamFriends()->GetPersonaName());
			if (playerSlot != nullptr) {
				playerSlot->setReady(false);
			}
		}
		addPlayerInLobby(lobby2Client->GetMyUserID());
	}
	return lobby2Client->GetRoomID();
}

void NetPlayer::sendServerIPtoNewClient() {
	if (IamHost) {
		std::string ipMessage = "IP|";
		RakNet::Console_SendRoomChatMessage_Steam* msg = (RakNet::Console_SendRoomChatMessage_Steam*) messageFactory->Alloc(RakNet::L2MID_Console_SendRoomChatMessage);
		ipMessage = ipMessage + peer->GetLocalIP(0);
		msg->message = ipMessage.c_str();
		msg->roomId = lobby2Client->GetRoomID();
		lobby2Client->SendMsg(msg);
		messageFactory->Dealloc(msg);
	}
}


void NetPlayer::unirseLobby(const std::string& str)
{

	//char eleccion;
	//int elec;

	//std::string str;

	/*do {
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

	} while (eleccion == 'a');*/

	conectar(str, server_port);
	//RakSleep(1000);
	while (isConnected() == false) {
		NetworkManager::i().updateNetwork(Time::Zero);
	}

	TPlayer p;
	p.guid = peer->GetMyGUID();
	p.name = SteamFriends()->GetPersonaName();

	dispatchMessage(p, UNIRSE_PARTIDA);
	

	/*swhile (World::i().gamestarted == false) {
		NetworkManager::i().updateNetwork(Time::Zero);
	}

	StateStack::i().GetCurrentState()->Clear();
	StateStack::i().SetCurrentState(States::ID::InGame);
	StateStack::i().GetCurrentState()->Inicializar();*/
}



void NetPlayer::apagar()
{
	if (isConnected()) {
		//First call shutdown from base class
		NetObject::apagar();

		//Do what you need here
		m_servers.clear();
	}
	
}



void NetPlayer::searchServersOnLAN() {
	//Creo un RakPeer para lanzar un paquete de b�squeda
	RakNet::RakPeerInterface *client;
	client = RakNet::RakPeerInterface::GetInstance();

	RakNet::SocketDescriptor socketDescriptor(65534, 0);
	socketDescriptor.socketFamily = AF_INET;

	client->Startup(1, &socketDescriptor, 1);

	RakNet::RakNetGUID rakID = client->GetMyGUID();

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

uint64_t NetPlayer::getLobbyID() {
	if (lobby2Client != nullptr) {
		return lobby2Client->GetRoomID();
	}
	return 0;
}

RakNet::Lobby2MessageFactory_Steam * NetPlayer::getMessageFactory() {
	return messageFactory;
}

RakNet::Lobby2Client_Steam * NetPlayer::getLobby2Client() {
	return lobby2Client;
}

void NetPlayer::joinSteamLobby(uint64 lobbyID) {
	RakNet::Console_JoinRoom_Steam* msg = (RakNet::Console_JoinRoom_Steam*) messageFactory->Alloc(RakNet::L2MID_Console_JoinRoom);
	msg->roomId = lobbyID;
	std::cout << "Joining Lobby: " << lobbyID << std::endl;
	lobby2Client->SendMsg(msg);
	messageFactory->Dealloc(msg);

	MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
	if (menu != nullptr) {
		menu->setNameOnPlayerSlot(SteamFriends()->GetPersonaName());
	}
	addPlayerInLobby(lobby2Client->GetMyUserID());
	//conectar(ip, server_port);
}

void NetPlayer::addPlayerInLobby(uint64_t steamID) {
	SteamIDs.push_back(steamID);
}

void NetPlayer::substractPlayerInLobby(uint64_t steamID) {
	for (auto it = SteamIDs.begin(); it < SteamIDs.end(); ++it) {
		if ((*(it)) == steamID) {
			SteamIDs.erase(it);
			break;
		}
	}
}









































void NetPlayer::handlePackets(Time elapsedTime) {

	

	for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {

		// Recibimos un paquete, tenemos que obtener el tipo de mensaje
		mPacketIdentifier = getPacketIdentifier(packet);

		switch (mPacketIdentifier) {
		case ID_REMOTE_DISCONNECTION_NOTIFICATION:
			printf("Otro cliente se ha desconectado.\n");
			break;
		case 22:
			printf("EL SERVIDOR SE HA CAIDO.\n");

			//Volvemos al menu
			StateStack::i().GetCurrentState()->Clear();
			StateStack::i().SetCurrentState(States::ID::Menu);
			StateStack::i().GetCurrentState()->Inicializar();

			return;

			break;
		case ID_REMOTE_CONNECTION_LOST:
			printf("Otro cliente ha perdido la conexion.\n");

			break;
		case ID_CONNECTION_ATTEMPT_FAILED:
			printf("Fallo en la conexion.\n");

			//Aqui enviariamos un evento de conexion fallida a la interfaz.

			break;

		case ID_CONNECTION_REQUEST_ACCEPTED: {

			printf("Nuestra conexion se ha aceptado.\n");
			servidor = packet->guid;
			servidorAdr = packet->systemAddress;



			//Esta variable indica que el servidor ha aceptado la conexion
			connected = true;

			break;
		}

		case CARGA_COMPLETA:
		{
			//Un jugador ha terminado de cargar la partida, y esta listo para jugar
			RakID info = *reinterpret_cast<RakID*>(packet->data);
			m_enemyFactory.markEnemyAsAvailable(info.guid);

			//Solo lo creamos si no estamos en estado de carga
			if (StateStack::i().GetCurrentStateID() != States::ID::Carga) {
				m_enemyFactory.createEnemyIfAvailable(info.guid);
			}


			break;
		}

		case EMPEZAR_PARTIDA: {

			TGameInfo info = *reinterpret_cast<TGameInfo*>(packet->data);


			GameStartEvent* gev = new GameStartEvent(info);

			EventSystem::i().dispatchNow(gev);

			//When we recive a starting game message we change
			//current state to CARGA
			StateStack::i().GetCurrentState()->Clear();
			StateStack::i().SetCurrentState(States::ID::Carga);
			StateStack::i().GetCurrentState()->Inicializar();

			break;
		}


		case NUEVO_PLAYER:
		{
			//un player nuevo se ha conectado, y recibo sus datos, tengo que ponerlo en la lista de jugadores

			TPlayer p = *reinterpret_cast<TPlayer*>(packet->data);

			m_enemyFactory.addEnemyToBeCreated(p);

#ifdef NETWORK_DEBUG
			//debugger->addDebugMark(e->getID());
#endif

		}
		break;

		case NUEVO_CLIENTE:
		{
			//eres un player nuevo, te envian todos los clientes que habian en el server para que tu tambien los tengas

			TPlayer p = *reinterpret_cast<TPlayer*>(packet->data);

			m_enemyFactory.addEnemyToBeCreated(p);

#ifdef NETWORK_DEBUG
			//debugger->addDebugMark(e->getID());
#endif


		}
		break;
		case MOVIMIENTO:
		{
			unsigned char useTimeStamp; // Assign this to ID_TIMESTAMP
			RakNet::Time timeStamp; // Put the system time in here returned by RakNet::GetTime()
			unsigned char typeId;
			bool isDying;
			Vec3<float> position;
			Vec3<float> rotation;
			RakNet::RakNetGUID guid;


			RakNet::BitStream myBitStream(packet->data, packet->length, false); // The false is for efficiency so we don't make a copy of the passed data
			myBitStream.Read(useTimeStamp);
			myBitStream.Read(timeStamp);
			myBitStream.Read(typeId);
			myBitStream.Read(isDying);
			myBitStream.Read(position);
			myBitStream.Read(rotation);
			myBitStream.Read(guid);

			
			//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
			Enemy *e = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(guid));

			if (e != NULL) {
				e->getNetworkPrediction()->addMovement( TMovimiento{ useTimeStamp, timeStamp, typeId, isDying, position, rotation, guid });
				//e->encolaMovimiento(m);

				/*DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
				Time time = milliseconds(RakNet::GetTimeMS() - timeStamp);
				menu->addPrintText(std::to_string(time.asMilliseconds()));*/
				
			}

			/*countMovementPacketsIn++;*/

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(m.guid, mPacketIdentifier);
#endif
		}
		break;


		case DESCONECTADO:
		{
			RakID rakID = *reinterpret_cast<RakID*>(packet->data);

			Entity* ent = EntityManager::i().getRaknetEntity(rakID.guid);
			GraphicEngine::i().removeNode(ent->getNode());
			EntityManager::i().removeEntity(ent);
			

		}
		break;

		case TERMINAR_PARTIDA:
		{
			//Volvemos al menu
			StateStack::i().GetCurrentState()->Clear();
			StateStack::i().SetCurrentState(States::ID::Menu);
			StateStack::i().GetCurrentState()->Inicializar();

			return;

			break;
		}


		case DISPARAR_BALA:
		{
			TBala balaDisparada = *reinterpret_cast<TBala*>(packet->data);
			SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("shoot.mp3", "sounds"), balaDisparada.position);
			GunBullet* bala = new GunBullet(balaDisparada.position, balaDisparada.direction, balaDisparada.finalposition, balaDisparada.rotation);
			bala->cargarContenido();

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(balaDisparada.guid, mPacketIdentifier);
#endif
		}
		break;
		case IMPACTO_BALA:
		{

			TImpactoBala bala = *reinterpret_cast<TImpactoBala*>(packet->data);

			//nos guardamos el guid de quien dispara por si mata al jugador poder actualizar la tabla

			//si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			//bala.guid = quien te ha disparado
			m_player->getLifeComponent().restaVida(bala.damage, bala.guidDisparado);
			m_player->relojSangre.restart();

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(bala.guid, mPacketIdentifier);
#endif

		}
		break;

		case DISPARAR_ROCKET:
		{
			TBala balaDisparada = *reinterpret_cast<TBala*>(packet->data);

			RocketBulletEnemy* balaRocket = new RocketBulletEnemy(balaDisparada.position, balaDisparada.direction, balaDisparada.rotation);

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(balaDisparada.guid, mPacketIdentifier);
#endif

		}
		break;

		case IMPACTO_ROCKET:
		{
			TImpactoRocket impacto = *reinterpret_cast<TImpactoRocket*>(packet->data);

			//si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			//le pasamos el damage causado por el rocket y el guid del jugador que lo disparo, para que si lo mata pueda apuntarse un punto
			m_player->getLifeComponent().restaVida(impacto.damage, impacto.guidDisparado);
			m_player->relojSangre.restart();

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(impacto.guidDisparado, mPacketIdentifier);
#endif

		}
		break;

		case LANZAR_GRANADA:
		{
			TGranada granada = *reinterpret_cast<TGranada*>(packet->data);

			Enemy* ent = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(granada.guid));
			ent->lanzarGranada(granada);

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(granada.guid, mPacketIdentifier);
#endif
		}
		break;

		case APLICAR_IMPULSO:
		{

			TImpulso imp = *reinterpret_cast<TImpulso*>(packet->data);

			//si recibimos este mensaje es pork nos han dado a nosotros
			m_player->impulsar(imp.fuerza);

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(imp.guid, mPacketIdentifier);
#endif
		}
		break;

		case NUEVA_VIDA:
		{
			TDropServer vidaServer = *reinterpret_cast<TDropServer*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			LifeObject *v = static_cast<LifeObject*>(EntityManager::i().getEntity(vidaServer.id));
			if (v != NULL) {
				v->asignaTiempo(vidaServer.tiempo);
			}

		}
		break;

		case NUEVA_ARMA:
		{
			TDropServer armaServer = *reinterpret_cast<TDropServer*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			WeaponDrop *v = static_cast<WeaponDrop*>(EntityManager::i().getEntity(armaServer.id));
			if (v != NULL) {
				v->asignaTiempo(armaServer.tiempo);
			}


		}
		break;

		case ARMA_COGIDA:
		{
			TId idArma = *reinterpret_cast<TId*>(packet->data);

			//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
			//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
			WeaponDrop *w = static_cast<WeaponDrop*>(EntityManager::i().getEntity(idArma.id));
			w->ArmaCogida();

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(idArma.guid, mPacketIdentifier);
#endif

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

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(idVida.guid, mPacketIdentifier);
#endif
		}
		break;

		case MUERTE:
		{

			RakID nuevoplayer = *reinterpret_cast<RakID*>(packet->data);

			Entity* ent = EntityManager::i().getRaknetEntity(nuevoplayer.guid);

			//Si ha muerto el player
			if (ent == m_player) {
				//es el player
				Player* player = (Player*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
				player->resetAll();

			} else if (ent->getClassName() == "Enemy_Bot") {
				Enemy_Bot* bot = (Enemy_Bot*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
				bot->resetAll();

			}

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(nuevoplayer.guid, mPacketIdentifier);
#endif

		}
		break;
		case ACTUALIZA_TABLA:
		{
			TFilaTabla nuevaFila = *reinterpret_cast<TFilaTabla*>(packet->data);

			PlayerEvent* evento = new PlayerEvent(nuevaFila);

			EventSystem::i().dispatchNow(evento);

			World::i().getPartida()->muestraMarcador();

		}
		break;
		case AUMENTA_KILL:
		{
			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			KillEvent* killEvent = new KillEvent(guidTabla.guid);

			EventSystem::i().dispatchNow(killEvent);

			World::i().getPartida()->muestraMarcador();


#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(guidTabla.guid, mPacketIdentifier);
#endif
		}
		break;

		case AUMENTA_MUERTE:
		{

			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			MuerteEvent* deathEvent = new MuerteEvent(guidTabla.guid);

			EventSystem::i().dispatchNow(deathEvent);

			World::i().getPartida()->muestraMarcador();

#ifdef NETWORK_DEBUG
			debugger->sendSyncPackage(guidTabla.guid, mPacketIdentifier);
#endif

		}
		break;


		case FIN_PARTIDA:
		{

			RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			Event* ev = new Event();
			ev->event_type = E_FIN_PARTIDA;

			//Notificamos al HUD que es el fin de la partida
			EventSystem::i().dispatchNow(ev);


		}
		break;

		case CAMBIO_ARMA:
		{
			TCambioArma t_cambioArma = *reinterpret_cast<TCambioArma*>(packet->data);

			if (t_cambioArma.cambio == 1) {
				Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMAUP", NULL);
				MessageHandler::i().sendMessage(msg1);
			} else {
				Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMADOWN", NULL);
				MessageHandler::i().sendMessage(msg1);
			}

		}
		break;

		case SYNC:
		{

#ifdef NETWORK_DEBUG
			TSyncMessage sync = *reinterpret_cast<TSyncMessage*>(packet->data);

			debugger->receivedSyncPacket(sync);
#endif
			break;
		}

		/*case PING:
		{
		//Ping

		TPing pingStruct = *reinterpret_cast<TPing*>(packet->data);
		//+1 milisegundo que tarda en hacer el for
		//pingMS = RakNet::GetTimeMS() - pingStruct.ping - duracionFor + 1;

		break;
		}*/
		default:
			printf("Un mensaje con identificador %i ha llegado.\n", mPacketIdentifier);
			break;

		}



	}


}