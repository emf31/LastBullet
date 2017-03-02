#include "AsaltoDrop.h"
#include <NetworkManager.h>

AsaltoDrop::AsaltoDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
{
}


AsaltoDrop::~AsaltoDrop()
{
}

void AsaltoDrop::inicializar()
{
}

void AsaltoDrop::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRespawnWeapon.getElapsedTime().asSeconds() >= timeRespawnWeapon) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));
			m_nodo->setVisible(true);

		}
	}
}

void AsaltoDrop::handleInput()
{
}

void AsaltoDrop::cargarContenido()
{


}

void AsaltoDrop::borrarContenido()
{
}

void AsaltoDrop::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {



		std::string ClassName = static_cast<Entity*>(message.data)->getClassName();

		if (ClassName == "Player" || ClassName == "Enemy_Bot") {

			if (estado == DISPONIBLE) {
				estado = USADO;
				clockRespawnWeapon.restart();

				TId tID;
				tID.id = m_id;

				NetworkManager::i().dispatchMessage(tID, ARMA_COGIDA);


				if (ClassName == "Player")
					static_cast<Player*>(message.data)->setWeapon(ASALTO);
				if (ClassName == "Enemy_Bot") {
					Enemy_Bot* bot = static_cast<Enemy_Bot*>(message.data);
					bot->setWeapon(ASALTO);
					if (bot->getMachineState()->isInState("BuscarWeapon"))
						bot->getMachineState()->ChangeState(&BuscarWeapon::i());
				}

				m_nodo->setVisible(false);

			}
		}
	}
}

bool AsaltoDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	return true;
}
