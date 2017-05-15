#include "AsyncEnemyFactory.h"
#include <Enemy.h>
#include <EntityManager.h>
#include <EventSystem.h>

AsyncEnemyFactory::AsyncEnemyFactory() : m_enemies()
{
}

AsyncEnemyFactory::~AsyncEnemyFactory()
{
	m_enemies.clear();
}

void AsyncEnemyFactory::addEnemyToBeCreated(TPlayer & p)
{
	EnemyMap::const_iterator it = m_enemies.find(RakNet::RakNetGUID::ToUint32(p.guid));
	if (it != m_enemies.end()) {
		return;
	}

	m_enemies[RakNet::RakNetGUID::ToUint32(p.guid)] = p;
}

void AsyncEnemyFactory::createEnemiesIfAvailable()
{
	//Avoid error on delete element while looping
	for (auto it = m_enemies.cbegin(); it != m_enemies.cend(); /*no increment*/) {
		bool available = it->second.available;
		if (available) {
			Enemy *e = new Enemy(it->second.name, it->second.guid);
			e->inicializar();
			e->cargarContenido();

			EntityManager::i().registerRaknetEntity(e);

			it = m_enemies.erase(it);
		}
		else {
			++it;
		}
	}

	//Si todos los enemigos estan listos notificamos a la partida
	checkIfAllEnemiesReady();
}

void AsyncEnemyFactory::createEnemyIfAvailable(RakNet::RakNetGUID & rakID)
{
	EnemyMap::const_iterator it = m_enemies.find(RakNet::RakNetGUID::ToUint32(rakID));

	if (it != m_enemies.end()) {
		if (it->second.available == true) {
			Enemy *e = new Enemy(it->second.name, rakID);
			e->inicializar();
			e->cargarContenido();

			EntityManager::i().registerRaknetEntity(e);

			m_enemies.erase(RakNet::RakNetGUID::ToUint32(rakID));

			
		}
	}

	//Si todos los enemigos estan listos notificamos a la partida
	checkIfAllEnemiesReady();
}

void AsyncEnemyFactory::markEnemyAsAvailable(RakNet::RakNetGUID & rakID)
{
	EnemyMap::iterator it = m_enemies.find(RakNet::RakNetGUID::ToUint32(rakID));

	if (it != m_enemies.end()) {
		it->second.available = true;
	}
}

void AsyncEnemyFactory::markEnemyAsUnavailable(RakNet::RakNetGUID & rakID)
{
	EnemyMap::iterator it = m_enemies.find(RakNet::RakNetGUID::ToUint32(rakID));

	if (it != m_enemies.end()) {
		it->second.available = false;
	}
}

std::list<TPlayer> AsyncEnemyFactory::getEnemies()
{
	std::list<TPlayer> lista;
	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++) {
		lista.push_back(it->second);
	}

	return lista;
}

void AsyncEnemyFactory::checkIfAllEnemiesReady()
{
	bool ready = true;
	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++) {
		if (!it->second.available) {
			ready = false;
		}
	}
	
	//Todos los enemigos estan listos
	if (ready) {
		Event* ev = new Event();
		ev->event_type = E_ALLPLAYERS_READY;
		EventSystem::i().dispatchNow(ev);
	}
}
