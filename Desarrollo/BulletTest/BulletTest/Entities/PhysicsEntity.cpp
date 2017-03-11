
#include "PhysicsEntity.h"
#include <Quaternion.h>

PhysicsEntity::PhysicsEntity(std::shared_ptr<BasicSceneNode> nodo, const std::string& name) : Entity(-1, nodo, name)
{
	
}


PhysicsEntity::~PhysicsEntity()
{
}

void PhysicsEntity::setCollisionGroup(int group) {
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = group;
}

void PhysicsEntity::setCollisionMask(int mask) {
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterMask = mask;

}

void PhysicsEntity::rotate(Vec3<float> rot)
{

	btQuaternion quat;
	quat.setEulerZYX(rot.getX(), rot.getY(), rot.getZ()); //or quat.setEulerZYX depending on the ordering you want

	m_rigidBody->getWorldTransform().setRotation(quat);

}

void PhysicsEntity::inicializar()
{
}

void PhysicsEntity::update(Time elapsedTime)
{


	// Set rotation
	btVector3 Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(cons(Euler));

	Euler *= RADTODEG;

	m_renderState.updateRotations(Vec3<float>(Euler.getX(), Euler.getY(), Euler.getZ()));

	// Set position
	//m_rigidBody->setm
	//btVector3 Point2 = m_rigidBody->getCenterOfMassTransform().getOrigin();
	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	//if(centerCollision==NULL)


	m_renderState.updatePositions(Vec3<float>((float)Point[0]-centerCollision.getX(), (float)Point[1]-centerCollision.getY(), (float)Point[2]-centerCollision.getX()));

	//m_rigidBody->pos
}

void PhysicsEntity::handleInput()
{
}

void PhysicsEntity::cargarContenido()
{


}

void PhysicsEntity::borrarContenido()
{
}

void PhysicsEntity::handleMessage(const Message & message)
{

}

bool PhysicsEntity::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void PhysicsEntity::setPosition(const Vec3<float>& pos)
{
	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);
}
