
#include "Camera.h"


Camera::Camera(ICameraSceneNode* camera) : m_camera(camera), m_entity(NULL)
{
}


Camera::~Camera()
{
	delete m_camera;
}

void Camera::setTarget(Vec3<float> target)
{
	m_camera->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
}

void Camera::setPosition(Vec3<float> position)
{
	m_camera->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

Vec3<float> Camera::getPosition()
{
	vector3df aux = m_camera->getPosition();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

Vec3<float> Camera::getTarget()
{
	vector3df aux = m_camera->getTarget();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}


void Camera::asignarEntity(Entity* ent)
{
	m_entity = ent;
}

void Camera::update()
{
	if (m_entity != nullptr) {
		setPosition(Vec3<float>(
			m_entity->getRenderPosition().getX(),
			m_entity->getRenderPosition().getY() + m_entity->getNode()->getScale().getY()+2,	//Situamos la camara en el top del player(el +50 es por el mesh que no situa la camara bien)
			m_entity->getRenderPosition().getZ() )
		);
	}
}
