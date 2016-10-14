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


void Entity::update(Time elapsedTime, btRigidBody *TObject)
{
	Vec3<float> vector = Vec3<float>(0.f, 0.f, 0.f);

	//isMovingRight = true;

	if (isMovingForward)
		vector.addX(30.f);
	if (isMovingBackward)
		vector.addX(-30.f);
	if (isMovingLeft)
		vector.addZ(30.f);
	if (isMovingRight)
		vector.addZ(-30.f);

	renderState.setVelocity(vector);

	TObject->setLinearVelocity(btVector3(vector.getX(), vector.getY(), vector.getZ()));
	//renderState.update(elapsedTime);

	// Set position
	btVector3 Point = TObject->getCenterOfMassPosition();
	renderState.setPosition(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));
	TObject->activate(true);
	//m_nodo->setPosition(vector3df((f32)Point[0], (f32)Point[1], (f32)Point[2]));

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = TObject->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;
	m_nodo->setRotation(Euler);
	//m_nodo->setPosition(vector3df(m_posicion.getX(), m_posicion.getY(), m_posicion.getZ()));
}

void Entity::updateRender(float interpolation)
{
	renderState.updateRender(interpolation, m_nodo);
}
