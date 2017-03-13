#include "LifeComponent.h"
#include <Player.h>
#include <Map.h>
#include <NetworkManager.h>

LifeComponent::LifeComponent(Entity * owner) 
	: m_pOwner(owner), m_isDying(false), m_vida(100)
{
}

LifeComponent::~LifeComponent()
{
}
//guid = quien te ha disparado
void LifeComponent::restaVida(float cantidad, RakNet::RakNetGUID guid)
{
	m_vida -= cantidad;
	if (m_vida <= 0 && m_isDying == false) {

		m_isDying = true;
		relojMuerte.restart();



		TPlayer nuevoplayer;
		nuevoplayer.position = m_pOwner->getRenderState()->getPosition();
		nuevoplayer.guid = m_pOwner->getGuid();
		nuevoplayer.name = m_pOwner->getName();


		Entity* ent = EntityManager::i().getRaknetEntity(guid);

		if (ent != NULL && ent->getClassName() == "Enemy_Bot") {
			Message msg(ent, "MATASTE", NULL);
			MessageHandler::i().sendMessageNow(msg);
		}



		NetworkManager::i().dispatchMessage(nuevoplayer, MUERTE);


		TKill kill;
		kill.guidKill = guid;
		kill.guidDeath = m_pOwner->getGuid();

		

		NetworkManager::i().dispatchMessage(kill, ACTUALIZA_TABLA);
	

	}
	
}

void LifeComponent::update()
{
	//Una vez termine la animacion de muerte, volvemos a movernos
	if (m_isDying && relojMuerte.getElapsedTime().asSeconds() > 3) {
		m_isDying = false;
		m_vida = 100;

		m_pOwner->setPosition(Map::i().searchSpawnPoint());
		m_pOwner->resetMachineState();
	}

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
