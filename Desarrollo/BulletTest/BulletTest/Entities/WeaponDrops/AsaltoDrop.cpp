#include "AsaltoDrop.h"
#include "../../Motor de Red/Cliente.h"


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
		if (static_cast<Entity*>(message.data)->getClassName() == "Player") {

			if (estado == DISPONIBLE) {
				//PhysicsEngine::i().removeGhostObject(m_ghostObject);
				estado = USADO;
				clockRespawnWeapon.restart();
				if (Cliente::i().isConected())
					Cliente::i().armaCogida(m_id);
				static_cast<Player*>(message.data)->setWeapon(ASALTO);
				m_nodo->setVisible(false);

			}
		}
		}
}
