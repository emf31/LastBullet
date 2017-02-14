#include "SniperDrop.h"
#include <Cliente.h>


SniperDrop::SniperDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
{
}


SniperDrop::~SniperDrop()
{
}

void SniperDrop::inicializar()
{
}

void SniperDrop::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRespawnWeapon.getElapsedTime().asSeconds() >= timeRespawnWeapon) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));
			m_nodo->setVisible(true);

		}
	}
}

void SniperDrop::handleInput()
{
}

void SniperDrop::cargarContenido()
{


}

void SniperDrop::borrarContenido()
{
}

void SniperDrop::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		if (static_cast<Entity*>(message.data)->getClassName() == "Player") {

			if (estado == DISPONIBLE) {
				estado = USADO;
				clockRespawnWeapon.restart();
				if (Cliente::i().isConected()) {
					TId tID;
					tID.id = m_id;

					Cliente::i().dispatchMessage(tID, ARMA_COGIDA);
				}
				static_cast<Player*>(message.data)->setWeapon(SNIPER);
				m_nodo->setVisible(false);

			}
		}
	}
}

bool SniperDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	ArmaCogida();
	return true;
}
