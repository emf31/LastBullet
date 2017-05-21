#include "CharacterTypes.h"
#include "Util.h"

std::list<TPlayer> CharacterTypes::botsNames = std::list<TPlayer>();

std::vector<std::string> CharacterTypes::deathSounds = {
	"death1.wav",
	"death2.wav",
	"death3.wav",
	"death4.wav"
};

//Gets one different character data every time is called

TPlayer CharacterTypes::getOneCharacterData() {

	TPlayer p = botsNames.back();
	botsNames.pop_back();

	return p;

}

std::string CharacterTypes::getRandomDeath()
{
	return deathSounds.at(Randi(0,deathSounds.size() - 1));
}

std::string CharacterTypes::parseColorIntoPath(CharacterColor color) {

	ResourceProvider& rp = Settings::i().GetResourceProvider();

	switch (color) {
	case CharacterColor::RED: return rp.getFinalFilename("personaje.obj", "characters");
	case CharacterColor::BLUE: return rp.getFinalFilename("personaje2.obj", "characters");
	case CharacterColor::ORANGE: return rp.getFinalFilename("personaje.obj", "characters");
	case CharacterColor::GREEN: return rp.getFinalFilename("personaje.obj", "characters");
	default: return "";
	}
}

CharacterTypes::CharacterTypes() {
	botsNames.push_back(TPlayer{ NUEVO_PLAYER, RakNet::UNASSIGNED_RAKNET_GUID, "Nixon", CharacterColor::RED, true });
	botsNames.push_back(TPlayer{ NUEVO_PLAYER, RakNet::UNASSIGNED_RAKNET_GUID, "Obama", CharacterColor::GREEN, false });
	botsNames.push_back(TPlayer{ NUEVO_PLAYER, RakNet::UNASSIGNED_RAKNET_GUID, "PPlu", CharacterColor::BLUE, false });
	botsNames.push_back(TPlayer{ NUEVO_PLAYER, RakNet::UNASSIGNED_RAKNET_GUID, "Nixon", CharacterColor::ORANGE, false });
}
