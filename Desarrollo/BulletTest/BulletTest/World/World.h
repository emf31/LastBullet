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

	void inicializar();
	void apagar();


	Partida* getPartida() const { return partida; }

private:


	Partida* partida;

	World();
};