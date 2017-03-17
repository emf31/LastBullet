
#include "EntPassive.h"
#include "EntityManager.h"


EntPassive::EntPassive(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	Entity(id, nodo, name , guid)
{

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntityPassive(this);

}


EntPassive::~EntPassive()
{
}







