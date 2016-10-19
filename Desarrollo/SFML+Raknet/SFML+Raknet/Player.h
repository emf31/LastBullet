#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <RakNetTypes.h>
#include <RakPeerInterface.h>

typedef struct {
	float x, y;
}Tposicion;

class Player{

public:
	Player(std::string name, float x, float y);
	Player();
	~Player();



	float getVida();
	Tposicion getPos();
	float getMunicion();

	void setVida(float nVida);
	void disparar();

	void setPosicion(Tposicion pos);
	void restablecerMovimiento();
	void setNombre(std::string name);

	void setGuid(RakNet::RakNetGUID rkguid);
	RakNet::RakNetGUID getGuid();
	int getInput();

	int conectado = 0;
	sf::CircleShape shape;
	std::string nombre;
	float vida;
	float municion;
	int actualizado = 0;
	int movimiento = 0;
	Tposicion posicion;

private:

	RakNet::RakNetGUID guid;
};

