#include "Player.h"

Player::Player(std::string name, float x, float y){
	vida = 100;
	municion = 100;

	posicion.x = x;
	posicion.y = y;

	nombre = name;

	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
}
Player::Player() {
	
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
}


Player::~Player(){

}


void Player::restablecerMovimiento() {
	movimiento = 0;
}

float Player::getVida(){
	return 0.0f;
}

Tposicion Player::getPos() {
	return posicion;
}

void Player::setPosicion(Tposicion pos) {
	posicion = pos;
}

float Player::getMunicion(){
	return municion;
}

void Player::setVida(float nVida) {
	vida = nVida;
}

void Player::disparar() {
	if (municion != 0) {
		municion--;
	} else {
		municion = 100;
	}
}



void Player::setNombre(std::string name) {
	nombre = name;
}

 void Player::setGuid(RakNet::RakNetGUID rkguid) {
	guid = rkguid;
}

RakNet::RakNetGUID Player::getGuid() {
	return guid;
}

int Player::getInput() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		//posY = posY - 0.1f;
		movimiento = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//posX = posX - 0.1f;
		movimiento = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		//posX = posX + 0.1f;
		movimiento = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//posY = posY + 0.1f;
		movimiento = 4;
	}
	return movimiento;
}