#pragma once

#include <string>

class Character;

class AnimationCharacter
{
public:
	AnimationCharacter() {};
	~AnimationCharacter() { }

	virtual void Enter(Character* e) = 0;
	virtual void Exit(Character* e) = 0;
	virtual void Execute(Character* e) = 0;

	virtual std::string getAnimationName() = 0;

};

