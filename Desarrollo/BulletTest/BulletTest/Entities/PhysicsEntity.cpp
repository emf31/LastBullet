
#include "PhysicsEntity.h"


PhysicsEntity::PhysicsEntity(std::shared_ptr<BasicSceneNode> nodo, const std::string& name) : Entity(-1, nodo, name)
{
	
}


PhysicsEntity::~PhysicsEntity()
{
}

void PhysicsEntity::rotate(Vec3<float> rot)
{
	btTransform tr;
	tr.setIdentity();
	btQuaternion quat;
	quat.setEulerZYX(rot.getX(), rot.getY(), rot.getZ()); //or quat.setEulerZYX depending on the ordering you want
	tr.setRotation(quat);

	m_rigidBody->getWorldTransform().setRotation(quat);
	//m_rigidBody->setCenterOfMassTransform(tr);
}

void PhysicsEntity::inicializar()
{
}

void PhysicsEntity::update(Time elapsedTime)
{


	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;

	m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));

	// Set position
	//m_rigidBody->setm
	//btVector3 Point2 = m_rigidBody->getCenterOfMassTransform().getOrigin();
	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

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
