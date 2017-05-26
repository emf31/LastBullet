#include "EntityManager.h"
#include "../Estructuras.h"
#include <string>


void EntityManager::sendPlayer(TPlayer & p, RakNet::RakPeerInterface *peer)
{
	TPlayer nuevocli;

	p.mID = NUEVO_PLAYER;


	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		
		peer->Send((const char*)&p, sizeof(p), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, i->second->getGuid(), false);

		//enviamos todos los clientes que habian en el servidor al nuevo player

		nuevocli.mID = NUEVO_CLIENTE;
		nuevocli.guid = i->second->getGuid();
		nuevocli.name = i->second->getName();
		nuevocli.available = i->second->isAvailable();
		
		peer->Send((const char*)&nuevocli, sizeof(nuevocli), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, p.guid, false);
	}
}

void EntityManager::sendBot(TPlayer &p, const RakNet::RakNetGUID& host, RakNet::RakPeerInterface *peer)
{
	//Enviamos todos el bot a todos los clientes menos al host de la partida, que es el que los ha creado
	p.mID = NUEVO_PLAYER;

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		if (i->second->getGuid() != host) {
			peer->Send((const char*)&p, sizeof(p), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, i->second->getGuid(), false);
		}
	}
}

void EntityManager::enviaNuevaPos(RakNet::BitStream& bitStream, RakNet::RakNetGUID packetOwner, RakNet::RakNetGUID gameOwner, RakNet::RakPeerInterface *peer)
{
	Entity* ent = EntityManager::i().getRaknetEntity(packetOwner);

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != packetOwner) {

			//No se envia al propietario de la partida, si el que se mueve es un bot
			if (ent->getClassName() == "Bot" && i->second->getGuid() == gameOwner) {
				continue;
			}
			
			peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);

			

		}

	}
}

void EntityManager::lanzarGranda(TGranada & g, RakNet::RakNetGUID owner, RakNet::RakPeerInterface * peer)
{
	Entity* ent = EntityManager::i().getRaknetEntity(g.guid);

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != g.guid) {

			//No se envia al propietario de la partida, si el que se mueve es un bot
			if (ent->getClassName() == "Bot" && i->second->getGuid() == owner) {
				continue;
			}

			peer->Send((const char*)&g, sizeof(g), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		}

	}

}

void EntityManager::enviarTerminarPartida(RakNet::RakNetGUID& owner, RakNet::RakPeerInterface *peer)
{
	RakID rakiD;
	rakiD.mID = TERMINAR_PARTIDA;
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		if (i->second->getGuid() == owner) {
			peer->Send((const char*)&rakiD, sizeof(rakiD), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, i->second->getGuid(), false);
		}
		
		

	}
}

void EntityManager::enviaDesconexion(RakNet::RakNetGUID & guid, RakNet::RakPeerInterface *peer)
{
	RakID rakID;

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != guid) {
			rakID.mID = DESCONECTADO;
			rakID.guid = guid;
			peer->Send((const char*)&rakID, sizeof(rakID), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, i->second->getGuid(), false);
		}

	}
}
//imp tiene el daño del arma y el guid del que han dado, dispara es el guid de quien lo dispara
void EntityManager::enviaDisparado(TImpactoBala &imp, RakNet::RakNetGUID &dispara, RakNet::RakPeerInterface *peer)
{
	/*RakNet::RakNetGUID guid = imp.guid;
	imp.guid = dispara;*/

	//se envia unicamente al cliente que ha sido disparado

	peer->Send((const char*)&imp, sizeof(imp), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, imp.guidImpactado, false);

}

void EntityManager::enviaDisparadoRocket(TImpactoRocket &impact, RakNet::RakPeerInterface * peer)
{

	peer->Send((const char*)&impact, sizeof(impact), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, impact.guidImpactado, false);


}


void EntityManager::notificarMuerte(RakID & p, RakNet::RakPeerInterface *peer)
{

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS

		peer->Send((const char*)&p, sizeof(p), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, i->second->getGuid(), false);


	}
}

void EntityManager::enviaTiempoActualVida(Life * l, RakNet::RakNetGUID &guid, RakNet::RakPeerInterface * peer)
{

	TDropServer vida;
	vida.mID = NUEVA_VIDA;
	vida.id = l->getID();
	vida.tiempo = l->clockRecargaLife;

	peer->Send((const char*)&vida, sizeof(vida), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, guid, false);


}

void EntityManager::enviaTiempoActualArma(DropObject * o, RakNet::RakNetGUID &guid, RakNet::RakPeerInterface * peer)
{
	TDropServer weapondrop;
	weapondrop.mID = NUEVA_ARMA;
	weapondrop.id = o->getID();
	weapondrop.tiempo = o->clockRecargaLife;

	peer->Send((const char*)&weapondrop, sizeof(weapondrop), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, guid, false);

}

void EntityManager::enviarDisparoCliente(TBala & b, RakNet::RakNetGUID owner, RakNet::RakPeerInterface *peer)
{

	Entity* ent = EntityManager::i().getRaknetEntity(b.guid);

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != b.guid) {

			//No se envia al propietario de la partida, si el que se mueve es un bot
			if (ent->getClassName() == "Bot" && i->second->getGuid() == owner) {
				continue;
			}

			peer->Send((const char*)&b, sizeof(b), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		}

	}
}


void EntityManager::enviarDisparoClienteRocket(TBala & b, RakNet::RakNetGUID owner, RakNet::RakPeerInterface *peer)
{

	Entity* ent = EntityManager::i().getRaknetEntity(b.guid);

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a todos menos a nosotros mismos
		if (i->second->getGuid() != b.guid) {

			//No se envia al propietario de la partida, si el que se mueve es un bot
			if (ent->getClassName() == "Bot" && i->second->getGuid() == owner) {
				continue;
			}

			peer->Send((const char*)&b, sizeof(b), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);

		}

	}

}

void EntityManager::VidaCogida(TId &idVida, RakNet::RakPeerInterface * peer)
{
	
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS para que todos sepan que la vida con idVida ha sido cogida

		peer->Send((const char*)&idVida, sizeof(idVida), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
	}
}

void EntityManager::ArmaCogida(TId &idArma, RakNet::RakPeerInterface * peer)
{

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS para que todos sepan que el arma con idArma ha sido cogida y a todos le reaparezca a la vez
		peer->Send((const char*)&idArma, sizeof(idArma), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);


	}
}

void EntityManager::inicializar()
{
	std::unordered_map<unsigned long, Entity*>::iterator iter = m_jugadores.begin();
	for (; iter != m_jugadores.end(); ++iter) {
		iter->second->inicializar();
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

	//Si la entity tiene GUID la añadimos a la lista de jugadores
	if (entity->getGuid() != RakNet::UNASSIGNED_RAKNET_GUID) {
		m_jugadores[RakNet::RakNetGUID::ToUint32(entity->getGuid())] = entity;
	}
	else {
		if (m_entities.find(entity->getID()) != m_entities.end()) {
			//mostramos error
			//std::cout << "ESA VIDA o ARMA YA HA SIDO CREADA " + entity->getID() << std::endl;

		}
		else {
			//si todo ha ido bien le asignamos el entity al map
			//std::cout << "CREO UNA VIDA o ARMA CON ID : " + entity->getID() << std::endl;
			m_entities[entity->getID()] = entity;
		}


	}





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

Entity * EntityManager::getEntityID(int id)
{
	auto found = m_entities.find(id);
	if (found != m_entities.end())
		return found->second;
	//no existe devolvemos 0


	return NULL;
}

std::list<Entity*> EntityManager::getAllPlayers()
{
	std::list<Entity*> players;

	for (auto it = m_jugadores.begin(); it != m_jugadores.end(); it++) {
		players.push_back(it->second);
	}

	return players;
}

void EntityManager::mostrarClientes() {

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		i->second->getGuid();
		std::cout << "Nombre del player: " << i->second->getName() << std::endl;
		std::cout << "Posicion: " << i->second->getPosition().getX() << ", " << i->second->getPosition().getZ() << std::endl;
		std::cout << "GUID de la Entity: " << RakNet::RakNetGUID::ToUint32(i->second->getGuid()) << std::endl;
		std::cout << "GUID de la Clave: " << i->first << std::endl;
		std::cout << "ID: " << i->second->getID() << std::endl;

	}


}

void EntityManager::enviaImpulso(TImpulso &impulso, RakNet::RakPeerInterface *peer)
{
	peer->Send((const char*)&impulso, sizeof(impulso), HIGH_PRIORITY, RELIABLE_ORDERED, 0, impulso.guid, false);

}


void EntityManager::aumentaKill(TKill& kill, int MaxKills, RakNet::RakPeerInterface * peer)
{
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(kill.guidKill))->second;
	fila->kills++;

	RakID s_guid;

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS para que todos actualicen la tabla de puntuacion
		
		kill.mID = AUMENTA_KILL;
		s_guid.guid = kill.guidKill;

		peer->Send((const char*)&kill, sizeof(kill), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);


	}
	if (fila->kills >= MaxKills) {
		for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

			//se envia a TODOS para que todos actualicen la tabla de puntuacion
			s_guid.mID = FIN_PARTIDA;

			s_guid.guid = fila->guid;

			peer->Send((const char*)&s_guid, sizeof(s_guid), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);

		}
	}
}

void EntityManager::aumentaMuerte(TKill& kill, RakNet::RakPeerInterface * peer)
{
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(kill.guidDeath))->second;
	fila->deaths++;

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		//se envia a TODOS para que todos actualicen la tabla de puntuacion

		kill.mID = AUMENTA_MUERTE;

		peer->Send((const char*)&kill, sizeof(kill), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);

	}

}

void EntityManager::enviaFila(RakNet::RakPeerInterface * peer, TFilaTabla fila)
{

	TFilaTabla fila2;

	m_tabla[RakNet::RakNetGUID::ToUint32(fila.guid)] = fila;

	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		if (i->second->getGuid() != fila.guid) {
			//se envia la fila del nuevo jugador a todos los clientes

			peer->Send((const char*)&fila, sizeof(fila), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		}
	}

	//se envian todas las filas que ya hay en la tabla al nuevo cliente (incluyendo su propia fila que antes no se envio)
	for (auto j = m_tabla.begin(); j != m_tabla.end(); ++j) {

		fila2 = j->second;
		peer->Send((const char*)&fila2, sizeof(fila2), HIGH_PRIORITY, RELIABLE_ORDERED, 0, fila.guid, false);
	}

}


void EntityManager::enviaSync(RakNet::RakPeerInterface *peer, TSyncMessage sync) {
	//std::cout << "Tipoo: " <<(unsigned int) sync.mID << std::endl;
	peer->Send((const char*)&sync, sizeof(sync), HIGH_PRIORITY, RELIABLE_ORDERED,0, sync.destino, false);
}

void EntityManager::empezarPartida(RakNet::RakPeerInterface * peer, TGameInfo & info)
{
	info.mID = EMPEZAR_PARTIDA;

	//Enviamos mensaje de empezar partida a todos con los datos de la partida
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {

		peer->Send((const char*)&info, sizeof(info), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);

	}
}

//Notificamos a todos de que hay un player disponible
void EntityManager::notificarDisponibilidad(RakID & p, RakNet::RakPeerInterface * peer)
{
	for (auto i = m_jugadores.begin(); i != m_jugadores.end(); ++i) {
		//No notificamos de disp a nosotros mismos
		if (i->second->getGuid() != p.guid) {
			peer->Send((const char*)&p, sizeof(p), HIGH_PRIORITY, RELIABLE_ORDERED, 0, i->second->getGuid(), false);
		}
		
	}
}
