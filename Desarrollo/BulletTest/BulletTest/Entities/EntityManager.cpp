
#include <iostream>
#include "EntityManager.h"

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
	for (auto i = m_entities.begin(); i != m_entities.end(); ++i) {
		i->second->updateRender(interpolation);
	}
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
