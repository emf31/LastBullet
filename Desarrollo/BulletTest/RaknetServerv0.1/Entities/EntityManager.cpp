#include "EntityManager.h"
#include "../Estructuras.h"

void EntityManager::sendPlayer(TPlayer & p, RakNet::RakPeerInterface *peer)
{
	TPlayer nuevocli;
	//TODO: CAMBIAR ESTO POR UNA LISTA QUE SOLO TE DEVUELVA PLAYERS
	RakNet::BitStream bsOut;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		//enviamos el nuevo player a todos los clientes que habian en el servidor
		bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);
		bsOut.Write(p);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		bsOut.Reset();

		//enviamos todos los clientes que habian en el servidor al nuevo player
	
		nuevocli.guid = i->second->getGuid();
		nuevocli.name = i->second->getName();
		nuevocli.position = i->second->getRenderState()->getPosition();
		bsOut.Write((RakNet::MessageID)NUEVO_CLIENTE);
		bsOut.Write(nuevocli);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p.guid, false);
		bsOut.Reset();
	}
}

void EntityManager::enviaNuevaPos(TPlayer & p, RakNet::RakPeerInterface *peer)
{
	
	//TODO: CAMBIAR ESTO POR UNA LISTA QUE SOLO TE DEVUELVA PLAYERS
	RakNet::BitStream bsOut;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != p.guid) {

			//enviamos la posicion actualizada del player a todos los clientes
			bsOut.Write((RakNet::MessageID)MOVIMIENTO);
			bsOut.Write(p);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
			bsOut.Reset();
		}

	}
}

void EntityManager::inicializar()
{
	std::unordered_map<unsigned long, Entity*>::iterator iter = m_jugadores.begin();
	for (; iter != m_jugadores.end(); ++iter) {
		iter->second->inicializar();
	}

}

void EntityManager::update(Time elapsedTime)
{
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		i->second->update(elapsedTime);
	}
}

void EntityManager::updateRender(float interpolation)
{
	/*for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		i->second->updateRender(interpolation);
	}*/
}

void EntityManager::handleInput()
{
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		i->second->handleInput();
	}
}



void EntityManager::cargarContenido()
{
	std::unordered_map<unsigned long, Entity*>::iterator i = m_jugadores.begin();
	for (; i != m_jugadores.end(); ++i) {
		i->second->cargarContenido();
	}
}

void EntityManager::borrarContenido()
{
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		i->second->borrarContenido();
	}
}

void EntityManager::apagar()
{
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		//borramos la entities
		delete i->second;
		i->second = 0;
	}
	//vaciamos el contenido del mapa
	m_jugadores.clear();
}

void EntityManager::registerEntity(Entity * entity)
{

		m_jugadores[RakNet::RakNetGUID::ToUint32(entity->getGuid())] = entity;
	
}

void EntityManager::removeEntity(Entity * entity)
{
	auto found = m_jugadores.find(RakNet::RakNetGUID::ToUint32(entity->getGuid()));
	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_jugadores.end()) {
		m_jugadores.erase(found);
	}
}



Entity * EntityManager::getRaknetEntity(RakNet::RakNetGUID guid)
{
	auto found = m_jugadores.find(RakNet::RakNetGUID::ToUint32(guid));
	if (found != m_jugadores.end())
		return found->second;
	//no existe devolvemos 0
	return NULL;
}