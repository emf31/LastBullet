
#include <iostream>
#include <string>
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

Cliente::Cliente()
{
}



void Cliente::update() {
	
	RakNet::BitStream bsOut;
	std::string str;
	TPlayer nuevoplayer;
	TBala balaDisparada;
	TGranada granada;
	TVidaServer vidaServer;
	RakNet::RakNetGUID desconectado;
	int idVida;
	

	while (1) {
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
				//Al conectarnos le enviamos nuestro objeto Player tal cual
				bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);

				printf("Introduce un nombre \n");
				std::cin >> str;

				Player *player = new Player(str, peer->GetMyGUID());
				player->inicializar();
				player->cargarContenido();
				

				nuevoplayer.guid = player->getGuid();
				nuevoplayer.name = player->getName();
				//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
				nuevoplayer.position = Vec3<float> (0,100,0);
				player->setPosition(nuevoplayer.position);

				//Esta variable indica que el servidor a aceptado la conexion
				conectado = true;

				bsOut.Write(nuevoplayer);
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
				bsOut.Reset();

			}
				break;

			case NUEVO_PLAYER:
			{
				//un player nuevo se ha conectado, y recibo sus datos, tengo que ponerlo en la lista de jugadores

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);

				TPlayer *p = new TPlayer();
				p->position = nuevoplayer.position;
				p->guid = nuevoplayer.guid;
				p->name = nuevoplayer.name;
				p->rotation = nuevoplayer.rotation;
				p->velocidad = nuevoplayer.velocidad;

				Message msg(EntityManager::i().getEntity(PLAYER),"NUEVO_ENEMIGO", static_cast<void*>(p));
				MessageHandler::i().sendMessage(msg);

			}
			break;

			case NUEVO_CLIENTE:
			{
				//eres un player nuevo, te envian todos los clientes que habian en el server para que tu tambien los tengas

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				//recibo el player
				bsIn.Read(nuevoplayer);

				TPlayer *p = new TPlayer();
				p->position = nuevoplayer.position;
				p->guid = nuevoplayer.guid;
				p->name = nuevoplayer.name;
				p->rotation = nuevoplayer.rotation;
				p->velocidad = nuevoplayer.velocidad;

				Message msg(EntityManager::i().getEntity(PLAYER), "NUEVO_ENEMIGO", static_cast<void*>(p));
				MessageHandler::i().sendMessage(msg);

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

			case VIDA_COGIDA:
			{


				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(idVida);
				//recibimos mensaje en el cliente de que cuando nos conectamos una vida estaba cogida, entonces obtenemos esa vida que nos dice el servidor cual es mediante el id
				//y le cambiamos el tiempo de recargar que tenia por el que el servidor te pasa
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
				bsIn.Read(nuevoplayer);
				//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
				Enemy *e = static_cast<Enemy*>(EntityManager::i().getRaknetEntity(nuevoplayer.guid));
				//e->updateEnemigo(nuevoplayer.position);
				//e = nullptr;
				//std::cout << "///////////////////INICIO MOVIMIENTO////////////////////////" << std::endl;
				//std::cout << "++ENVIO MENSAJE MOVE A LA ENTITY" << e->getName() << std::endl;


				//ANTEEES!!
				//Message msg1(e, "MOVE", static_cast<void*>(&nuevoplayer));
				//MessageHandler::i().sendMessage(msg1);

				//e->updateEnemigo(nuevoplayer.position);

				//NUEVO
				if (e != NULL) {
					TPlayer *p = new TPlayer();
					p->position = nuevoplayer.position;
					p->guid = nuevoplayer.guid;
					p->name = nuevoplayer.name;
					p->rotation = nuevoplayer.rotation;
					p->velocidad = nuevoplayer.velocidad;

					Message msg(e, "MOVIMIENTO", static_cast<void*>(p));
					MessageHandler::i().sendMessage(msg);
				}
				

				//std::cout << "///////////////////FINAL MOVIMIENTO////////////////////////" << std::endl;
				
				//std::cout << "///////////////////INCIO LISTA////////////////////////" << std::endl;
				//EntityManager::i().muestraPosClientes();
				//std::cout << "///////////////////FINAL LISTA////////////////////////" << std::endl;

			}
			break;


			case DESCONECTADO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				
				bsIn.Read(desconectado);
				Entity* e = EntityManager::i().getRaknetEntity(desconectado);
				EntityManager::i().getRaknetEntity(desconectado)->borrarContenido();
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(desconectado));
				EntityManager::i().removeRaknetEntity(EntityManager::i().getRaknetEntity(desconectado));

				//TODO IMPORTANTE: esto a veces da un error pork borra el entity justo cuando en el otro hilo esta haciendo el update del entity que aqui se elimina
				//habria que enviarle un mensaje borrate igual que la bala para que lo borre despues del update.
				

			}
			break;

			case DISPARAR_BALA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(balaDisparada);
				//Bullet* bala = new Bullet(balaDisparada.position, balaDisparada.direction, balaDisparada.finalposition, balaDisparada.rotation);

				Message msg1(EntityManager::i().getEntity(1000), "DIBUJARBALA", static_cast<void*>(&balaDisparada));
				MessageHandler::i().sendMessage(msg1);


			}
			break;

			case LANZAR_GRANADA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(granada);
				//Bullet* bala = new Bullet(balaDisparada.position, balaDisparada.direction, balaDisparada.finalposition, balaDisparada.rotation);

				Message msg1(EntityManager::i().getRaknetEntity(granada.guid), "LAZARGRANADA", static_cast<void*>(&granada));
				MessageHandler::i().sendMessage(msg1);


			}
			break;

			case IMPACTO_BALA:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				std::cout << "Me han disparado" << std::endl;

				//TODO:ahora mismo no hace falta leer, aqui te pasan el arma con la cual disparaste.
				//bsIn.Read(desconectado);

				//el player siempre tendra ID=1 asi que si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
				if (EntityManager::i().getEntity(PLAYER)->restaVida() <= 0) {
					std::cout << "ME HAN MATADO" << std::endl;
					std::cout << "HIJO PUTA EL CAMPERO" << std::endl;
					//si entras aqui es porque te has quedado sin vida, se lo comunicas el servidor para que se lo comunique a todos y te vuelva a asignar una posicion.

					bsOut.Write((RakNet::MessageID)MUERTE);

					nuevoplayer.guid = EntityManager::i().getEntity(PLAYER)->getGuid();
					nuevoplayer.name = EntityManager::i().getEntity(PLAYER)->getName();
					nuevoplayer.position = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();


					bsOut.Write(nuevoplayer);
					peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
					bsOut.Reset();



					

				}

			}
			break;

			case MUERTE:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(nuevoplayer);
				
				std::cout << "el player " << nuevoplayer.name << " ha muerto" << std::endl;

				if (EntityManager::i().getRaknetEntity(nuevoplayer.guid)->getID()==1000) {
					//es el player
					Player* player= (Player*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
					player->setPosition(nuevoplayer.position);			
					player = nullptr;

					//TODO: esto en verdad no iria aqui, esto deberia de estar en algun metodo que resetee, la vida y la municion despues de que pase un cierto tiempo para reaparecer
					//ademas que desactivara el draw de esta entetity para que no puedeas moverte ni nada mientras estas muerto.
					EntityManager::i().getEntity(1000)->resetVida();
				}
				else {
					//es un enemigo
					Enemy* enemigo= (Enemy*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
					enemigo->setPosition(nuevoplayer.position);
					enemigo = nullptr;
				}
				


			}
			break;


			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;

			}
		}

	}

}

void Cliente::inicializar() {
	conectado = false;

	peer = RakNet::RakPeerInterface::GetInstance();

	printf("Introduce la IP \n");
	std::string str;
	std::cin >> str;
	std::cout << "Conectando al servidor " << str << ":" << SERVER_PORT << std::endl;

	conectar(str, SERVER_PORT);
}

void Cliente::conectar(std::string address, int port) {
	peer->Startup(1, &sd, 1);
	peer->Connect(address.c_str(), SERVER_PORT, 0, 0);


	hilo = new std::thread(&Cliente::update, this);
}

void Cliente::esperar() {
	hilo->join();
}

void Cliente::enviarPos(Player* p) {

	RakNet::BitStream bsOut;
	TPlayer paquetemov;

	bsOut.Write((RakNet::MessageID)MOVIMIENTO);

	//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
	paquetemov.position = p->getRenderState()->getPosition();
	paquetemov.rotation = p->getRenderState()->getRotation();
	paquetemov.velocidad = p->getVelocity();
	paquetemov.guid = p->getGuid();
	paquetemov.name = p->getName();
	
	

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



void Cliente::lanzarGranada(TGranada g) {

	RakNet::BitStream bsOut;
	

	bsOut.Write((RakNet::MessageID)LANZAR_GRANADA);

	bsOut.Write(g);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}

void Cliente::enviarDisparo(RakNet::RakNetGUID guid) {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)IMPACTO_BALA);

	//////////////////////////////////////////////////////
	//TODO: asumimios que el disparo ha sido certero del jugador que dispara con un enemigo, luego simplemente habria que cambiar la logica de ahora (que es pulsar la R, esta en player)
	//por la de que si la bala colisiona de verdad, si la bala colisiona de verdad desencadenaria toda la logica que se produce al pulsar la R ahora.
	/////////////////////////////////////////////////////
	//bsOut.Write(aqui pasariamos el guid del enemigo al que le hemos dado cuando sepamos con quien ha colisionado la bala)
	//se pueden enviar 2 mensajes seguidos, luego habria que hacer 2 read en el servidor, el primero te dice el guid de quien ha recibido el disparo y el segundo el guid de quien ha disparado

	//ANTES ESTABA ASI
	//bsOut.Write(guid);
	//esto no tiene sentido le estas pasando el guid del que dispara, hay que saber el guid de a quien le da la bala, ahora cogemos uno cual sea de los enteties

	//TODO: le hemos asignado id=3 a los enemigos provisionalmente, para poder restarle vida a un enemigo puesto que no sabriamos su id.
	bsOut.Write(guid);
	printf("envio mensaje del disparo\n");
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}


void Cliente::enviarDesconexion() {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DESCONECTADO);
	bsOut.Write(1);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

	

	//salir = true;
}

void Cliente::dispararBala(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation) {

	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DISPARAR_BALA);
	TBala bala;
	bala.direction = direction;
	bala.position = position;
	bala.finalposition = finalposition;
	bala.rotation = rotation;
	bala.guid = EntityManager::i().getEntity(1000)->getGuid();
	bsOut.Write(bala);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();

}


void Cliente::apagar() {
	if (conectado) {
		hilo->detach();
	}
	//Borrar todas las cosas de raknet
	//delete packet;
	//delete peer;
}