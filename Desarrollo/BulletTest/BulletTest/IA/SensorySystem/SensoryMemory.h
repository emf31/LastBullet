#pragma once

#include <SensorySystem\Memory.h>
#include <EntityManager.h>
#include <vec3.hpp>
#include <map>
#include <Clock.hpp>
#include <Character.h>

class Enemy_Bot;

class SensoryMemory {

private:

	//propietario de la instancia
	Enemy_Bot* m_bot;

	std::map<Character*, Memory> m_botMemory;

	double m_memorySpan;

	Clock sensoryClock;

	void updateNewEnemies(Character* ent);

public:

	SensoryMemory(Enemy_Bot* myBot,double span = 10);
	~SensoryMemory();

	void updateVision();
	void updateSound(Character* ent);
	bool isEnemyShootable(Character* ent)const;
	bool isEnemyInFOV(Character* ent)const;
	bool isRaycastObstructed(Character* ent)const;
	bool isInFOV(Character* ent)const;

	Vec3<float> GetLastRecordedPositionOfOpponent(Character* ent)const;
	double GetTimeOpponentHasBeenVisible(Character* ent)const;
	double GetTimeSinceLastSensed(Character* ent)const;
	double GetTimeOpponentHasBeenOutOfView(Character* ent)const;


	std::list<Character*> GetListOfRecentlySensedEnemies()const;


};