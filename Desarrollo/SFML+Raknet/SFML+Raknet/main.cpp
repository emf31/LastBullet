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
	
	sf::CircleShape shape2;
	shape2.setFillColor(sf::Color::Red);
	shape2.setRadius(100.f);
	sf::CircleShape shape3;
	shape3.setFillColor(sf::Color::Black);
	shape3.setRadius(100.f);
	int i = 0;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(208, 208, 208, 1));
		player->shape.setPosition(player->getPos().x, player->getPos().y);
		window.draw(player->shape);
		for (i = 0; i < raknet->clientArray.size(); i++) {
			if (i == 0) {
				//raknet->clientArray.at(i)->shape.setPosition(raknet->clientArray.at(i)->getPos().x, raknet->clientArray.at(i)->getPos().y);
				shape2.setPosition(raknet->clientArray.at(i)->getPos().x, raknet->clientArray.at(i)->getPos().y);
			}
			if (i == 1) {
				//raknet->clientArray.at(i)->shape.setPosition(raknet->clientArray.at(i)->getPos().x, raknet->clientArray.at(i)->getPos().y);
				shape3.setPosition(raknet->clientArray.at(i)->getPos().x, raknet->clientArray.at(i)->getPos().y);
			}
		}
		window.draw(shape2);
		window.draw(shape3);
			
		window.display();
	}
	hilo.join();
	return 0;
}