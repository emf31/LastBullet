#include <iostream>

#include "Animation.h"

Animation::~Animation()
{
}

void Animation::addAnimation(std::string name, int start, int end)
{
	if (name!="") {
		if (m_animations.find(name) != m_animations.end()) {
			printf("Nombre de animacion no disponible\n");
			return;
		}
		struct frames f;
		f.start = start;
		f.end = end;
		m_animations[name] = f;
	}
		
}

void Animation::removeAnimation(std::string name)
{
	auto found = m_animations.find(name);
	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_animations.end()) {
		m_animations.erase(found);
	}
}

int Animation::getAnimationStart(std::string name)
{
	auto found = m_animations.find(name);
	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_animations.end()) {
		actualAnimation = name;
		return found->second.start;
	}
	return NULL;
}
int Animation::getAnimationEnd(std::string name)
{
	auto found = m_animations.find(name);
	//Si es diferente de m_entities.end() es que lo ha encontrado
	if (found != m_animations.end()) {
		actualAnimation = name;
		return found->second.end;
	}
	return NULL;
}


