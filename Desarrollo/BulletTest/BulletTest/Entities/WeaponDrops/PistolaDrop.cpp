#include "PistolaDrop.h"


PistolaDrop::PistolaDrop(std::shared_ptr<BasicSceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
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
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

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
		if (static_cast<Entity*>(message.data)->getClassName() == "Player" || static_cast<Entity*>(message.data)->getClassName() == "Enemy") {

			if (estado == DISPONIBLE) {
				PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
				estado = USADO;
				clockRecargaLife.restart();

				static_cast<Player*>(message.data)->setWeapon(PISTOLA);

			}
		}
		}
}
