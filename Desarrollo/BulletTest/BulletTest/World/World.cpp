#include "World.h"
#include <EntityManager.h>
#include <Map.h>
#include <PhysicsEngine.h>

World::World() : partida(nullptr)
{
	partida = new Partida();
}

World::~World()
{
	delete partida;
	partida = nullptr;
}


void World::inicializar()
{
	
	partida->inicializar();

	//Esto resetea valores
	EntityManager::i().inicializarEntityManager();

	std::string str = "../media/";
	str.append(partida->getCurrentMap());
	Map::i().inicializar(str);

	//LLama al inicializar de todas las entities
	EntityManager::i().inicializar();

	EntityManager::i().cargarContenido();


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
	partida->apagar();
}
