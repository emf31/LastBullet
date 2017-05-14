#include "SoundManager.h"

void SoundManager::drop()
{
	for (auto it = sounds.begin(); it != sounds.end();++it ) {
			(*it)->drop();
	}
	sounds.clear();
	engine->drop();
}

void SoundManager::setVolume(float volume)
{
	engine->setSoundVolume(ik_f32(volume));
}

void SoundManager::playSound(std::string sound, bool loop)
{
	ISound* music = engine->play2D(sound.c_str(),loop,false,true);
	sounds.push_back(music);
}

void SoundManager::playSound(std::string sound, Vec3<float> pos, bool loop)
{
	ISound* music = engine->play3D(sound.c_str(), vec3df(pos.getX(), pos.getY(), pos.getZ()), loop,false,true);
	//music->setVolume(0.5f);
	music->setMinDistance(15.f);
	sounds.push_back(music);
	
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
			if ((*it)->isFinished()) {
				(*it)->drop();
				it= sounds.erase(it);
			}
			else {
				++it;
			}
	}
}
//Avoid error on delete element while looping

SoundManager::SoundManager()
{
	engine= createIrrKlangDevice();
}
