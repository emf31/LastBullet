#include "World.h"
#include <EntityManager.h>
#include <Map.h>
#include <PhysicsEngine.h>


World::~World()
{
}


void World::inicializar(const std::string& mapa)
{
	

	//Esto resetea valores
	EntityManager::i().inicializarEntityManager();

	partida = new Partida();


	//LLama al inicializar de todas las entities
	EntityManager::i().inicializar();

	EntityManager::i().cargarContenido();

	//partida = new Partida();


	//enviamos los paquetes del vida al servidor para que los cree
	std::list<Entity*>lifeObj = EntityManager::i().getLifeObjects();
	for (std::list<Entity*>::const_iterator it = lifeObj.begin(); it != lifeObj.end(); ++it) {
		TId tID;
		tID.id = (*it)->getID();
		NetworkManager::i().dispatchMessage(tID, NUEVA_VIDA);
	}

	//enviamos los paquetes de armas al servidor para que los cree

	std::list<Entity*>weapon = EntityManager::i().getWeapons();
	for (std::list<Entity*>::const_iterator it = weapon.begin(); it != weapon.end(); ++it) {
		TId tID2;
		tID2.id = (*it)->getID();
		NetworkManager::i().dispatchMessage(tID2, NUEVA_ARMA);
	}
}

void World::apagar()
{
	delete partida;
	partida = nullptr;
}
