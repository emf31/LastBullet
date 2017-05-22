
#include <Character.h>


Character::Character(int id, std::shared_ptr<SceneNode> nodo, const std::string & name, RakNet::RakNetGUID guid) : EntActive(id, nodo, name, guid), footsteps(nullptr)
{
	life_component = new LifeComponent(this);
}

Character::~Character()
{
	delete life_component;
}

AnimationMachine * Character::getAnimationMachine() { return animationMachine; }
