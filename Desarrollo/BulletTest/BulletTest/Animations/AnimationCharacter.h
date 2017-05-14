#pragma once

#include <string>

class Character;

class AnimationCharacter
{
public:
	AnimationCharacter() {};
	~AnimationCharacter();


	virtual void Execute(Character* e) = 0;

	virtual std::string getAnimationName() = 0;


};

