
#include "Camera.h"
#include <CameraShake.h>
#include <GunRecoil.h>
#include <Player.h>


Camera::Camera(TCamera* camera, const std::string &nombre) : m_camera(camera), m_pName(nombre),  m_entity(NULL)
{
	m_cameraShake = new CameraShake(*this);
	m_GunRecoil = new GunRecoil(*this);
	//defaultFOV = m_camera->getFOV(); // this is in radians 
	//defaultAspect = m_camera->getAspectRatio();
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
	m_camera->setTarget(target);
}

void Camera::setPosition(Vec3<float> position)
{
	m_camera->setPosition(position);
	
}

Vec3<float> Camera::getPosition()
{
	return m_camera->getPosition();
}

Vec3<float> Camera::getTarget()
{
	return m_camera->getTarget();
}




void Camera::setRotationX(float angulo) {
	m_camera->setRotationX(angulo);
}

void Camera::setRotationY(float angulo) {
	m_camera->setRotationY(angulo);
}

void Camera::setRotationZ(float angulo) {
	m_camera->setRotationZ(angulo);
}

Vec3<float> Camera::getVecRight()
{
	//return m_camera->getDerecha();
	return Vec3<float>(0,0,0);
}



void Camera::asignarEntity(Character* ent)
{
	m_entity = ent;
}

void Camera::update()
{

	if (m_entity != nullptr) {

		if (m_entity->getClassName() == "Player") {
			setPosition(Vec3<float>(
						m_entity->getRenderPosition().getX(),
						m_entity->getRenderPosition().getY() + 3.f,
						m_entity->getRenderPosition().getZ())
			);
			//m_cameraShake->update();
			//m_GunRecoil->update(static_cast<Player*>(m_entity)->isShooting);
		}
		if (m_entity->getClassName() == "Enemy_Bot")
			setPosition(Vec3<float>(
				m_entity->getRenderPosition().getX(),
				m_entity->getRenderPosition().getY() + 3.f,
				m_entity->getRenderPosition().getZ())
			);

	}
	

}

Vec3<float> Camera::getRotation() {
	return m_camera->getRotation();
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
	//m_camera->setFOV(zoomFOV);

}

void Camera::restablecerMira()
{
	//m_camera->setFOV(defaultFOV);
}
