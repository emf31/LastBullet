#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <thread> 
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID

#define SERVER_PORT 65535

enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1
};

void escribirMensaje(RakNet::RakPeerInterface *peer, RakNet::SystemAddress *servidor) {
	/*MessageID useTimeStamp; // Assign this to ID_TIMESTAMP
	RakNet::Time timeStamp; // Put the system time in here returned by RakNet::GetTime()
	MessageID typeId; // This will be assigned to a type I've added after ID_USER_PACKET_ENUM, lets say ID_SET_TIMED_MINE
	useTimeStamp = ID_TIMESTAMP;
	timeStamp = RakNet::GetTime();
	typeId = ID_SET_TIMED_MINE;
	Bitstream myBitStream;
	myBitStream.Write(useTimeStamp);
	myBitStream.Write(timeStamp);
	myBitStream.Write(typeId);
	// Assume we have a Mine* mine object
	myBitStream.Write(mine->GetPosition().x);
	myBitStream.Write(mine->GetPosition().y);
	myBitStream.Write(mine->GetPosition().z);
	myBitStream.Write(mine->GetNetworkID()); // In the struct this is NetworkID networkId
	myBitStream.Write(mine->GetOwner()); // In the struct this is SystemAddress systemAddress*/
	RakNet::Packet *packet;
	while (1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
			//packet = new RakNet::Packet();
			packet = new RakNet::Packet();
			std::cout << "Escribe tu mensaje " << std::endl;
			RakNet::BitStream bsOut;
			bsOut.Write((RakNet::MessageID)ID_GAME_MESSAGE_1);
			std::string str;
			std::cin >> str;
			bsOut.Write(str);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, *servidor, false);
		}
	}

}

void cliente(RakNet::RakPeerInterface *peer, RakNet::SystemAddress *servidor,int *llega) {
	RakNet::Packet *packet;
	while (1) {
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
			std::thread second(escribirMensaje, peer, servidor);
			switch (packet->data[0])
			{
			case ID_REMOTE_DISCONNECTION_NOTIFICATION:
				printf("Otro cliente se ha desconectado.\n");
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
				*llega = 1;
				
				
				break;
			default:
				printf("Un mensaje con identificador %i ha llegado.\n", packet->data[0]);
				break;
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
	
	
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(208,208,208,1));
		//window.draw(shape);
		window.display();
	}
	return 0;
}