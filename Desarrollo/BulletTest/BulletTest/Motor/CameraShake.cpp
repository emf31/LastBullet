#include "CameraShake.h"
#include <math.h>

CameraShake::CameraShake(Camera& camera):m_camera(camera), m_shakeActive(false), m_amplitud(0.8),m_frecuencia(20)
{
}

void CameraShake::update()
{
	if (m_shakeActive) {
		//x=A*sen(wt)
		//T=1/w
		//t=1.5T
		if (m_shakeTime.getElapsedTime().asSeconds() < (1.5*(2*PI / m_frecuencia))) {
			posicion = -m_amplitud*sin(m_frecuencia*m_shakeTime.getElapsedTime().asSeconds());
			m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX(), m_camera.getTarget().getY() + posicion, m_camera.getTarget().getZ()));
		}
		else{
			m_shakeActive = false;
		}

	}
}
