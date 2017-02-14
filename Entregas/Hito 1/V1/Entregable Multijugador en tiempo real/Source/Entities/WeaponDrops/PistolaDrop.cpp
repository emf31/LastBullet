#include "PistolaDrop.h"
#include <Cliente.h>


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
		if (static_cast<Entity*>(message.data)->getClassName() == "Player") {

			if (estado == DISPONIBLE) {
				//PhysicsEngine::i().removeGhostObject(m_ghostObject);
				estado = USADO;
				clockRespawnWeapon.restart();

				static_cast<Player*>(message.data)->setWeapon(PISTOLA);

				m_nodo->setVisible(false);
				if (Cliente::i().isConected()) {
					TId tID;
					tID.id = m_id;
					Cliente::i().dispatchMessage(tID, ARMA_COGIDA);
				}
				

			}
		}
	}
}

bool PistolaDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	//ArmaCogida();
	return true;
}

