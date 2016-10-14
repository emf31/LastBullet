#include "stdafx.h"
#include "Entity.h"


Entity::Entity(ISceneNode *nodo)
{
	m_nodo = nodo;

	vector3df vec = m_nodo->getPosition();

	m_posicion = Vec3<float>(vec.X,vec.Y,vec.Z);
	m_velocidad = Vec3<float>(0.f,0.f,0.f);	//Vector velocidad

}


Entity::~Entity()
{
}

void Entity::update(Time elapsedTime)
{
	Vec3<float> vector = Vec3<float>(0.f, 0.f, 0.f);

	if (isMovingForward)
		vector.addX(50.f);
	if (isMovingBackward)
		vector.addX(-50.f);
	if (isMovingLeft)
		vector.addZ(50.f);
	if (isMovingRight)
		vector.addZ(-50.f);

	m_velocidad = vector;
	m_posicion +=  m_velocidad*elapsedTime.asSeconds();
	
	m_nodo->setPosition(vector3df(m_posicion.getX(), m_posicion.getY(), m_posicion.getZ()));
}
