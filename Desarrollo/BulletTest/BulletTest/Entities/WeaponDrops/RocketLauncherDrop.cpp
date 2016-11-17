#include "RocketLauncherDrop.h"


RocketLauncherDrop::RocketLauncherDrop(std::shared_ptr<BasicSceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
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
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

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
		if (static_cast<Entity*>(message.data)->getClassName() == "Player" || static_cast<Entity*>(message.data)->getClassName() == "Enemy") {

			if (estado == DISPONIBLE) {
				PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
				estado = USADO;
				clockRecargaLife.restart();

				static_cast<Player*>(message.data)->setWeapon(LANZACOHETES);

			}

		}
	}
}

