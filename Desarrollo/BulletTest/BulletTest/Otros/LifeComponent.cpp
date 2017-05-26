#include "LifeComponent.h"
#include <Player.h>
#include <Map.h>
#include <NetworkManager.h>
#include <Character.h>
#include <InGameHUD.h>
#include <CharacterTypes.h>
#include <SoundManager.h>
#include <Death.h>
#include <AnimationMachine.h>

LifeComponent::LifeComponent(Character * owner) 
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

	if (m_vida <= 0) {
		m_vida = 0;
	}

	if (m_vida <= 0 && m_isDying == false) {

		if (m_pOwner->getClassName() == "Player") {
			GraphicEngine::i().updateDeathCamera();
			GraphicEngine::i().setActiveCamera("CameraDeath");
			static_cast<InGameHUD*>(GUIManager::i().getGUIbyName("InGameHUD"))->setVisibleAllHUD(false);
			m_pOwner->getNode()->setVisible(true);
			m_pOwner->getAnimationMachine()->ChangeState(&Death::i());
			
		}



		m_isDying = true;
		relojMuerte.restart();

		SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename(CharacterTypes::getRandomDeath(), "sounds"), m_pOwner->getPosition(), Sound::type::sound);

		RakID nuevoplayer;
		nuevoplayer.guid = m_pOwner->getGuid();
		

		Entity* ent = EntityManager::i().getRaknetEntity(guid);

		if (ent != NULL && ent->getClassName() == "Enemy_Bot") {
			Message msg(ent, "MATASTE", NULL);
			MessageHandler::i().sendMessageNow(msg);
		}

		NetworkManager::i().dispatchMessage(nuevoplayer, MUERTE);

		m_pOwner->resetAll();


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
		if (m_pOwner->getClassName() == "Player") {
			GraphicEngine::i().setActiveCamera("CamaraPlayer");
			static_cast<InGameHUD*>(GUIManager::i().getGUIbyName("InGameHUD"))->setVisibleAllHUD(true);
			m_pOwner->getNode()->setVisible(false);
		}
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
