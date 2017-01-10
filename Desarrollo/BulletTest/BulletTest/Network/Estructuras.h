#pragma once
#include <vec3.hpp>
#include <RakPeerInterface.h>
#include <iostream>
#include <MessageIdentifiers.h>
#include <Clock.hpp>

typedef struct {
	Vec3<float> position;
	RakNet::RakNetGUID guid;
	std::string name;
}TPlayer;

typedef struct {
	bool isDying;
	Vec3<float> position;
	Vec3<float> rotation;
	RakNet::RakNetGUID guid;
}TMovimiento;

typedef struct {
	float damage;
	RakNet::RakNetGUID guid;
}TImpactoBala;

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
	RakNet::RakNetGUID guidImpactado;
	RakNet::RakNetGUID guidDisparado;
}TImpactoRocket;

typedef struct {
	Vec3<float> fuerza;
	RakNet::RakNetGUID guid;
}TImpulso;

typedef struct {
	//cambio sera 1 o 2, si es un 1 cambia de arma hacia arriba y si es un 2 cambia de arma hacia abajo.
	int cambio;
	RakNet::RakNetGUID guid;
}TCambioArma;

typedef struct {
	std::string name;
	RakNet::RakNetGUID guid;
	int kills;
	int deaths;
	int puntuacion;
}TFilaTabla;


typedef struct {
	RakNet::RakNetGUID guidKill;
	RakNet::RakNetGUID guidDeath;
}TKill;


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
	ARMA_COGIDA = ID_USER_PACKET_ENUM + 22,
	APLICAR_IMPULSO = ID_USER_PACKET_ENUM + 23,
	CAMBIO_ARMA = ID_USER_PACKET_ENUM + 24,
	ACTUALIZA_TABLA = ID_USER_PACKET_ENUM + 25,
	MOSTRAR_TABLA = ID_USER_PACKET_ENUM + 26,
	AUMENTA_KILL = ID_USER_PACKET_ENUM + 27,
	AUMENTA_MUERTE = ID_USER_PACKET_ENUM + 28,
	FIN_PARTIDA = ID_USER_PACKET_ENUM + 29
};
