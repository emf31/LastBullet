#include "RocketLauncherDrop.h"
#include <NetworkManager.h>

RocketLauncherDrop::RocketLauncherDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
{
}


RocketLauncherDrop::~RocketLauncherDrop()
{
}

void RocketLauncherDrop::inicializar()
{
}

void RocketLauncherDrop::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRespawnWeapon.getElapsedTime().asSeconds() >= timeRespawnWeapon) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));
			m_nodo->setVisible(true);
		}
	}
}

void RocketLauncherDrop::handleInput()
{
}

void RocketLauncherDrop::cargarContenido()
{


}

void RocketLauncherDrop::borrarContenido()
{
}

void RocketLauncherDrop::handleMessage(const Message & message)
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
					static_cast<Player*>(message.data)->setWeapon(LANZACOHETES);
				if (ClassName == "Enemy_Bot") {
					static_cast<Enemy_Bot*>(message.data)->setWeapon(LANZACOHETES);
					static_cast<Enemy_Bot*>(message.data)->getMachineState()->ChangeState(&BuscarWeapon::i());
					std::cout << "Cojo un RocketLauncherDrop" << std::endl;
				}


				m_nodo->setVisible(false);

			}
		}
	}
}

bool RocketLauncherDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	return true;
}




