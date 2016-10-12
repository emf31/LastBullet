#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "RaknetStuff.h"
#include "Player.h"



void escribirMensaje(RakNet::RakPeerInterface *peer, RakNet::RakNetGUID servidor) {
	RakNet::Packet *packet;
	std::cout << "Escribe tu mensaje2 " << std::endl;
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)135);
	std::string str;
	std::cin >> str;
	bsOut.Write(str);
	peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor, false);
}

void cliente(RakNet::RakPeerInterface *peer, RakNet::SystemAddress *servidor,int *llega) {
	RakNet::Packet *packet;
	std::string str;
	RakNet::BitStream bsOut;

	RakNet::BitStream bsOut2;
	RakNet::RakNetGUID servidor2;
	int conectado = 0;
	while (1) {
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			
			switch (packet->data[0])
			{
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
			case ID_CONNECTION_REQUEST_ACCEPTED:
				printf("Nuestra conexion se ha aceptado.\n");
				servidor = &packet->systemAddress;
				
				std::cout << "Escribe tu mensaje " << std::endl;
				
				bsOut.Write((RakNet::MessageID)ID_GAME_MESSAGE_1);
				if (conectado==0) {
					servidor2 = packet->guid;
				}
				
				//std::cin >> str;
				bsOut.Write("hola");
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
				bsOut.Reset();
				*llega = 1;
				conectado = 1;
				
				
				break;
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;
			}
		}
		if (conectado) {
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
				//escribirMensaje(peer, servidor2);
				std::cout << "Envio un float " << std::endl;

				bsOut.Write((RakNet::MessageID)MENSAJE_POSICION);
				
				struct posicion
				{
					float x, y, z;
				} myVector;

				//sf::Vector3f mivector(16.5f, 24.f, 5.1f);
				//bsOut.WriteVector(mivector.x, mivector.y, mivector.z);
				//bsOut.WriteVector(16.5f, 24.f, 5.1f);
				//bsOut.WriteVector(16.2, 24.3, 5.4);
				myVector.x = 1.0f;
				myVector.y = 2.4f;
				myVector.z = 6.1f;
				//bsOut.WriteVector(myVector.x, myVector.y, myVector.z);
				//std::cin >> str;
				bsOut.WriteFloat16(7.2f, 0, 9);
				bsOut.WriteFloat16(1.0f, 0, 9);
				bsOut.WriteFloat16(3.5f, 0, 9);
				
				//bsOut.Write("hola2");
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
				
				bsOut.Reset();
				*llega = 1;
				conectado = 1;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				//escribirMensaje(peer, servidor2);
				std::cout << "Envio un string " << std::endl;

				bsOut.Write((RakNet::MessageID)MENSAJE_NOMBRE);
				
				
				//std::cin >> str;

				bsOut.Write("RuCri95");
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
				bsOut.Reset();
				*llega = 1;
				conectado = 1;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
				//escribirMensaje(peer, servidor2);
				std::cout << "Envio un objeto " << std::endl;

				typedef struct Entity
				{
					std::string nombre;
					float x, y,z;
					int vida;
					int municion;
					
				} TEntity;

				TEntity player;
				std::cout << "Introduce el nombre del player " << std::endl;
				std::cin >> str;
				player.nombre = str;
				player.x = 5.4f;
				player.y = 8.4f;
				player.z = 3.4f;
				//std::cout << "Introduce la vida " << std::endl;
				player.vida = 10;
				//std::cout << "Introduce la municion " << std::endl;
				player.municion = 100;
				bsOut.Write((RakNet::MessageID)OBJETO);


				//std::cin >> str;
				bsOut.Write(player);
				peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
				//peer->Send((const char*)&player, sizeof(player), HIGH_PRIORITY, RELIABLE_ORDERED, 0, servidor2, false);
				bsOut.Reset();
				*llega = 1;
				conectado = 1;
			}
		}
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Raknet Client v0.1");
	sf::CircleShape shape(100.f);
	char str[512];
	int llega = 0;
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::SocketDescriptor sd;
	RakNet::SystemAddress *servidor;
	printf("Introduce la IP \n");
	std::cin >> str;
	std::cout << "Conectando al servidor " << str << ":" << SERVER_PORT << std::endl;
	peer->Startup(1, &sd, 1);
	peer->Connect(str, SERVER_PORT, 0, 0);
	std::thread first(cliente, peer, servidor, &llega);
	//RaknetStuff::Conectar("127.0.0.1", 65535);
	
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(208,208,208,1));
		window.draw(shape);
		window.display();
	}
	return 0;
}