#pragma once

#include <iostream>
#include <Estructuras.h>
#include <Util.h>
#include <list>
#include <Settings.h>



struct TPlayer;

//This class assigns character data for bots. Althought can be used too for represent the color of a character.
class CharacterTypes
{
public:

	
	enum CharacterColor {
		RED = 0,
		BLUE = 1,
		GREEN = 2,
		ORANGE = 3
	};

	//Gets one different character data every time is called
	static TPlayer getOneCharacterData();

	//Get Random death
	static std::string getRandomDeath();

	static std::string parseColorIntoPath(CharacterColor color);
private:
	static std::list<TPlayer> botsNames;

	static std::vector<std::string> deathSounds;

	CharacterTypes();
};
