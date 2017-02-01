
#include "Camera.h"
#include <CameraShake.h>
#include <GunRecoil.h>


Camera::Camera(ICameraSceneNode* camera) : m_camera(camera), m_entity(NULL)
{
	m_cameraShake = new CameraShake(*this);
	m_GunRecoil = new GunRecoil(*this);
	defaultFOV = m_camera->getFOV(); // this is in radians 
	defaultAspect = m_camera->getAspectRatio();
	zoomFOV = 0.25f;
}


Camera::~Camera()
{
	delete m_camera;
	delete m_cameraShake;
	delete m_GunRecoil;
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
			m_entity->getRenderPosition().getY() + 8,	//Situamos la camara en el top del player(el +50 es por el mesh que no situa la camara bien)
			m_entity->getRenderPosition().getZ())
		);
	}
	m_cameraShake->update();
	m_GunRecoil->update();

}

Vec3<float> Camera::getRotation() {
	return Vec3<float> (m_camera->getRotation().X, m_camera->getRotation().Y, m_camera->getRotation().Z);
}

void Camera::cameraShake()
{
	m_cameraShake->shakeOn();
}
void Camera::cameraRecoil()
{
	m_GunRecoil->RecoilOn();
}

void Camera::apuntar()
{
	m_camera->setFOV(zoomFOV);
}

void Camera::restablecerMira()
{
	m_camera->setFOV(defaultFOV);
}
