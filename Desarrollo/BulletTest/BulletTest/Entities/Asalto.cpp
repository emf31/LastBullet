#include "Asalto.h"


Asalto::Asalto(SceneNode* nodo, const std::string& name) : Weapon(nodo, name)
{
}


Asalto::~Asalto()
{
}

void Asalto::inicializar()
{
}

void Asalto::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

		}
	}
}

void Asalto::handleInput()
{
}

void Asalto::cargarContenido()
{


}

void Asalto::borrarContenido()
{
}

void Asalto::handleMessage(const Message & message)
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
