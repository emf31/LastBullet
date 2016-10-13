#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "RaknetStuff.h"
#include "Player.h"

int main() {
	std::string nombre;
	std::cout << "Nombre del player: " << std::endl;
	std::cin >> nombre;
	Player *player = new Player(nombre,10,10);

	RaknetStuff *raknet = new RaknetStuff(player);
	printf("Introduce la IP \n");
	std::string str;
	std::cin >> str;
	std::cout << "Conectando al servidor " << str << ":" << SERVER_PORT << std::endl;

	std::thread hilo = raknet->Conectar(str, SERVER_PORT);
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Raknet Client v0.1");
	
	int i = 0;
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(208,208,208,1));
		window.draw(*player->shape);
		for (i = 0; i < raknet->clientArray.size(); i++) {
			window.draw(*raknet->clientArray.at(i)->shape);
		}
		window.display();
	}
	hilo.join();
	return 0;
}