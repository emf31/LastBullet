#pragma once
#include <map>
#include <functional>  
#include "TriggerRecordStruct.h"

typedef std::multimap<unsigned short, TriggerRecordStruct*, std::greater<unsigned short> > TRIGGER_MAP;

class TriggerSystem
{
public:
	TriggerSystem();
	~TriggerSystem();

	int RegisterTrigger(EnumTriggerType _eTriggerType, int nPriority, int idSource, Vec3<float> vPos, float fRadius, float fDuration, bool bDynamicSourcePos);

	void RemoveTrigger(int nTriggerID);
	void Update();

private:

	TRIGGER_MAP m_mapTriggerMap;
	bool m_bTriggerCriticalSection;

};

