#include "EntityManager.h"
#include "Entity.h"



Entity::Entity(int id, const std::string& name) :
	m_id(id),
	m_name(name),
	m_renderState()
{
	//De momento se generan en el 0,0
	m_renderState.setPosition(Vec3<float>(0, 0, 0));

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntity(this);
}


Entity::~Entity()
{
}
