#pragma once
#include <irrKlang\irrKlang.h>
#include <iostream>
#include <vec3.hpp>
#include <unordered_map>

using namespace irrklang;


#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

class SoundManager
{
public:

	static SoundManager& i() {
		static SoundManager singleton;
		return singleton;
	}

	
	void drop();
	void setVolume(float volume);
	ISound* playSound(std::string sound, bool loop=false);
	ISound* playSound(std::string sound,Vec3<float>pos,bool loop=false);
	void setListenerPosition(Vec3<float>pos, Vec3<float> dir);
	void stopAllSounds();
	void update();

private:
	SoundManager();
	ISoundEngine* engine;
	std::list<ISound*> sounds;
};