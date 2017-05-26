#pragma once
#include <unordered_map>
#include "../Otros/Time.hpp"
#include "Entity.h"
#include "../Estructuras.h"
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h> 
#include "Life.h"
#include "../DropObject.h"

class EntityManager
{
public:
	static EntityManager& i() {
		static EntityManager singleton;
		return singleton;
	}
	//Envia un nuevo player a todos los clientes
	void sendPlayer(TPlayer &p, RakNet::RakPeerInterface *peer);
	void sendBot(TPlayer &p, const RakNet::RakNetGUID& host, RakNet::RakPeerInterface *peer);
	//este metodo ahora envia la posicion y la rotacion del jugador
	void enviaNuevaPos(RakNet::BitStream& bitStream, RakNet::RakNetGUID packetOwner, RakNet::RakNetGUID gameOwner, RakNet::RakPeerInterface *peer);
	void lanzarGranda(TGranada &g, RakNet::RakNetGUID owner, RakNet::RakPeerInterface *peer);
	void enviaDesconexion(RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer);
	void enviarTerminarPartida(RakNet::RakNetGUID& owner, RakNet::RakPeerInterface *peer);
	void enviaDisparado(TImpactoBala &imp, RakNet::RakNetGUID &dispara, RakNet::RakPeerInterface *peer);
	void enviaDisparadoRocket(TImpactoRocket &impact, RakNet::RakPeerInterface *peer);
	void notificarMuerte(RakID &p, RakNet::RakPeerInterface *peer);
	void enviaTiempoActualVida(Life *l, RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer);
	void enviaTiempoActualArma(DropObject *d, RakNet::RakNetGUID &guid, RakNet::RakPeerInterface *peer);
	void enviarDisparoCliente(TBala &b, RakNet::RakNetGUID owner, RakNet::RakPeerInterface *peer);
	void enviarDisparoClienteRocket(TBala &b, RakNet::RakNetGUID owner, RakNet::RakPeerInterface *peer);
	void VidaCogida(TId &idVida, RakNet::RakPeerInterface *peer);
	void ArmaCogida(TId &idArma, RakNet::RakPeerInterface *peer);
	void mostrarClientes();
	void enviaImpulso(TImpulso &impulso, RakNet::RakPeerInterface *peer);
	void aumentaKill(TKill& kill, int MaxKills, RakNet::RakPeerInterface * peer);
	void aumentaMuerte(TKill& kill, RakNet::RakPeerInterface * peer);
	void enviaFila(RakNet::RakPeerInterface *peer, TFilaTabla fila);
	void enviaSync(RakNet::RakPeerInterface *peer,TSyncMessage sync);;
	void empezarPartida(RakNet::RakPeerInterface *peer, TGameInfo& info);;
	void notificarDisponibilidad(RakID &p, RakNet::RakPeerInterface *peer);

	//Inicializa todas las entities
	void inicializar();

	void borrarContenido();
	//Borra el entity manager(borramos el mapa y los punteros a entities)
	void apagar();

	//Registra una entity en el mapa
	void registerEntity(Entity* entity);
	//Borra una entity del mapa
	void removeEntity(Entity* entity);
	Entity * getRaknetEntity(RakNet::RakNetGUID guid);
	Entity * getEntityID(int id);

	int getNumJugadores() const { return m_jugadores.size(); }

	std::list<Entity*> getAllPlayers();


private:
	EntityManager(EntityManager const&);
	EntityManager() { m_nextID = 0;  m_jugadores = std::unordered_map<unsigned long, Entity*>();
	}

	int m_nextID;
	std::unordered_map<unsigned long, Entity*> m_jugadores;
	std::unordered_map<int, Entity*> m_entities;
	std::unordered_map <unsigned long, TFilaTabla> m_tabla;

};

