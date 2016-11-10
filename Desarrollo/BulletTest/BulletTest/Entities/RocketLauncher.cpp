#include "RocketLauncher.h"


RocketLauncher::RocketLauncher(SceneNode* nodo, const std::string& name) : Weapon(nodo, name)
{
}


RocketLauncher::~RocketLauncher()
{
}

void RocketLauncher::inicializar()
{
}

void RocketLauncher::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

		}
	}
}

void RocketLauncher::handleInput()
{
}

void RocketLauncher::cargarContenido()
{


}

void RocketLauncher::borrarContenido()
{
}

void RocketLauncher::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		if (estado == DISPONIBLE) {
			PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
			estado = USADO;
			clockRecargaLife.restart();

			static_cast<Player*>(message.data)->setWeapon(LANZACOHETES);

		}
	}
}