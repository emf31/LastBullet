#pragma once

#include <SensorySystem\Memory.h>
#include <EntityManager.h>
#include <vec3.hpp>
#include <map>
#include <Clock.hpp>

class Enemy_Bot;

class SensoryMemory {

private:

	//propietario de la instancia
	Enemy_Bot* m_bot;

	std::map<Entity*, Memory> m_botMemory;

	double m_memorySpan;

	Clock sensoryClock;

	void updateNewEnemies(Entity* ent);

public:

	SensoryMemory(Enemy_Bot* myBot,double span = 10);
	~SensoryMemory();

	void updateVision();
	void updateSound();
	bool isEnemyShootable(Entity* ent)const;
	bool isEnemyInFOV(Entity* ent)const;
	bool isRaycastObstructed(Entity* ent)const;
	bool isInFOV(Entity* ent)const;

	Vec3<float> GetLastRecordedPositionOfOpponent(Entity* ent)const;
	double GetTimeOpponentHasBeenVisible(Entity* ent)const;
	double GetTimeSinceLastSensed(Entity* ent)const;
	double GetTimeOpponentHasBeenOutOfView(Entity* ent)const;


	std::list<Entity*> GetListOfRecentlySensedEnemies()const;


};