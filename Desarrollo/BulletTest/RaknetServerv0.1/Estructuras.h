#pragma once
#include "../../BulletTest/Otros/vec3.hpp"
#include <RakPeerInterface.h>
#include <iostream>
#include <MessageIdentifiers.h>

typedef struct {
	Vec3<float> position;
	Vec3<float> velocidad;
	Vec3<float> rotation;
	RakNet::RakNetGUID guid;
	std::string name;
}TPlayer;

typedef struct {
	Vec3<float> position;
	Vec3<float> direction;
	Vec3<float> finalposition;
	Vec3<float> rotation;
	RakNet::RakNetGUID guid;
}TBala;

typedef struct {
	Vec3<float> origen;
	Vec3<float> direction;
	RakNet::RakNetGUID guid;
}TGranada;

typedef struct {
	int id;
	Clock tiempo;
}TVidaServer;


typedef struct {
	float damage;
	RakNet::RakNetGUID guid;
}TImpactoRocket;



enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	MENSAJE_POSICION = ID_USER_PACKET_ENUM + 2,
	MENSAJE_NOMBRE = ID_USER_PACKET_ENUM + 3,
	NUEVO_PLAYER = ID_USER_PACKET_ENUM + 4,
	GUID_NUESTRO = ID_USER_PACKET_ENUM + 5,
	MOVIMIENTO = ID_USER_PACKET_ENUM + 6,
	LISTA_CLIENTES = ID_USER_PACKET_ENUM + 7,
	NUEVO_CLIENTE = ID_USER_PACKET_ENUM + 8,
	ELIMINAR_CLIENTE = ID_USER_PACKET_ENUM + 9,
	ACTUALIZA_CLIENTE = ID_USER_PACKET_ENUM + 10,
	DESCONECTADO = ID_USER_PACKET_ENUM + 11,
	IMPACTO_BALA = ID_USER_PACKET_ENUM + 12,
	MUERTE = ID_USER_PACKET_ENUM + 13,
	DISPARAR_BALA = ID_USER_PACKET_ENUM + 14,
	LANZAR_GRANADA = ID_USER_PACKET_ENUM + 15,
	VIDA_COGIDA = ID_USER_PACKET_ENUM + 16,
	NUEVA_VIDA = ID_USER_PACKET_ENUM + 17,
	TIEMPO_VIDA = ID_USER_PACKET_ENUM + 18,
	DISPARAR_ROCKET = ID_USER_PACKET_ENUM + 19,
	IMPACTO_ROCKET = ID_USER_PACKET_ENUM + 20,
	NUEVA_ARMA = ID_USER_PACKET_ENUM + 21,
	ARMA_COGIDA = ID_USER_PACKET_ENUM + 22

};
