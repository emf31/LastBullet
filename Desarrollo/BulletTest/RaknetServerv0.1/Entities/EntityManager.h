#pragma once
#include <unordered_map>
#include "../BulletTest/BulletTest/Otros/Time.hpp"
#include "Entity.h"
#include "../Estructuras.h"
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h> 

class EntityManager
{
public:
	static EntityManager& i() {
		static EntityManager singleton;
		return singleton;
	}
	//Envia un nuevo player a todos los clientes
	void sendPlayer(TPlayer &p, RakNet::RakPeerInterface *peer);


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
	Entity* getEntity(int id);

private:
	EntityManager(EntityManager const&);
	EntityManager() { m_nextID = 0; m_entities = std::unordered_map<int, Entity*>(); }

	int m_nextID;
	std::unordered_map<int, Entity*> m_entities;

};

