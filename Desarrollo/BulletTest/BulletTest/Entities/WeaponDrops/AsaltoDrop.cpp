#include "AsaltoDrop.h"


AsaltoDrop::AsaltoDrop(std::shared_ptr<BasicSceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
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
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

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
		if (estado == DISPONIBLE) {
			PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
			estado = USADO;
			clockRecargaLife.restart();

			static_cast<Player*>(message.data)->setWeapon(ASALTO);

		}
	}
}
