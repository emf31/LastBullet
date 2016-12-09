#pragma once
#include <map>
#include <functional>  
#include "TriggerRecordStruct.h"
#include "Entities/Entity.h"
#include "Otros/vec3.hpp"

typedef std::multimap<unsigned short, TriggerRecordStruct*, std::greater<unsigned short> > TRIGGER_MAP;

class TriggerSystem
{
public:
	TriggerSystem();
	~TriggerSystem();

	unsigned long RegisterTrigger(EnumTriggerType _eTriggerType, unsigned long nPriority, int idSource, Vec3<float> vPos, float fRadius, Time fDuration, bool bDynamicSourcePos);
	

	void RemoveTrigger(unsigned long nTriggerID);
	void Update();

	void UpdatePos(TriggerRecordStruct *trigger);

private:

	TRIGGER_MAP m_mapTriggerMap;
	bool m_bTriggerCriticalSection;
	unsigned long IDTriggers;

};

