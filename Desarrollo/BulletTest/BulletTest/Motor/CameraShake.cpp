#include "CameraShake.h"
#include <math.h>
#include <Player.h>
#include <EntityManager.h>

CameraShake::CameraShake(Camera& camera):m_camera(camera), m_shakeActive(false), m_amplitud(0.4f),m_frecuencia(10.f)
{
}

void CameraShake::shakeOn()
{
	m_shakeActive = true; 
	m_shakeTime.restart();
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Asalto") {
		m_amplitud = 0.4f;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Pistola") {
		m_amplitud = 0.1f;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "RocketLauncher") {
		m_amplitud = 0.6f;
	}
}

void CameraShake::update()
{
	if (m_shakeActive) {
		if (m_shakeTime.getElapsedTime().asSeconds() < (0.5*(2*M_PI / m_frecuencia))) {
			posicion = -m_amplitud*sin(m_frecuencia*m_shakeTime.getElapsedTime().asSeconds());

			//m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX(), m_camera.getTarget().getY()-(posicion), m_camera.getTarget().getZ()));
			SceneNode* nodo=static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeapon()->getNode().get();
			nodo->setPosition(Vec3<float>(nodo->getPosition().getX(), nodo->getPosition().getY() + posicion, nodo->getPosition().getZ()));
		}
		else{
			m_shakeActive = false;
		}

	}
}
