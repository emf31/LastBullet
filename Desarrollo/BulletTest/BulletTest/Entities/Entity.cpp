#include "stdafx.h"
#include "Entity.h"
#include "../RenderState.h"


Entity::Entity(int id, ISceneNode* nodo, const std::string& name) :	
	m_id(id),
	m_nodo(nodo), 
	m_name(name)
{
	vector3df vec = m_nodo->getPosition();
	m_renderState.setPosition(Vec3<float>(vec.X, vec.Y, vec.Z));

	//tiempoSalto.restart();
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
