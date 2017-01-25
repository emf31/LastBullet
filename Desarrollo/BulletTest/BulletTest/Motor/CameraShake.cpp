#include "CameraShake.h"
#include <math.h>
#include <Player.h>
#include <EntityManager.h>

CameraShake::CameraShake(Camera& camera):m_camera(camera), m_shakeActive(false), m_amplitud(0.4),m_frecuencia(10)
{
}

void CameraShake::shakeOn()
{
	m_shakeActive = true; 
	m_shakeTime.restart();
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Asalto") {
		m_amplitud = 0.4;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Pistola") {
		m_amplitud = 0.1;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "RocketLauncher") {
		m_amplitud = 0.6;
	}
}

void CameraShake::update()
{
	if (m_shakeActive) {
		//x=A*sen(wt)
		//T=1/w
		//t=1.5T
		if (m_shakeTime.getElapsedTime().asSeconds() < (0.5*(2*PI / m_frecuencia))) {
			posicion = -m_amplitud*sin(m_frecuencia*m_shakeTime.getElapsedTime().asSeconds());

			//m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX(), m_camera.getTarget().getY()-(posicion), m_camera.getTarget().getZ()));
			ISceneNode* nodo=static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeapon()->getNode()->getNodo();
			nodo->setPosition(vector3df(nodo->getPosition().X, nodo->getPosition().Y + posicion, nodo->getPosition().Z));

			
		}
		else{
			m_shakeActive = false;
		}

	}
}
