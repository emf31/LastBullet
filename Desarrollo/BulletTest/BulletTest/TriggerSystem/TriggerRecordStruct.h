#pragma once

#include <vec3.hpp>
#include <Time.hpp>
#include <Clock.hpp>
#include <EnumParser.h>

enum EnumTriggerType {
	kTrig_None = 0,
	kTrig_Explosion = (1 << 0),
	kTrig_EnemyNear = (1 << 1),
	Button_Spawn = (1 << 2),
	Button_Trig_Ent = (1 << 3),
	Button_Trig_Ent_Pistola = (1 << 4),
	Button_Trig_Ent_Rocket = (1 << 5),
	Button_Trig_Ent_Asalto = (1 << 6),
	kTrig_EnemyShootSound = (1 << 7)
};

EnumParser<EnumTriggerType>::EnumParser() {
	enumMap["kTrig_None"] = kTrig_None;
	enumMap["kTrig_Explosion"] = kTrig_Explosion;
	enumMap["kTrig_EnemyNear"] = kTrig_EnemyNear;
	enumMap["Button_Spawn"] = Button_Spawn;
	enumMap["Button_Trig_Ent"] = Button_Trig_Ent;
	enumMap["Button_Trig_Ent_Pistola"] = Button_Trig_Ent_Pistola;
	enumMap["Button_Trig_Ent_Rocket"] = Button_Trig_Ent_Rocket;
	enumMap["Button_Trig_Ent_Asalto"] = Button_Trig_Ent_Asalto;
	enumMap["kTrig_EnemyShootSound"] = kTrig_EnemyShootSound;
}


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

