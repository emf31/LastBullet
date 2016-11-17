
#include "Entity.h"
#include "../Motor/RenderState.h"
#include "EntityManager.h"


Entity::Entity(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	m_id(id),
	m_nodo(nodo),
	m_name(name),
	m_renderState(),
	m_guid(guid)
{

	if (m_nodo) {
		m_renderState.setPosition(m_nodo.get()->getPosition());
	}
	else {
		m_renderState.setPosition(Vec3<float>(0,0,0));
	}

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntity(this);
}


Entity::~Entity()
{
}

void Entity::updateRender(float interpolation)
{
	m_renderState.updateRender(interpolation, m_nodo);
}

Vec3<float> Entity::getRenderPosition()
{
	return m_renderState.getRenderPos();
}

std::shared_ptr<SceneNode> Entity::getNode()
{
	return m_nodo;
}


