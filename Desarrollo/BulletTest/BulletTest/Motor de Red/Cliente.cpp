
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

Cliente::Cliente()
{
}

void Cliente::update() {
	RakNet::Packet *packet;
	RakNet::BitStream bsOut;
	std::string str;
	TPlayer nuevoplayer;
	RakNet::RakNetGUID desconectado;
	
	int cont = 0;

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
				player->cargarContenido();

				nuevoplayer.guid = player->getGuid();
				nuevoplayer.name = player->getName();
				//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
				nuevoplayer.position = Vec3<float> (0,100,0);
				player->setPosition(nuevoplayer.position);

				GraphicEngine::i().iniciado = true;
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

				Enemy *e = new Enemy(nuevoplayer.name, nuevoplayer.guid);
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
				e->cargarContenido();
				e->setPosition(nuevoplayer.position);




			}
			break;

			case MOVIMIENTO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				//recibo el player
				bsIn.Read(nuevoplayer);
				//recibimos la nueva posicion del cliente que se ha movido y la actualizamos
				Enemy *e = (Enemy*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
				//e->updateEnemigo(nuevoplayer.position);
				//e = nullptr;
				std::cout << "///////////////////INICIO MOVIMIENTO////////////////////////" << std::endl;
				Message msg1(e, "MOVE", (void*)&nuevoplayer);

				MessageHandler::i().sendMessage(msg1);

				EntityManager::i().muestraPosClientes();
				std::cout << "///////////////////FINAL MOVIMIENTO////////////////////////" << std::endl;

			}
			break;

			case DESCONECTADO:
			{

				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				
				bsIn.Read(desconectado);

				EntityManager::i().getRaknetEntity(desconectado)->borrarContenido();
				EntityManager::i().removeEntity(EntityManager::i().getRaknetEntity(desconectado));

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
				if (EntityManager::i().getEntity(1)->restaVida() <= 0) {
					std::cout << "ME HAN MATADO" << std::endl;
					std::cout << "HIJO PUTA EL CAMPERO" << std::endl;
					//si entras aqui es porque te has quedado sin vida, se lo comunicas el servidor para que se lo comunique a todos y te vuelva a asignar una posicion.

					bsOut.Write((RakNet::MessageID)MUERTE);

					nuevoplayer.guid = EntityManager::i().getEntity(1)->getGuid();
					nuevoplayer.name = EntityManager::i().getEntity(1)->getName();
					nuevoplayer.position = EntityManager::i().getEntity(1)->getRenderState()->getPosition();


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

				if (EntityManager::i().getRaknetEntity(nuevoplayer.guid)->getID()==1) {
					//es el player
					Player* player= (Player*)EntityManager::i().getRaknetEntity(nuevoplayer.guid);
					player->setPosition(nuevoplayer.position);			
					player = nullptr;

					//TODO: esto en verdad no iria aqui, esto deberia de estar en algun metodo que resetee, la vida y la municion despues de que pase un cierto tiempo para reaparecer
					//ademas que desactivara el draw de esta entetity para que no puedeas moverte ni nada mientras estas muerto.
					EntityManager::i().getEntity(1)->resetVida();
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
	//bucleCliente();
	//return std::thread(&Cliente::bucleCliente, this);
	hilo= new std::thread(&Cliente::update, this);
}

void Cliente::esperar() {
	hilo->join();
}

void Cliente::enviarPos(Player* p) {

	RakNet::BitStream bsOut;
	TPlayer paquetemov;

	bsOut.Write((RakNet::MessageID)MOVIMIENTO);

	paquetemov.guid = p->getGuid();
	paquetemov.name = p->getName();
	//TODO: asumimios que tanto el servidor como el cliente crean el player en el (0,0) en un futuro el servidor deberia enviar la posicion inicial al cliente.
	paquetemov.position = p->getRenderState()->getPosition();
	

	bsOut.Write(paquetemov);
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
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
	bsOut.Reset();
}