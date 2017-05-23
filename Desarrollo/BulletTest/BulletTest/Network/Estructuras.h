#pragma once
#include <RakPeerInterface.h>
#include <RakNetTypes.h>
#include <RakNetTime.h>
#include <GetTime.h>
#include <iostream>
#include <MessageIdentifiers.h>
#include <Clock.hpp>
#include <vec3.hpp>
#include <CharacterTypes.h>


#pragma pack(push, 1)
struct TPlayer {
	unsigned char mID;
	RakNet::RakNetGUID guid;
	std::string name;
	int color;
	bool available;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct RakID {
	unsigned char mID;
	RakNet::RakNetGUID guid;

	
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TMovimiento {
	unsigned char useTimeStamp;
	RakNet::Time timeStamp;
	unsigned char mID;
	bool isDying;
	bool isOnGround;
	int currentWeapon;
	bool isMoving;
	Vec3<float> position;
	Vec3<float> rotation;
	RakNet::RakNetGUID guid;
};
#pragma pack(pop)


#pragma pack(push, 1)
struct TPing {
	unsigned char mID;
	RakNet::Time ping;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TBala {
	unsigned char mID;
	Vec3<float> position;
	Vec3<float> direction;
	Vec3<float> finalposition;
	Vec3<float> rotation;
	Vec3<float> orientation;
	RakNet::RakNetGUID guid;

	

};
#pragma pack(pop)


#pragma pack(push, 1)
struct TImpactoBala {
	unsigned char mID;
	float damage;
	RakNet::RakNetGUID guidImpactado;
	RakNet::RakNetGUID guidDisparado;
	
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TImpactoRocket {
	unsigned char mID;
	float damage;
	RakNet::RakNetGUID guidImpactado;
	RakNet::RakNetGUID guidDisparado;

	
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TGranada {
	unsigned char mID;
	Vec3<float> origen;
	Vec3<float> direction;
	RakNet::RakNetGUID guid;

	
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TImpulso {
	unsigned char mID;
	Vec3<float> fuerza;
	RakNet::RakNetGUID guid;

	

};
#pragma pack(pop)

#pragma pack(push, 1)
struct TKill{
	unsigned char mID;
	RakNet::RakNetGUID guidKill;
	RakNet::RakNetGUID guidDeath;


};
#pragma pack(pop)

#pragma pack(push, 1)
struct TFilaTabla {
	unsigned char mID;
	std::string name;
	RakNet::RakNetGUID guid;
	int kills;
	int deaths;
	int puntuacion;


};
#pragma pack(pop)

#pragma pack(push, 1)
struct TDropServer {
	unsigned char mID;
	int id;
	Clock tiempo;


};
#pragma pack(pop)

#pragma pack(push, 1)
struct TId {
	unsigned char mID;
	int id;
	RakNet::RakNetGUID guid;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TSyncMessage {
	unsigned char mID;

	unsigned char packageType;
	RakNet::RakNetGUID origen;
	RakNet::RakNetGUID destino;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TGameInfo {
	unsigned char mID;

	RakNet::RakNetGUID creador;
	std::string name;
	int gameMode;
	int numBots;
	int maxKills;
	int playersTotales;
	std::string map;

};
#pragma pack(pop)



struct TLogInfo {
	unsigned char mID;
	std::string info;
};

enum GameMessages {
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
	FIN_PARTIDA = ID_USER_PACKET_ENUM + 29,
	SYNC = ID_USER_PACKET_ENUM + 30,
	PING = ID_USER_PACKET_ENUM + 31,
	CREAR_PARTIDA = ID_USER_PACKET_ENUM + 32,
	CREAR_LOBBY = ID_USER_PACKET_ENUM + 33,
	UNIRSE_LOBBY = ID_USER_PACKET_ENUM + 34,
	EMPEZAR_PARTIDA = ID_USER_PACKET_ENUM + 35,
	NUEVO_BOT = ID_USER_PACKET_ENUM + 36,
	UNIRSE_PARTIDA = ID_USER_PACKET_ENUM + 37,
	RECIBO_DATOS = ID_USER_PACKET_ENUM + 38,
	TERMINAR_PARTIDA = ID_USER_PACKET_ENUM + 39,
	CARGA_COMPLETA = ID_USER_PACKET_ENUM + 40,
	SOLICITAR_INFO = ID_USER_PACKET_ENUM + 41
};
