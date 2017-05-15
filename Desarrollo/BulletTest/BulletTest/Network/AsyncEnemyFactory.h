#pragma once

#include <Estructuras.h>
#include <unordered_map>
#include <RakNetTypes.h>


//This class concern about creating enemies only if available
//NOTE: Available means that the player behind that enemy is prepared
//to start the game. Creating enemies without this factory could give an error during a game.

class AsyncEnemyFactory {

public:
	AsyncEnemyFactory();
	~AsyncEnemyFactory();

	void addEnemyToBeCreated(TPlayer& p);

	//Once the enemy is created it's erased from the map
	void createEnemiesIfAvailable();
	void createEnemyIfAvailable(RakNet::RakNetGUID& rakID);


	void markEnemyAsAvailable(RakNet::RakNetGUID& rakID);
	void markEnemyAsUnavailable(RakNet::RakNetGUID& rakID);

	std::list<TPlayer> getEnemies();

	void checkIfAllEnemiesReady();


private:
	typedef std::unordered_map<unsigned long, TPlayer> EnemyMap;
	EnemyMap m_enemies;

	
};