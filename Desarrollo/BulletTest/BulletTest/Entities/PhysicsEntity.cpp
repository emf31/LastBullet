
#include "PhysicsEntity.h"
#include <Quaternion.h>


PhysicsEntity::PhysicsEntity(std::shared_ptr<StaticSceneNode> nodo, const std::string& name, Vec3<float> position, Vec3<float> rotation, Vec3<float> scale) : 
	EntPassive(-1, nodo, name)
{
	m_scale = scale;
	m_position = position;
	m_rotation = rotation;
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
	//or quat.setEulerZYX depending on the ordering you want
	quat.setEulerZYX(rot.getZ(), rot.getY(), rot.getX());
	m_rigidBody->getWorldTransform().setRotation(quat);

}

void PhysicsEntity::inicializar()
{
	update(Time::Zero);
}

//Metodo static para poder llamarlo desde otros sitios, es mas bien un metodo para llevarlo a Util.h
static Vec3<float> toEulerianAngle(const btQuaternion& q)
{
	Vec3<float> result;

	float ysqr = q.y() * q.y();

	// roll (x-axis rotation)
	float t0 = +2.0 * (q.w() * q.x() + q.y() * q.z());
	float t1 = +1.0 - 2.0 * (q.x() * q.x() + ysqr);
	result.setX(std::atan2(t0, t1));

	// pitch (y-axis rotation)
	float t2 = +2.0 * (q.w() * q.y() - q.z() * q.x());
	t2 = t2 > 1.0 ? 1.0 : t2;
	t2 = t2 < -1.0 ? -1.0 : t2;
	result.setY(std::asin(t2));

	// yaw (z-axis rotation)
	float t3 = +2.0 * (q.w() * q.z() + q.x() * q.y());
	float t4 = +1.0 - 2.0 * (ysqr + q.z() * q.z());

	result.setZ(std::atan2(t3, t4));

	return result;
}

void PhysicsEntity::update(Time elapsedTime)
{


	// Set rotation
	const btQuaternion& TQuat = m_rigidBody->getOrientation();

	//Pasamos el quaternion a angulos euler
	Vec3<float> Euler = toEulerianAngle(TQuat);

	Euler *= RADTODEG;

	m_rotation = Vec3<float>(-Euler.getX(), Euler.getY() + 180, -Euler.getZ());
	

	// Set position restando el center collision para centrar la colision al centro del objeto
	btVector3 Point = m_rigidBody->getCenterOfMassPosition();

	m_position = Vec3<float>((float)Point[0] - centerCollision.getX(), (float)Point[1] - centerCollision.getY(), (float)Point[2] - centerCollision.getX());


	m_nodo->setTransformationMatriz(m_position, m_rotation, m_scale);
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
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	update(Time::Zero);
}
