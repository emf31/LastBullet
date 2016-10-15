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


void Entity::update(Time elapsedTime, btRigidBody *TObject, ISceneManager *irrScene,int player)
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

	if(player){
		Vec3<float> target=Vec3<float>(
			irrScene->getActiveCamera()->getTarget().X,
			irrScene->getActiveCamera()->getTarget().Y,
			irrScene->getActiveCamera()->getTarget().Z
		);
		
		Vec3<float> posicion = Vec3<float>(m_nodo->getPosition().X, m_nodo->getPosition().Y, m_nodo->getPosition().Z);
		Vec3<float> speed = target - posicion;
		Vec3<float> speedFinal = Vec3<float>(0,0,0);

		if (isMovingForward) {
			speedFinal.setX(speedFinal.getX() + speed.getX());
			speedFinal.setZ(speedFinal.getZ() + speed.getZ());
		}
		if (isMovingBackward) {
			speedFinal.setX(speedFinal.getX() - speed.getX());
			speedFinal.setZ(speedFinal.getZ() - speed.getZ());
		}
		if (isMovingLeft) {
			speedFinal.setX(speedFinal.getX() - speed.getZ());
			speedFinal.setZ(speedFinal.getZ() + speed.getX());
		}
		if (isMovingRight) {
			speedFinal.setX(speedFinal.getX() + speed.getZ());
			speedFinal.setZ(speedFinal.getZ() - speed.getX());
		}
		speedFinal.normalise();
		TObject->setLinearVelocity(btVector3(speedFinal.getX()*50.f, speedFinal.getY(), speedFinal.getZ()*50.f));
			
	}
	else {
		TObject->setLinearVelocity(btVector3(vector.getX(), vector.getY(), vector.getZ()));
	}

	// Set position
	btVector3 Point = TObject->getCenterOfMassPosition();
	renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = TObject->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;

	//m_nodo->setRotation(Euler);
	renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));
}

void Entity::updateRender(float interpolation)
{
	renderState.updateRender(interpolation, m_nodo);
}

Vec3<float> Entity::getRenderPosition()
{
	return renderState.getRenderPos();
}
