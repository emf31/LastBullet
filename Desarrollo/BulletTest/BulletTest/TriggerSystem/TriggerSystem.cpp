#include "TriggerSystem.h"
#include <EntityManager.h>
#include "../Entities/GroupEntity.h"

TriggerSystem::TriggerSystem()
{

	IDTriggers = 0;

}


TriggerSystem::~TriggerSystem()
{

}

unsigned long TriggerSystem::RegisterTrigger(EnumTriggerType _eTriggerType, unsigned long nPriority, int idSource, Vec3<float> vPos, float fRadius, Time fDuration, bool bDynamicSourcePos) {

	TriggerRecordStruct* pTriggerRecord = new TriggerRecordStruct( _eTriggerType, ++IDTriggers, idSource, vPos, fRadius, fDuration, bDynamicSourcePos);//Creamos un nuevo triggerRecord, y lo rellenamos
	//printf("He creado un trigger\n");
	m_mapTriggerMap.insert(TRIGGER_MAP::value_type(nPriority, pTriggerRecord));//Ordenamos los triggersRecords por prioridad

	return pTriggerRecord->nTriggerID;//Devolvemos el identificador del trigger

}

void TriggerSystem::RegisterEntity(Entity * ent)
{
	m_entities.push_back(ent);
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

	trigger->vPos = ent->getPosition();

}

void TriggerSystem::clearTriggers()
{
	m_entities.clear();
	for (auto i = m_mapTriggerMap.begin(); i != m_mapTriggerMap.end(); ++i) {
		delete i->second;
	}

	m_mapTriggerMap.clear();
}


void TriggerSystem::Update() {

	Entity* entity = NULL;
	float fDistance = 0.f;

	TriggerRecordStruct* pRec;
	TRIGGER_MAP::iterator it;

	it = m_mapTriggerMap.begin();

	while (it != m_mapTriggerMap.end()) {
		pRec = it->second;

		if ((pRec->nExpirationTime != Time::Zero) && (pRec->nExpirationTime < pRec->tiempoDeVida.getElapsedTime())) {
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


	for (std::vector<Entity*>::iterator it2 = m_entities.begin(); it2 != m_entities.end(); ++it2) {

		for (it = m_mapTriggerMap.begin(); it != m_mapTriggerMap.end(); ++it) {

			pRec = it->second;

			if (!(pRec->eTriggerType & (*it2)->getTriggerFlags())) {
				continue;
			}

			if (pRec->idSource == (*it2)->getID()) {
				continue;
			}
			
			Vec3<float> vector = (*it2)->getPosition() - pRec->vPos;
			fDistance = vector.Magnitude();
			
			//Si es Entity con trigger punto - radio
			if ((*it2)->getClassName() != "GroupEntity") {
				if (fDistance > pRec->fradius) {
					continue;
				}
			}
			else {
				if (fDistance > pRec->fradius + static_cast<GroupEntity*>(*it2)->getRadius()) {
					continue;
				}
			}

			

			if ((*it2)->handleTrigger(pRec)) {
				break;
			}

		}


	}



}

void TriggerSystem::apagar()
{
	clearTriggers();

	m_entities.clear();
}