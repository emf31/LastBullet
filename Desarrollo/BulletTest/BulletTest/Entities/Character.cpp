
#include <Character.h>

Character::Character(int id, std::shared_ptr<SceneNode> nodo, const std::string & name, RakNet::RakNetGUID guid) : EntActive(id, nodo, name, guid)
{
}

Character::~Character()
{
}

