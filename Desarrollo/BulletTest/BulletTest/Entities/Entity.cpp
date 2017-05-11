
#include "Entity.h"
#include <RenderState.h>
#include "EntityManager.h"


Entity::Entity(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	m_id(id),
	m_nodo(nodo),
	m_name(name),
	m_guid(guid),
	dwTriggerFlags(kTrig_None)
{

}


Entity::~Entity()
{
}

std::shared_ptr<SceneNode> Entity::getNode()
{
	return m_nodo;
}






