
#include "Entity.h"
#include "../RenderState.h"
#include "EntityManager.h"


Entity::Entity(int id, SceneNode* nodo, const std::string& name) :
	m_id(id),
	m_nodo(nodo),
	m_name(name),
	m_renderState()
{

	if (m_nodo) {
		m_renderState.setPosition(m_nodo->getPosition());
	}
	else {
		m_renderState.setPosition(Vec3<float>(0,0,0));
	}
	

	//tiempoSalto.restart();

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

SceneNode * Entity::getNode()
{
	return m_nodo;
}
