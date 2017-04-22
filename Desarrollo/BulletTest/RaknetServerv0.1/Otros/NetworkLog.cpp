#include "NetworkLog.h"
#include <EntityManager.h>
#include <Entity.h>
#include <string>

std::string NetworkLog::generarTabla()
{
	std::string tabla;

	tabla.append("ServerLog:\n\n");

	tabla.append("ClassType             ");
	tabla.append("RakID                 ");
	tabla.append("Nombre                   ");
	tabla.append("Position                                                          ");
	tabla.append("localID             ");
	tabla.append("Available  \n\n");

	for (auto it = m_tabla.begin(); it != m_tabla.end(); it++) {
		tabla.append(generarFila(it->second));
		tabla.append("\n\n");
	}

	return tabla;
}

std::string NetworkLog::updateAndGenerateTable()
{
	updatearTabla();

	return generarTabla();
}

std::string NetworkLog::generarFila(TServerEntity & fila)
{
	std::string filaString;

	filaString.append(fila.classType + "             ");
	filaString.append(std::to_string(RakNet::RakNetGUID::ToUint32(fila.guid)) + "             ");
	filaString.append(fila.name + "             ");
	filaString.append(vec3ToString(fila.position) + "             ");
	filaString.append(std::to_string(fila.localID) + "             ");
	filaString.append(std::to_string(fila.available) + "             ");

	return filaString;
}

void NetworkLog::updatearTabla()
{
	m_tabla.clear();

	std::list<Entity*> players = EntityManager::i().getAllPlayers();

	for (std::list<Entity*>::iterator it = players.begin(); it != players.end(); it++) {
		Entity* ent = *it;
		m_tabla[RakNet::RakNetGUID::ToUint32(ent->getGuid())] = 
			TServerEntity{ 
			ent->getGuid(), 
			ent->getClassName(), 
			ent->getName(), 
			ent->getPosition(), 
			ent->getID(), 
			ent->isAvailable()};
	}
}

std::string NetworkLog::vec3ToString(Vec3<float> &vec) {
	return std::string("(" + std::to_string(vec.getX()) + "," + std::to_string(vec.getY()) + "," + std::to_string(vec.getZ()) + ")");
}