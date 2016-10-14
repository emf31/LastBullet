#include "stdafx.h"
#include "Entity.h"
#include "../RenderState.h"


Entity::Entity(ISceneNode *nodo)
{
	m_nodo = nodo;

	vector3df vec = m_nodo->getPosition();
	renderState.setPosition(Vec3<float>(vec.X, vec.Y, vec.Z));
	renderState.setVelocity(Vec3<float>(0.f, 0.f, 0.f));

}


Entity::~Entity()
{
}


void Entity::update(Time elapsedTime)
{
	Vec3<float> vector = Vec3<float>(0.f, 0.f, 0.f);

	if (isMovingForward)
		vector.addX(150.f);
	if (isMovingBackward)
		vector.addX(-150.f);
	if (isMovingLeft)
		vector.addZ(150.f);
	if (isMovingRight)
		vector.addZ(-150.f);

	renderState.setVelocity(vector);
	renderState.update(elapsedTime);
	
	//m_nodo->setPosition(vector3df(m_posicion.getX(), m_posicion.getY(), m_posicion.getZ()));
}

void Entity::updateRender(float interpolation)
{
	renderState.updateRender(interpolation, m_nodo);
}
