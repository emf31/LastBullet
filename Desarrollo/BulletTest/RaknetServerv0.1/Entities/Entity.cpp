#include "EntityManager.h"
#include "Entity.h"



Entity::Entity(const std::string& name, RakNet::RakNetGUID guid, int id) :
	m_guid(guid),
	m_name(name),
	m_id(id),
	m_available(false)
{
	//De momento se generan en el 0,0
	setPosition(Vec3<float>(0, 0, 0));

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntity(this);
}


Entity::~Entity()
{
}
