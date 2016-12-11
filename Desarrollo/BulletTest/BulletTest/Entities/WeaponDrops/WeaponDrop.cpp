#include "WeaponDrop.h"
#include "../../Motor/PhysicsEngine.h"


WeaponDrop::WeaponDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : Entity(-1, nodo, name)
{
}


WeaponDrop::~WeaponDrop()
{
}



void WeaponDrop::asignaTiempo(Clock tiempo) {
	//ponemos el tiempo al tiempo real que el server te envia, cambiamos el estado a usado y quitamos la colision.
	clockRecargaLife = tiempo;
	PhysicsEngine::i().removeGhostObject(m_ghostObject);
	estado = USADO;
	m_nodo->setVisible(false);
}

void WeaponDrop::ArmaCogida()
{

	PhysicsEngine::i().removeGhostObject(m_ghostObject);
	estado = USADO;
	clockRecargaLife.restart();
	m_nodo->setVisible(false);
	

}