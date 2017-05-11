#include "NetworkDebugger.h"
#include <EntityManager.h>
#include <NetworkManager.h>


NetworkDebugger::NetworkDebugger()
{
	restartPacketsCount();
}

NetworkDebugger::~NetworkDebugger()
{
	for (auto it = m_marks.begin(); it != m_marks.end(); ++it) {
		EntityManager::i().removeEntity(it->second);
	}

	m_marks.clear();
}

bool NetworkDebugger::addDebugMark(int entID)
{
	Entity* ent = EntityManager::i().getEntity(entID);

	if (ent != NULL) {
		DebugMarks* debugMark = new DebugMarks(dynamic_cast<Character*>(ent), 11.f);

		debugMark->inicializar();
		debugMark->cargarContenido();

		m_marks[entID] = debugMark;

		return true;
	}

	return false;
}

bool NetworkDebugger::removeDebugMark(int entID)
{
	auto found = m_marks.find(entID);

	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_marks.end()) {
		m_marks.erase(found);

		return true;
	}

	return false;
}

DebugMarks* NetworkDebugger::getDebugMark(int entID) {
	auto found = m_marks.find(entID);

	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_marks.end()) {

		return found->second;
	}

	return NULL;
}

void NetworkDebugger::sendSyncPackage(const RakNet::RakNetGUID & guid, unsigned char message)
{
	//Send sync package
	TSyncMessage sync;
	sync.destino = guid;
	sync.origen = EntityManager::i().getEntity(PLAYER)->getGuid();
	sync.packageType = message;

	NetworkManager::i().dispatchMessage(sync, SYNC);
}




void NetworkDebugger::receivedSyncPacket(const TSyncMessage & sync)
{

	Enemy *e = dynamic_cast<Enemy*>(EntityManager::i().getRaknetEntity(sync.origen));


	if (e != NULL) {
		DebugMarks* mark = getDebugMark(e->getID());

		//notify mark we recived sync
		mark->syncRecevied();

		if (sync.packageType != MOVIMIENTO /*&& windowsPacketOpen*/) {
			mark->activateMark(seconds(2), Vec3<float>(0.2,1,0));
		}
		
	}

	auto found = m_counter.find(sync.packageType);
	if (found != m_counter.end()) {
		found->second++;
	}
	
}

void NetworkDebugger::restartPacketsCount()
{
	m_counter[MOVIMIENTO] = 0;
	m_counter[DISPARAR_BALA] = 0;
	m_counter[DISPARAR_ROCKET] = 0;
	m_counter[IMPACTO_BALA] = 0;
	m_counter[IMPACTO_ROCKET] = 0;
	m_counter[VIDA_COGIDA] = 0;
	m_counter[ARMA_COGIDA] = 0;
	m_counter[MUERTE] = 0;
	m_counter[LANZAR_GRANADA] = 0;
	m_counter[AUMENTA_KILL] = 0;
	m_counter[AUMENTA_MUERTE] = 0;
}

int NetworkDebugger::getPacketCount(unsigned char message)
{
	auto found = m_counter.find(message);
	if (found != m_counter.end()) {
		return found->second;
	}

	return -1;
}
