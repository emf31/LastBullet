
#include <iostream>
#include <string>
#include <chrono>
#include <RakNetTime.h>
#include <RakSleep.h>
#include "Cliente.h"
#include "Estructuras.h"
#include "../Entities/EntityManager.h"
#include "../Entities/Entity.h"
#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../Handlers/Message.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"
#include "../Entities/GunBullet.h"
#include "../Entities/LifeObject.h"
#include "../Entities/WeaponDrops/WeaponDrop.h"
#include "../Entities/WeaponDrops/AsaltoDrop.h"
#include "../Entities/RocketBulletEnemy.h"

Cliente::Cliente()
{
}



void Cliente::update() {
		

	
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			switch (packet->data[0]) {
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


				//Esta variable indica que el servidor a aceptado la conexion
				conectado = true;


			}
				break;

			case NUEVO_PLAYER:
			{
				//un player nuevo se ha conectado, y recibo sus datos, tengo que ponerlo en la lista de jugadores

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);


				Enemy *e = new Enemy(nuevoplayer.name, nuevoplayer.guid);
				e->inicializar();
				e->cargarContenido();
				e->setPosition(nuevoplayer.position);
				EntityManager::i().mostrarClientes();

			}
			break;

			case NUEVO_CLIENTE:
			{
				//eres un player nuevo, te envian todos los clientes que habian en el server para que tu tambien los tengas

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);

				Enemy *e = new Enemy(nuevoplayer.name, nuevoplayer.guid);
				e->inicializar();
				e->cargarContenido();
				e->setPosition(nuevoplayer.position);
				EntityManager::i().mostrarClientes();

			}
			break;

			case NUEVA_VIDA:
			{
				

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(vidaServer);
				//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
				//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
				LifeObject *v= static_cast<LifeObject*>(EntityManager::i().getEntity(vidaServer.id));
				v->asignaTiempo(vidaServer.tiempo);
				//NOTA: si esto no va igual tenemos que enviar un mensaje con el mensaje handler

			}
			break;

			case NUEVA_ARMA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(vidaServer);
				//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
				//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
				
				//NOTA: si esto no va igual tenemos que enviar un mensaje con el mensaje handler

			}
			break;

			case ARMA_COGIDA:
			{


				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(idVida);
				//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
				//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
				WeaponDrop *w = static_cast<WeaponDrop*>(EntityManager::i().getEntity(idVida));
				w->ArmaCogida();
				//NOTA: si esto no va igual tenemos que enviar un mensaje con el mensaje handler


				



				Message msg(w, "cogida", NULL);
				MessageHandler::i().sendMessage(msg);


			}
			break;

			case VIDA_COGIDA:
			{


				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(idVida);
				//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
				//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
				//TODO esto peta por todos lados, enviar un mensaje a la entity y que haga ella el reesto
				LifeObject *v = static_cast<LifeObject*>(EntityManager::i().getEntity(idVida));
				v->VidaCogida();
				//NOTA: si esto no va igual tenemos que enviar un mensaje con el mensaje handler

			}
			break;

			case MOVIMIENTO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el player
				bsIn.Read(movimiento);
				//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
				Enemy *e = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(movimiento.guid));

				if (e != NULL) {
					e->encolaMovimiento(movimiento);
				}
				
				e = nullptr;

			}
			break;


			case DESCONECTADO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				
				bsIn.Read(desconectado);
				//Entity* e = EntityManager::i().getRaknetEntity(desconectado);
				//EntityManager::i().getRaknetEntity(desconectado)->borrarContenido();
				//EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(desconectado));
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(desconectado));

				//TODO IMPORTANTE: esto a veces da un error pork borra el entity justo cuando en el otro hilo esta haciendo el update del entity que aqui se elimina
				//habria que enviarle un mensaje borrate igual que la bala para que lo borre despues del update.
				

			}
			break;

			case DISPARAR_BALA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(balaDisparada);


				GunBullet* bala = new GunBullet(balaDisparada.position, balaDisparada.direction, balaDisparada.finalposition, balaDisparada.rotation);
				bala->cargarContenido();

			}
			break;

			case DISPARAR_ROCKET:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(balaDisparada);

				RocketBulletEnemy* balaRocket = new RocketBulletEnemy(balaDisparada.position, balaDisparada.direction, balaDisparada.rotation);


			}
			break;

			case LANZAR_GRANADA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(granada);
				
				Enemy* ent = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(granada.guid));
				ent->lanzarGranada(granada);


			}
			break;

			case CAMBIO_ARMA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(t_cambioArma);

				if (t_cambioArma.cambio == 1) {
					Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMAUP", NULL);
					MessageHandler::i().sendMessage(msg1);
				}else {
					Message msg1(EntityManager::i().getRaknetEntity(t_cambioArma.guid), "ARMADOWN", NULL);
					MessageHandler::i().sendMessage(msg1);
				}



			}
			break;

			case IMPACTO_BALA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//nos guardamos el guid de quien dispara por si mata al jugador poder actualizar la tabla
				bsIn.Read(imp_bala);


				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent()->restaVida(imp_bala.damage, imp_bala.guid);

				//TODO ahora le quitamos siempre 20 de vida en un futuro podriamos pensar en quitar vida dependiendo de donde impacte la bala

			}
			break;

			case IMPACTO_ROCKET:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				std::cout << "ME HAN DADO CON EL ROCKET" << std::endl;

				
				bsIn.Read(impacto);

				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				//le pasamos el damage causado por el rocket y el guid del jugador que lo disparo, para que si lo mata pueda apuntarse un punto
				static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent()->restaVida(impacto.damage,impacto.guidDisparado);

			}
			break;

			case APLICAR_IMPULSO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(fuerza);

				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				Player* player = (Player*)EntityManager::i().getEntity(PLAYER);
				player->impulsar(fuerza);
				player = nullptr;

			}
			break;


			case ACTUALIZA_TABLA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(guidTabla);

				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				EntityManager::i().cambiaTabla(nuevaFila);

			}
			break;

			case AUMENTA_KILL:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(guidTabla);

				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				//EntityManager::i().aumentaKill(guidTabla);

			}
			break;

			case AUMENTA_MUERTE:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(nuevaFila);

				//el player siempre tendra ID=1000 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				//EntityManager::i().aumentaMuerte(guidTabla);

			}
			break;


			case MUERTE:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(nuevoplayer);
				
				//std::cout << "el player " << p.name << " ha muerto" << std::endl;

				if (EntityManager::i().getRaknetEntity(nuevoplayer.guid)->getID() == PLAYER) {
					//es el player
					Player* player = (Player*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
					//player->setPosition(nuevoplayer.position);		
					player->resetAll();
					player = nullptr;

					//TODO esto en verdad no iria aqui, esto deberia de estar en algun metodo que resetee, la vida y la municion despues de que pase un cierto tiempo para reaparecer
					//ademas que desactivara el draw de esta entetity para que no puedeas moverte ni nada mientras estas muerto.
					static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getLifeComponent()->resetVida();
				}
				else {
					//es un enemigo
					Enemy* enemigo = (Enemy*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
					enemigo->setIsDying(true);
					//enemigo->
					//enemigo->setPosition(nuevoplayer.position);
					enemigo = nullptr;
				}
				


			}
			break;

			case ID_UNCONNECTED_PONG:
			{
				RakNet::TimeMS time;
				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(1);
				bsIn.Read(time);
				printf("Got pong from %s with time %i\n", packet->systemAddress.ToString(), RakNet::Time() - time);
			}
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;

			}
		}


}

void Cliente::inicializar() {
	conectado = false;
	char eleccion;
	int elec;
	std::string str;

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
		} else if (eleccion == 'm') {
			printf("Introduce la IP \n");
			std::cin >> str;
			if (str != "a") {
				break;
			} else {
				eleccion = 'a';
			}
		}
	}while (eleccion == 'a');
	
	std::cout << "Conectando al servidor " << str << ":" << SERVER_PORT << std::endl;
	conectar(str, SERVER_PORT);
}

void Cliente::conectar(std::string address, int port) {
	peer = RakNet::RakPeerInterface::GetInstance();
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);

}

void Cliente::createPlayer(std::vector<Vec3<float>> &spawnPoints) {
	RakNet::BitStream bsOut;
	std::string str;
	TPlayer nuevoplayer;


	//Al conectarnos le enviamos nuestro objeto Player tal cual
	bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);

	printf("Introduce un nombre \n");
	std::cin >> str;


	Player *player = new Player(str, spawnPoints, peer->GetMyGUID());
	player->inicializar();
	player->cargarContenido();


	nuevoplayer.guid = player->getGuid();
	nuevoplayer.name = player->getName();



	bsOut.Write(nuevoplayer);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::enviarMovimiento(Player* p) {

	RakNet::BitStream bsOut;
	TMovimiento paquetemov;

	bsOut.Write((RakNet::MessageID)MOVIMIENTO);

	//TODO asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
	paquetemov.position = p->getRenderState()->getPosition();
	paquetemov.rotation = p->getRenderState()->getRotation();
	paquetemov.guid = p->getGuid();

	bsOut.Write(paquetemov);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::vidaCogida(int id)
{
	RakNet::BitStream bsOut;
	TPlayer paquetemov;

	bsOut.Write((RakNet::MessageID)VIDA_COGIDA);
	//enviamos un mensaje al server con la vida que ha sido cogida
	bsOut.Write(id);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::nuevaVida(int id)
{

	RakNet::BitStream bsOut;
	

	bsOut.Write((RakNet::MessageID)NUEVA_VIDA);

	bsOut.Write(id);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::nuevaArma(int id)
{

	RakNet::BitStream bsOut;


	bsOut.Write((RakNet::MessageID)NUEVA_ARMA);

	bsOut.Write(id);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::armaCogida(int id)
{
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)ARMA_COGIDA);
	//enviamos un mensaje al server con la vida que ha sido cogida
	bsOut.Write(id);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::lanzarGranada(TGranada g) {

	RakNet::BitStream bsOut;
	

	bsOut.Write((RakNet::MessageID)LANZAR_GRANADA);

	bsOut.Write(g);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::enviarDisparo(RakNet::RakNetGUID guid, float* damage) {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)IMPACTO_BALA);

	//////////////////////////////////////////////////////
	//TODO asumimios que el disparo ha sido certero del jugador que dispara con un enemigo, luego simplemente habria que cambiar la logica de ahora (que es pulsar la R, esta en player)
	//por la de que si la bala colisiona de verdad, si la bala colisiona de verdad desencadenaria toda la logica que se produce al pulsar la R ahora.
	/////////////////////////////////////////////////////
	//bsOut.Write(aqui pasariamos el guid del enemigo al que le hemos dado cuando sepamos con quien ha colisionado la bala)
	//se pueden enviar 2 mensajes seguidos, luego habria que hacer 2 read en el servidor, el primero te dice el guid de quien ha recibido el disparo y el segundo el guid de quien ha disparado

	//ANTES ESTABA ASI
	//bsOut.Write(guid);
	//esto no tiene sentido le estas pasando el guid del que dispara, hay que saber el guid de a quien le da la bala, ahora cogemos uno cual sea de los enteties
	TImpactoBala imp_bala;
	imp_bala.damage = *damage;
	imp_bala.guid = guid;

	bsOut.Write(imp_bala);
	//printf("envio mensaje del disparo\n");
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}


void Cliente::enviarDesconexion() {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DESCONECTADO);
	bsOut.Write(1);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::dispararBala(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation) {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DISPARAR_BALA);
	TBala bala;
	bala.direction = direction;
	bala.position = position;
	bala.finalposition = finalposition;
	bala.rotation = rotation;
	bala.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
	bsOut.Write(bala);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::dispararRocket(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation)
{
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DISPARAR_ROCKET);
	TBala bala;
	bala.direction = direction;
	bala.position = position;
	bala.rotation = rotation;
	bala.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
	bsOut.Write(bala);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}


void Cliente::playerMuerto()
{
	//si entras aqui es porque te has quedado sin vida, se lo comunicas el servidor para que se lo comunique a todos y te vuelva a asignar una posicion.

	RakNet::BitStream bsOut;
	TPlayer nuevoplayer;
	bsOut.Write((RakNet::MessageID)MUERTE);

	nuevoplayer.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
	nuevoplayer.name = EntityManager::i().getEntity(PLAYER)->getName();
	nuevoplayer.position = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();


	bsOut.Write(nuevoplayer);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::impactoRocket(RakNet::RakNetGUID palayerDanyado, TImpactoRocket* impact)
{
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)IMPACTO_ROCKET);

	bsOut.Write(*impact);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::aplicarImpulso(Vec3<float> force, RakNet::RakNetGUID guid)
{
	RakNet::BitStream bsOut;
	TImpulso impulso;
	impulso.fuerza = force;
	impulso.guid = guid;
	bsOut.Write((RakNet::MessageID)APLICAR_IMPULSO);
	bsOut.Write(impulso);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::cambioArma(int cambio, RakNet::RakNetGUID guid)
{
	RakNet::BitStream bsOut;
	TCambioArma swap;
	swap.cambio = cambio;
	swap.guid = guid;
	bsOut.Write((RakNet::MessageID)CAMBIO_ARMA);
	bsOut.Write(swap);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::actualizaTabla(RakNet::RakNetGUID guidKill, RakNet::RakNetGUID guidDeath)
{
	TKill kill;
	kill.guidKill = guidKill;
	kill.guidDeath = guidDeath;

	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)ACTUALIZA_TABLA);
	bsOut.Write(kill);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}

void Cliente::searchServersOnLAN() {
	//Creo un RakPeer para lanzar un paquete de búsqueda
	RakNet::RakPeerInterface *client;
	client = RakNet::RakPeerInterface::GetInstance();

	RakNet::SocketDescriptor socketDescriptor(65534, 0);
	socketDescriptor.socketFamily = AF_INET;

	client->Startup(1, &socketDescriptor, 1);

	//Hacemos ping a bradcast en el puerto en el que sabemos que está escuchando el server
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
			m_servers.push_back(packet->systemAddress.ToString());
		}

		RakSleep(1000);
	}
	//Destruyo el RakPeer. Ya no hace falta
	RakNet::RakPeerInterface::DestroyInstance(client);
}


void Cliente::apagar() {
	
	conectado = false;

	RakNet::RakPeerInterface::DestroyInstance(peer);

}