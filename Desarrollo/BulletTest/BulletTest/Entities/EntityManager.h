#pragma once

//#include <InGameHUD.h>
#include <unordered_map>
#include <Time.hpp>
#include "Entity.h"
#include <unordered_set>
#include <list>
#include <Estructuras.h>
#include <string>



static const int PLAYER = 1000;

class InGameHUD;

class EntityManager
{
public:
	static EntityManager& i() {
		static EntityManager singleton;
		return singleton;
	}

	int numClientes() {
		return m_jugadores.size();
	}
	
	void mostrarClientes();
	void muestraPosClientes();

	void inicializarEntityManager() {
		m_nextID = 0;
	}

	//Inicializa todas las entities
	void inicializar();
	//Updatea todas las entities
	void update(Time elapsedTime);
	//Updatea la posicion de render de todas las entities
	void updateRender(float interpolation);


	void handleInput();
	//Carga el contenido de todas las entities
	void cargarContenido();
	//Borra el contenido de todas las entities
	void borrarContenido();
	//Borra el entity manager(borramos el mapa y los punteros a entities)
	void apagar();

	//Registra una entity en el mapa
	void registerEntity(Entity* entity);

	//Borra una entity del mapa
	void removeEntity(Entity* entity);

	//Borra la cola de borrado de entities, se llama en cada iteracion
	void cleanDeleteQueue();

	void cambiaTabla(TFilaTabla fila) {
		std::cout << "Recibo como fila a:  " << fila.name << std::endl;
		m_tabla[RakNet::RakNetGUID::ToUint32(fila.guid)] = fila;
	}
	void muestraTabla(InGameHUD *ingame);
	void aumentaKill(RakNet::RakNetGUID &guid) {
		TFilaTabla *fila;
		fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
		fila->kills++;
	}
	void aumentaMuerte(RakNet::RakNetGUID &guid) {
		TFilaTabla *fila;
		fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
		fila->deaths++;
	}

	Entity* getEntity(int id);
	Entity* getRaknetEntity(RakNet::RakNetGUID guid);
	std::list<Entity*> getCharacters();
	std::list<Entity*> getEnemies();
	std::list<Entity*> getLifeObjects();
	std::list<Entity*> getWeapons();
	std::list<Entity*> getRockets();
	std::list<Entity*> getPistolas();
	std::list<Entity*> getAsalto();
	std::list<Entity*> getAllEntitiesTriggerables();

	

private:
	EntityManager(EntityManager const&);
	EntityManager() { 
	}

	int m_nextID;
	
	std::unordered_map<int, Entity*> m_entities;
	std::unordered_map<unsigned long, Entity*> m_jugadores;
	std::unordered_map <unsigned long, TFilaTabla> m_tabla;
	
	std::unordered_set<Entity*> delete_set;

};

