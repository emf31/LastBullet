#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <RakNetTypes.h>
#include <RakPeerInterface.h>
class Player{

public:
	Player(std::string name, float x, float y);
	Player();
	~Player();

	float getVida();
	sf::Vector2f getPos();
	float getMunicion();

	void setVida(float nVida);
	void disparar();

	void setPosicion(float x, float y);
	void setNombre(std::string name);

	void setGuid(RakNet::RakNetGUID rkguid);
	RakNet::RakNetGUID getGuid();
	int getInput();

	int conectado = 0;
	sf::CircleShape *shape;
	std::string nombre;
	float vida;
	float posX, posY;
	float municion;
	int actualizado = 0;
	int movimiento = 0;

private:

	RakNet::RakNetGUID guid;
};

