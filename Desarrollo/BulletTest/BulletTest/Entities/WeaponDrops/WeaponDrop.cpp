#include "WeaponDrop.h"
#include "../../Motor/PhysicsEngine.h"


WeaponDrop::WeaponDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : EntActive(-1, nodo, name), timeRespawnWeapon(3), m_ghostObject(nullptr)
{
}


WeaponDrop::~WeaponDrop()
{
}



void WeaponDrop::setPosition(const Vec3<float>& pos)
{
	m_renderState.setPosition(pos);

	btTransform transform = m_ghostObject->getWorldTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_ghostObject->setWorldTransform(transform);

	m_nodo->setPosition(pos);
}

void WeaponDrop::asignaTiempo(Clock tiempo) {
	//ponemos el tiempo al tiempo real que el server te envia, cambiamos el estado a usado y quitamos la colision.
	if (m_ghostObject) {
		PhysicsEngine::i().removeGhostObject(m_ghostObject);
		m_ghostObject = nullptr;
	}
	estado = USADO;
	m_nodo->setVisible(false);
	clockRespawnWeapon = tiempo;
}

void WeaponDrop::ArmaCogida()
{
	//if (estado == DISPONIBLE) {
	if (m_ghostObject) {
		PhysicsEngine::i().removeGhostObject(m_ghostObject);
		m_ghostObject = nullptr;
	}
		
		estado = USADO;
		clockRespawnWeapon.restart();
		m_nodo->setVisible(false);
	//}

	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("pickup.wav", "sounds"), getPosition(), Sound::type::sound);
}