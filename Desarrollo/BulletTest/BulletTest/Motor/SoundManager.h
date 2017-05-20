#pragma once
#include <irrKlang\irrKlang.h>
#include <iostream>
#include <vec3.hpp>
#include <unordered_map>

using namespace irrklang;


#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
class Sound {
public:
	enum type { music, sound } m_type;
	Sound(ISound* sound,type m):m_sound(sound),m_type(m){}
	ISound* m_sound;
};


class SoundManager
{
public:

	static SoundManager& i() {
		static SoundManager singleton;
		return singleton;
	}

	
	void drop();
	void setVolume(float volume);
	ISound* playSound(std::string sound, Sound::type type, bool loop = false);
	ISound* playSound(std::string sound,Vec3<float>pos, Sound::type type,bool loop=false);
	void setListenerPosition(Vec3<float>pos, Vec3<float> dir);
	void stopAllSounds();
	void update();
	void setVolumeMusic(float volume);
	void setVolumeSounds(float volume);

private:
	SoundManager();
	ISoundEngine* engine;
	std::list<Sound*> sounds;
	float soundVolume;
	float musicVolume;
};