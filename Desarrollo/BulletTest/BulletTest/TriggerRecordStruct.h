#pragma once

#include "Otros/vec3.hpp"
#include "Otros/Time.hpp"
#include "Otros/Clock.hpp"

enum EnumTriggerType {
	kTrig_None = 0,
	kTrig_Explosion = (1 << 0),
	kTrig_EnemyNear = (1 << 1)
};

struct TriggerRecordStruct {


	EnumTriggerType	eTriggerType;
	unsigned long nTriggerID;//ID del trigger
	int idSource;//ID del objeto que creo el trigger
	Vec3<float> vPos;//Posicion del trigger
	float fradius;//Radio del trigger
	Time nTimeStamp;//Tiempo de vida del trigger
	Time nExpirationTime;//Tiempo de expiracion del trigger
	bool bDynamicSourcePos;//Booleano para saber si es un trigger dinamico o no
	Clock tiempoDeVida;

	TriggerRecordStruct(EnumTriggerType eTriggerType,unsigned long nTriggerID, int idSource, Vec3<float> vPos, float fradius,  Time nExpirationTime, bool bDynamicSourcePos) :
		eTriggerType(eTriggerType),
		nTriggerID(nTriggerID),
		idSource(idSource),
		vPos(vPos),
		fradius(fradius),
		nExpirationTime(nExpirationTime),
		bDynamicSourcePos(bDynamicSourcePos){

		tiempoDeVida.restart();

	}


};

