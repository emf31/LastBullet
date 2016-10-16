#include "stdafx.h"
#include "Entity.h"
#include "../RenderState.h"
#include "EntityManager.h"


Entity::Entity(int id, ISceneNode* nodo, const std::string& name) :
	m_id(id),
	m_nodo(nodo),
	m_name(name),
	m_renderState()
{

	if (m_nodo) {
		vector3df vec = m_nodo->getPosition();
		m_renderState.setPosition(Vec3<float>(vec.X, vec.Y, vec.Z));
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
