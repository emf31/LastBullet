
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
	//quat.setEulerZYX(rot.getZ(), rot.getY(), rot.getX()); //or quat.setEulerZYX depending on the ordering you want
	quat.setEulerZYX(rot.getZ(), rot.getY(), rot.getX());
	m_rigidBody->getWorldTransform().setRotation(quat);

}

void PhysicsEntity::inicializar()
{
}

static Vec3<float> toEulerianAngle(const btQuaternion& q)
{
	Vec3<float> result;

	double ysqr = q.y() * q.y();

	// roll (x-axis rotation)
	double t0 = +2.0 * (q.w() * q.x() + q.y() * q.z());
	double t1 = +1.0 - 2.0 * (q.x() * q.x() + ysqr);
	result.setX(std::atan2(t0, t1));

	// pitch (y-axis rotation)
	double t2 = +2.0 * (q.w() * q.y() - q.z() * q.x());
	t2 = t2 > 1.0 ? 1.0 : t2;
	t2 = t2 < -1.0 ? -1.0 : t2;
	result.setY(std::asin(t2));

	// yaw (z-axis rotation)
	double t3 = +2.0 * (q.w() * q.z() + q.x() * q.y());
	double t4 = +1.0 - 2.0 * (ysqr + q.z() * q.z());

	result.setZ(std::atan2(t3, t4));

	return result;
}

void PhysicsEntity::update(Time elapsedTime)
{


	// Set rotation
	//btVector3 Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	//quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	//q.toEuler(cons(Euler));

	Vec3<float> Euler = toEulerianAngle(TQuat);

	Euler *= RADTODEG;

	//m_nodo->setRotationXYZ(Vec3<float>(-m_renderRotation.getX(), m_renderRotation.getY() + 180, -m_renderRotation.getZ()));

	m_renderState.updateRotations(Vec3<float>(-Euler.getX(), Euler.getY() + 180, -Euler.getZ()));

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
