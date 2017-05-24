#include "SniperDrop.h"
#include <NetworkManager.h>


SniperDrop::SniperDrop(std::shared_ptr<SceneNode> nodo, const std::string& name) : WeaponDrop(nodo, name)
{
	timeRespawnWeapon = 8;
}


SniperDrop::~SniperDrop()
{
}

void SniperDrop::inicializar()
{
}

void SniperDrop::update(Time elapsedTime)
{

	if (estado == USADO) {
		if (clockRespawnWeapon.getElapsedTime().asSeconds() >= timeRespawnWeapon) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(3.f, 3.f, 3.f));
			m_nodo->setVisible(true);

		}
	}
	else {
		Vec3<float> prev_rot = m_renderState.getRotation();
		prev_rot.addY(5);
		m_renderState.updateRotations(prev_rot);
	}
}

void SniperDrop::handleInput()
{
}

void SniperDrop::cargarContenido()
{
	Vec3<float> pos = getPosition();
	pos.addY(2.f);
	nodo_platform = GraphicEngine::i().createNode(m_renderState.getPosition(), Vec3<float>(1.f, 1.f, 1.f), "", "../media/Props/Plataforma.obj");
	m_nodo = GraphicEngine::i().createNode(pos, Vec3<float>(0.6f, 0.6f, 0.6f), "", "../media/Weapons/sniperDrop.obj");
	m_renderState.setPosition(pos);
}

void SniperDrop::borrarContenido()
{
}

void SniperDrop::handleMessage(const Message & message)
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
					static_cast<Player*>(message.data)->setWeapon(SNIPER);
				if (ClassName == "Enemy_Bot") {
					Enemy_Bot* bot = static_cast<Enemy_Bot*>(message.data);
					bot->setWeapon(SNIPER);
					if (bot->getMachineState()->isInState("BuscarWeapon"))
						bot->getMachineState()->ChangeState(&BuscarWeapon::i());
				}


				m_nodo->setVisible(false);

			}
		}
	}
}

bool SniperDrop::handleTrigger(TriggerRecordStruct * Trigger)
{
	ArmaCogida();
	return true;
}
