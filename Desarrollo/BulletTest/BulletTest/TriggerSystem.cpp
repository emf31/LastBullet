#include "TriggerSystem.h"
#include "Entities/EntityManager.h"

TriggerSystem::TriggerSystem()
{

	IDTriggers = 0;

}


TriggerSystem::~TriggerSystem()
{
}

unsigned long TriggerSystem::RegisterTrigger(EnumTriggerType _eTriggerType, unsigned long nPriority, int idSource, Vec3<float> vPos, float fRadius, Time fDuration, bool bDynamicSourcePos) {

	TriggerRecordStruct* pTriggerRecord = new TriggerRecordStruct( _eTriggerType, ++IDTriggers, idSource, vPos, fRadius, fDuration, bDynamicSourcePos);//Creamos un nuevo triggerRecord, y lo rellenamos

	m_mapTriggerMap.insert(TRIGGER_MAP::value_type(nPriority, pTriggerRecord));//Ordenamos los triggersRecords por prioridad

	return pTriggerRecord->nTriggerID;//Devolvemos el identificador del trigger

}

void TriggerSystem::RemoveTrigger(unsigned long IDTrigger) {


	TRIGGER_MAP::iterator it = m_mapTriggerMap.begin();

	while (it!=m_mapTriggerMap.end())
	{
		if (it->second->nTriggerID == IDTrigger) {
			delete(it->second);
			return;
		}
		else {
			++it;
		}
	}

/*	auto found = TRIGGER_MAP.find(entity->getID());

	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_entities.end()) {
		m_entities.erase(found);
	}*/

}

void TriggerSystem::UpdatePos(TriggerRecordStruct *trigger) {

	int idCreator=trigger->idSource;

	Entity* ent = EntityManager::i().getEntity(idCreator);

	trigger->vPos = ent->getRenderPosition();

}


void TriggerSystem::Update() {

	Entity* entity = NULL;
	float fDistance = 0.f;

	TriggerRecordStruct* pRec;
	TRIGGER_MAP::iterator it;

	it = m_mapTriggerMap.begin();

	while (it != m_mapTriggerMap.end()) {
		pRec = it->second;

		if ((pRec->nExpirationTime != Time::Zero) && (pRec->nExpirationTime > pRec->tiempoDeVida.getElapsedTime())) {
			delete(pRec);
			it = m_mapTriggerMap.erase(it);
		}
		else {
			if (pRec->bDynamicSourcePos) {
				UpdatePos(pRec);
				//pRec->nTimeStamp=pRec->tiempoDeVida.gerElapsedTime();
			}
			++it;
		}

	}

	list<Entity*> lista = EntityManager::i().getAllEntitiesTriggerables();

	for (list<Entity*>::Iterator it2 = lista.begin(); it2 != lista.end(); it2++) {

		for (it = m_mapTriggerMap.begin(); it != m_mapTriggerMap.end(); ++it) {

			pRec = it->second;

			if (!(pRec->eTriggerType & (*it2)->getTriggerFlags())) {
				continue;
			}

			if (pRec->idSource == (*it2)->getID()) {
				continue;
			}

			Vec3<float> vector = (*it2)->getRenderPosition() - pRec->vPos;
			fDistance = vector.Magnitude();

			if (fDistance > pRec->fradius) {
				continue;
			}

			if ((*it2)->handleTrigger(pRec)) {
				break;
			}

		}


	}



}