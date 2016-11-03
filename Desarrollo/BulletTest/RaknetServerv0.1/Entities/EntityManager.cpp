#include "EntityManager.h"
#include "../Estructuras.h"
#include <string>

void EntityManager::sendPlayer(TPlayer & p, RakNet::RakPeerInterface *peer)
{
	TPlayer nuevocli;
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
	
	RakNet::BitStream bsOut;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != p.guid) {
			std::cout << "///////ENVIAMOS POS INICIO////////" << std::endl;
			std::cout << "El player: " << p.name << "se mueve desde: "<< getRaknetEntity(p.guid)->getRenderState()->getPosition().getX()<<","<< getRaknetEntity(p.guid)->getRenderState()->getPosition().getZ() <<" a la nueva pos: " << p.position.getX() << "," << p.position.getZ() << std::endl;
			std::cout << "Enviamos esta nueva pos a: " << i->second->getName() <<"con guid: "<<RakNet::RakNetGUID::ToUint32(i->second->getGuid())<< std::endl;
			//enviamos la posicion actualizada del player a todos los clientes
			bsOut.Write((RakNet::MessageID)MOVIMIENTO);
			bsOut.Write(p);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
			bsOut.Reset();
			std::cout << "///////ENVIAMOS POS FINAL////////" << std::endl;
		}

	}
}

void EntityManager::enviaDesconexion(RakNet::RakNetGUID & guid, RakNet::RakPeerInterface *peer)
{

	
	RakNet::BitStream bsOut;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != guid) {

			//enviamos el guid del cliente que tiene que borrar
			bsOut.Write((RakNet::MessageID)DESCONECTADO);
			bsOut.Write(guid);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
			bsOut.Reset();
		}

	}
}

void EntityManager::enviaDisparado(RakNet::RakNetGUID & guid, RakNet::RakPeerInterface *peer)
{


	RakNet::BitStream bsOut;
		//se envia unicamente al cliente que ha sido disparado

			bsOut.Write((RakNet::MessageID)IMPACTO_BALA);
			//en verdad aqui no habria ni que pasarle nada, solo queremos notificarle que ha sido disparado
			//TODO: en un futuro aqui podriamos pasarle el arma con el que ha sido disparado asi dependiendo del arma con el que ha sido disparado se restara mas vida o menos vida.
			bsOut.Write("pasar el arma con la que disparas");
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, guid, false);
			bsOut.Reset();
		

	
}


void EntityManager::notificarMuerte(TPlayer & p, RakNet::RakPeerInterface *peer)
{


	RakNet::BitStream bsOut;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS
		
			//enviamos la estructura del cliente muerto para que todos cambien la posicion de ese cliente a la nueva pos asignada por el servidor
			bsOut.Write((RakNet::MessageID)MUERTE);
			bsOut.Write(p);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
			bsOut.Reset();
		

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

void EntityManager::mostrarClientes() {

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
	
		i->second->getGuid();
		std::cout << "Nombre del player: " << i->second->getName() << std::endl;
		std::cout << "Posicion: " << i->second->getRenderState()->getPosition().getX() << ", " << i->second->getRenderState()->getPosition().getZ() << std::endl;
		std::cout << "GUID de la Entity: " << RakNet::RakNetGUID::ToUint32(i->second->getGuid()) << std::endl;
		std::cout << "GUID de la Clave: " << i->first << std::endl;
		std::cout << "ID: " << i->second->getID() << std::endl;

	}


}