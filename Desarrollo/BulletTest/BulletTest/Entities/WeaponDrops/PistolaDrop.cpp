#include "PistolaDrop.h"

#include <NetworkManager.h>


PistolaDrop::PistolaDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
{
}


PistolaDrop::~PistolaDrop()
{
}

void PistolaDrop::inicializar()
{
}

void PistolaDrop::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRespawnWeapon.getElapsedTime().asSeconds() >= timeRespawnWeapon) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));
			
			m_nodo->setVisible(true);
		}
	}
}

void PistolaDrop::handleInput()
{
}

void PistolaDrop::cargarContenido()
{


}

void PistolaDrop::borrarContenido()
{
}

void PistolaDrop::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		std::string tipo = static_cast<Entity*>(message.data)->getClassName();
		if (tipo == "Player" || tipo == "Enemy_Bot") {

			if (estado == DISPONIBLE) {
				estado = USADO;
				clockRespawnWeapon.restart();

				if (tipo == "Player")
					static_cast<Player*>(message.data)->setWeapon(PISTOLA);
				if (tipo == "Enemy_Bot") {
					static_cast<Enemy_Bot*>(message.data)->setWeapon(PISTOLA);
				}
				m_nodo->setVisible(false);

				TId tID;
				tID.id = m_id;
				NetworkManager::i().dispatchMessage(tID, ARMA_COGIDA);


			}
		}
	}
}

bool PistolaDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	return true;
}

