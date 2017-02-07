#include <NetPlayer.h>
#include <Estructuras.h>
#include <EntityManager.h>
#include <Enemy.h>
#include <LifeObject.h>
#include <WeaponDrops/WeaponDrop.h>
#include <RocketBulletEnemy.h>
#include <Player.h>
#include <EventSystem.h>

NetPlayer::NetPlayer(Player* player) : NetObject(), m_player(player)
{
}

NetPlayer::~NetPlayer()
{

}

void NetPlayer::handlePackets(Time elapsedTime)
{

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
			connected = true;

			TPlayer nuevoplayer;
			nuevoplayer.guid = peer->GetMyGUID();
			nuevoplayer.name = m_player->getName();

			m_player->setGUID(peer->GetMyGUID());

			dispatchMessage(nuevoplayer, NUEVO_PLAYER);

			break;
		}


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
			/*countMovementPacketsIn++;
			sendSyncPackage(m.guid, mPacketIdentifier);*/
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

			//sendSyncPackage(balaDisparada.guid, mPacketIdentifier);
		}
		break;
		case IMPACTO_BALA:
		{

			TImpactoBala bala = *reinterpret_cast<TImpactoBala*>(packet->data);

			//nos guardamos el guid de quien dispara por si mata al jugador poder actualizar la tabla

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent().restaVida(bala.damage, bala.guid);
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojSangre.restart();

			//sendSyncPackage(bala.guid, mPacketIdentifier);

		}
		break;

		case DISPARAR_ROCKET:
		{
			TBala balaDisparada = *reinterpret_cast<TBala*>(packet->data);

			RocketBulletEnemy* balaRocket = new RocketBulletEnemy(balaDisparada.position, balaDisparada.direction, balaDisparada.rotation);

			//sendSyncPackage(balaDisparada.guid, mPacketIdentifier);

		}
		break;

		case IMPACTO_ROCKET:
		{
			TImpactoRocket impacto = *reinterpret_cast<TImpactoRocket*>(packet->data);

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			//le pasamos el damage causado por el rocket y el guid del jugador que lo disparo, para que si lo mata pueda apuntarse un punto
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent().restaVida(impacto.damage, impacto.guidDisparado);
			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojSangre.restart();

			//sendSyncPackage(impacto.guidDisparado, mPacketIdentifier);
		}
		break;

		case LANZAR_GRANADA:
		{
			TGranada granada = *reinterpret_cast<TGranada*>(packet->data);

			Enemy* ent = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(granada.guid));
			ent->lanzarGranada(granada);

			//sendSyncPackage(granada.guid, mPacketIdentifier);
		}
		break;

		case APLICAR_IMPULSO:
		{

			TImpulso imp = *reinterpret_cast<TImpulso*>(packet->data);

			//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			Player* player = (Player*)EntityManager::i().getEntity(PLAYER);
			player->impulsar(imp.fuerza);

			//sendSyncPackage(imp.guid, mPacketIdentifier);
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

			//sendSyncPackage(idArma.guid, mPacketIdentifier);
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

			//sendSyncPackage(idVida.guid, mPacketIdentifier);
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
			//sendSyncPackage(nuevoplayer.guid, mPacketIdentifier);
		}
		break;
		case ACTUALIZA_TABLA:
		{
			/*TFilaTabla nuevaFila = *reinterpret_cast<TFilaTabla*>(packet->data);

			PlayerEvent evento(nuevaFila);

			notify(evento);*/


		}
		break;
		case AUMENTA_KILL:
		{
			/*RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			KillEvent evento(guidTabla.guid);

			notify(evento);

			sendSyncPackage(guidTabla.guid, mPacketIdentifier);*/



		}
		break;

		case AUMENTA_MUERTE:
		{

			/*RakID guidTabla = *reinterpret_cast<RakID*>(packet->data);

			MuerteEvent evento(guidTabla.guid);

			notify(evento);

			sendSyncPackage(guidTabla.guid, mPacketIdentifier);*/


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

			Event* ev = new Event();
			ev->event_type = E_FIN_PARTIDA;

			//Notificamos al HUD que es el fin de la partida
			EventSystem::i().dispatchNow(ev);


		}
		break;

		/*case SYNC:
		{
			
			//Sync
			TSyncMessage sync = *reinterpret_cast<TSyncMessage*>(packet->data);
			//std::cout << windowsPacketOpen << std::endl;

			Enemy *e = dynamic_cast<Enemy*> (EntityManager::i().getRaknetEntity(sync.origen));
			if (e != NULL) {
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
		}*/
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

	/*if (mPacketIdentifier != MOVIMIENTO && mPacketIdentifier != SYNC && mPacketIdentifier != PING)
		countPacketsIn++;*/

	//std::cout << (unsigned int)mPacketIdentifier << std::endl;




	/*countPacketsTotal = countPacketsIn + countPacketsOut;
	countMovementPacketsTotal = countMovementPacketsIn + countMovementPacketsOut;
	duracionFor = timeFor.getElapsedTime().asMilliseconds();
	//pingMS = pingMS - (elapsedTime.asMilliseconds() - duracionFor);
	//pingMS = duracionFor;
	timeFor.restart();*/
}

/*void NetPlayer::apagar()
{
	if (isConnected()) {
		//First call shutdown from base class
		NetObject::apagar();

		//Do what you need here
	}
	
}
*/