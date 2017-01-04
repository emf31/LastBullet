#pragma once
#include <map>
#include <functional>  
#include "TriggerRecordStruct.h"
#include "../Entities/Entity.h"
#include <vec3.hpp>
#include <vector>

typedef std::multimap<unsigned short, TriggerRecordStruct*, std::greater<unsigned short> > TRIGGER_MAP;

class TriggerSystem
{
public:
	TriggerSystem();
	~TriggerSystem();

	static TriggerSystem& i() {
		static TriggerSystem singleton;
		return singleton;
	}

	unsigned long RegisterTrigger(EnumTriggerType _eTriggerType, unsigned long nPriority, int idSource, Vec3<float> vPos, float fRadius, Time nExpirationTime, bool bDynamicSourcePos);
	
	void RegisterEntity(Entity* ent);

	void RemoveTrigger(unsigned long nTriggerID);
	void Update();

	void UpdatePos(TriggerRecordStruct *trigger);

	void clearTriggers();
	void apagar();
private:
	std::vector<Entity*> m_entities;
	TRIGGER_MAP m_mapTriggerMap;
	bool m_bTriggerCriticalSection;
	unsigned long IDTriggers;

};

