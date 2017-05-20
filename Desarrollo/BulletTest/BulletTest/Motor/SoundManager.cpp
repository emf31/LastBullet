#include "SoundManager.h"

void SoundManager::drop()
{
	for (auto it = sounds.begin(); it != sounds.end();++it ) {
			(*it)->m_sound->drop();
	}
	sounds.clear();
	engine->drop();
}

void SoundManager::setVolume(float volume)
{
	engine->setSoundVolume(ik_f32(volume));
}

ISound* SoundManager::playSound(std::string sound, Sound::type type, bool loop)
{
	ISound* music = engine->play2D(sound.c_str(),loop,false,true);
	if (type == Sound::type::music)
		music->setVolume(musicVolume);
	if (type == Sound::type::sound)
		music->setVolume(soundVolume);


	sounds.push_back(new Sound(music, type));

	return music;
}

ISound* SoundManager::playSound(std::string sound, Vec3<float> pos,Sound::type type, bool loop)
{
	ISound* music = engine->play3D(sound.c_str(), vec3df(pos.getX(), pos.getY(), pos.getZ()), loop,false,true);
	music->setMinDistance(15.f);

	if (type == Sound::type::music)
		music->setVolume(musicVolume);
	if (type == Sound::type::sound)
		music->setVolume(soundVolume);

	sounds.push_back(new Sound(music,type));

	return music;
	
}

void SoundManager::setListenerPosition(Vec3<float> pos,Vec3<float> dir)
{
	engine->setListenerPosition(vec3df(pos.getX(), pos.getY(), pos.getZ()), vec3df(dir.getX(), dir.getY(), dir.getZ()));
}

void SoundManager::stopAllSounds()
{
	engine->stopAllSounds();
}

void SoundManager::update()
{
	for (auto it = sounds.cbegin(); it != sounds.cend(); ) {			
			if ((*it)->m_sound->isFinished()) {
				(*it)->m_sound->drop();
				it= sounds.erase(it);
			}
			else {
				++it;
			}
	}
}
void SoundManager::setVolumeMusic(float volume)
{
	musicVolume = volume;
	for (auto it = sounds.begin(); it != sounds.end(); ++it) {
		if ((*it)->m_type == Sound::type::music)
			(*it)->m_sound->setVolume(musicVolume);
	}
}
void SoundManager::setVolumeSounds(float volume)
{
	soundVolume = volume;
	for (auto it = sounds.begin(); it != sounds.end(); ++it) {
		if ((*it)->m_type == Sound::type::sound)
			(*it)->m_sound->setVolume(soundVolume);
	}
}
//Avoid error on delete element while looping

SoundManager::SoundManager():soundVolume(1.f),musicVolume(1.f)
{
	engine= createIrrKlangDevice();
}
