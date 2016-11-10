#include "Pistola.h"


Pistola::Pistola(SceneNode* nodo, const std::string& name) : Weapon(nodo, name)
{
}


Pistola::~Pistola()
{
}

void Pistola::inicializar()
{
}

void Pistola::update(Time elapsedTime)
{
	if (estado == USADO) {
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(5.f, 5.f, 5.f));

		}
	}
}

void Pistola::handleInput()
{
}

void Pistola::cargarContenido()
{


}

void Pistola::borrarContenido()
{
}

void Pistola::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		if (estado == DISPONIBLE) {
			PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
			estado = USADO;
			clockRecargaLife.restart();

			static_cast<Player*>(message.data)->setWeapon(PISTOLA);

		}
	}
}
