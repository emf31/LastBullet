#pragma once
#include <Partida.h>
#include <NetworkManager.h>

class World {
public:
	
	~World();

	static World& i() {
		static World singleton;
		return singleton;
	}

	void inicializar(const std::string& mapa);
	void apagar();

	bool gamestarted = false;

private:

	//Partida* partida;

	World() { }
};