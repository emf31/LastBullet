#include "LifeComponent.h"
#include <Player.h>
#include <Cliente.h>

LifeComponent::LifeComponent(Player * player)
{
	m_player = player;
	m_isDying = false;
}

LifeComponent::~LifeComponent()
{
}
void LifeComponent::restaVida(float cantidad, RakNet::RakNetGUID guid)
{
	m_vida -= cantidad;
	if (m_vida <= 0 && m_isDying == false) {

		m_isDying = true;
		relojMuerte.restart();

		if (Cliente::i().isConected()) {
			Cliente::i().playerMuerto();
			Cliente::i().actualizaTabla(guid, m_player->getGuid());
		}

	}
	
}

bool LifeComponent::update()
{
	//Una vez termine la animacion de muerte, volvemos a movernos
	if (m_isDying && relojMuerte.getElapsedTime().asSeconds() > 3) {
		m_isDying = false;
		m_vida = 100;

		m_player->searchSpawnPoint();
		m_player->resetAll();
	}

	return m_isDying;
}

void LifeComponent::resetVida()
{
	m_vida = 100;
}

float LifeComponent::getVida()
{
	return m_vida;
}

void LifeComponent::sumarVida()
{
	m_vida += 40;
	if (m_vida > 100) {
		m_vida = 100;
	}
}

bool LifeComponent::isDying()
{
	return m_isDying;
}
