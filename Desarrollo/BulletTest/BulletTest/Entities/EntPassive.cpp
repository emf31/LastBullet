
#include "EntPassive.h"
#include "EntityManager.h"


EntPassive::EntPassive(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	Entity(id, nodo, name , guid)
{
	if (m_nodo) {
		m_position = m_nodo->getPosition();
	}
	else {
		m_position = Vec3<float>(0, 0, 0);
	}

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntityPassive(this);

}


EntPassive::~EntPassive()
{
}







