#pragma once

#include "Otros/vec3.hpp"

enum EnumTriggerType {
	kTrig_None = 0,
	kTrig_Explosion = (1 << 0),
	kTrig_EnemyNear = (1 << 1)
};

struct TriggerRecordStruct {


	EnumTriggerType	eTriggerType;
	int nTriggerID;//ID del trigger
	int idSource;//ID del objeto que creo el trigger
	Vec3<float> vPos;//Posicion del trigger
	float fradius;//Radio del trigger
	int nTimeStamp;//Tiempo de vida del trigger
	int nExpirationTime;//Tiempo de expiracion del trigger
	bool bDynamicSourcePos;//Booleano para saber si es un trigger dinamico o no

	TriggerRecordStruct(EnumTriggerType eTriggerType, int nTriggerID, int idSource, Vec3<float> vPos, float fradius, int nTimeStamp, int nExpirationTime, bool bDynamicSourcePos) :
		eTriggerType(eTriggerType),
		nTriggerID(nTriggerID),
		idSource(idSource),
		vPos(vPos),
		fradius(fradius),
		nTimeStamp(nTimeStamp),
		nExpirationTime(nExpirationTime),
		bDynamicSourcePos(bDynamicSourcePos){


	}


};

