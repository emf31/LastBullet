#include "EntityManager.h"
#include "../Estructuras.h"

void EntityManager::sendPlayer(TPlayer & p, RakNet::RakPeerInterface *peer)
{
	//TODO: CAMBIAR ESTO POR UNA LISTA QUE SOLO TE DEVUELVA PLAYERS
	RakNet::BitStream bsOut;
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		//enviamos el nuevo player a todos los clientes que habian en el servidor
		bsOut.Write((RakNet::MessageID)NUEVO_PLAYER);
		bsOut.Write(p);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		bsOut.Reset();

		//enviamos todos los clientes que habian en el servidor al nuevo player
		TPlayer nuevocli;
		nuevocli.guid = i->second->getGuid();
		nuevocli.name = i->second->getName();
		nuevocli.position = i->second->getRenderState()->getPosition();
		bsOut.Write((RakNet::MessageID)NUEVO_CLIENTE);
		bsOut.Write(nuevocli);
		peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p.guid, false);
		bsOut.Reset();
	}
}

void EntityManager::inicializar()
{
	std::unordered_map<int, Entity*>::iterator iter = m_entities.begin();
	for (; iter != m_entities.end(); ++iter) {
		iter->second->inicializar();
	}

}

void EntityManager::update(Time elapsedTime)
{
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
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
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		i->second->handleInput();
	}
}



void EntityManager::cargarContenido()
{
	std::unordered_map<int, Entity*>::iterator i = m_entities.begin();
	for (; i != m_entities.end(); ++i) {
		i->second->cargarContenido();
	}
}

void EntityManager::borrarContenido()
{
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		i->second->borrarContenido();
	}
}

void EntityManager::apagar()
{
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		//borramos la entities
		delete i->second;
		i->second = 0;
	}
	//vaciamos el contenido del mapa
	m_entities.clear();
}

void EntityManager::registerEntity(Entity * entity)
{
	// comprobamos si la Entity tiene un ID
	if (entity->getID() == -1) {
		//Si no tiene, le damos una que este disponible
		//Lo hago asi porque no puedo asegurar que el id siguiente no este asignado ya
		while (m_entities.find(m_nextID) != m_entities.end()) {
			++m_nextID;
		}
		entity->setID(m_nextID++);
	}
	//en caso de que tenga ya id comprobamos que no este en uso
	else if (m_entities.find(entity->getID()) != m_entities.end()) {
		//mostramos error
		std::cout << "Error registrando entity de ID: " + entity->getID() << std::endl;
		return;
	}
	//si todo ha ido bien le asignamos el entity al map
	m_entities[entity->getID()] = entity;

}

void EntityManager::removeEntity(Entity * entity)
{
	auto found = m_entities.find(entity->getID());
	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_entities.end()) {
		m_entities.erase(found);
	}
}

Entity * EntityManager::getEntity(int id)
{
	auto found = m_entities.find(id);
	if (found != m_entities.end())
		return found->second;
	//no existe devolvemos 0
	return NULL;
}
