#pragma once
#include <unordered_map>
#include "../BulletTest/BulletTest/Otros/Time.hpp"
#include "Entity.h"
#include "../Estructuras.h"
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h> 
#include "Life.h"

class EntityManager
{
public:
	static EntityManager& i() {
		static EntityManager singleton;
		return singleton;
	}
	//Envia un nuevo player a todos los clientes
	void sendPlayer(TPlayer &p, RakNet::RakPeerInterface *peer);
	//este metodo ahora envia la posicion y la rotacion del jugador
	void enviaNuevaPos(TPlayer &p, RakNet::RakPeerInterface *peer);
	void lanzarGranda(TGranada &g, RakNet::RakPeerInterface *peer);
	void enviaDesconexion(RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer);
	void enviaDisparado(RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer); 
	void notificarMuerte(TPlayer &p, RakNet::RakPeerInterface *peer);
	void enviaTiempoActualVida(Life *l, RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer);
	void enviarDisparoCliente(TBala &b, RakNet::RakPeerInterface *peer);
	void VidaCogida(int idVida, RakNet::RakPeerInterface *peer);
	void mostrarClientes();


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
	Entity * EntityManager::getRaknetEntity(RakNet::RakNetGUID guid);
	Entity * EntityManager::getEntityID(int id);

private:
	EntityManager(EntityManager const&);
	EntityManager() { m_nextID = 0;  m_jugadores = std::unordered_map<unsigned long, Entity*>();
	}

	int m_nextID;
	std::unordered_map<unsigned long, Entity*> m_jugadores;
	std::unordered_map<int, Entity*> m_entities;

};

