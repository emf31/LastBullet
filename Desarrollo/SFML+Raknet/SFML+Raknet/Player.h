#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "RaknetStuff.h"
class Player{

public:
	Player(std::string name, float x, float y);
	~Player();

	float getVida();
	sf::Vector2f getPos();
	float getMunicion();

	void setVida(float nVida);
	void disparar();

	void setPosicion(float x, float y);
	void setNombre(std::string name);

	void setGuid(RakNet::RakNetGUID rkguid);

private:
	float vida;
	float posX, posY;
	float municion;

	std::string nombre;
	sf::CircleShape shape;

	RakNet::RakNetGUID guid;
};

