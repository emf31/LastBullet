#include "LifeObject.h"
#include <PhysicsEngine.h>
#include <TriggerSystem.h>
#include <NetworkManager.h>

LifeObject::LifeObject(std::shared_ptr<SceneNode> nodo, const std::string& name) : EntActive(-1, nodo, name), m_ghostObject(nullptr)
{
	//TriggerSystem::i().RegisterEntity(this);
}


LifeObject::~LifeObject()
{
}

void LifeObject::rotate(Vec3<float> rot)
{
	/*btTransform tr;
	tr.setIdentity();
	btQuaternion quat;
	quat.setEulerZYX(rot.getX(), rot.getY(), rot.getZ()); //or quat.setEulerZYX depending on the ordering you want
	tr.setRotation(quat);

	m_rigidBody->setCenterOfMassTransform(tr);*/
}

void LifeObject::inicializar()
{
	timeRecargaLife = 4;
}

void LifeObject::update(Time elapsedTime)
{

	if (estado == USADO) {
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
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

void LifeObject::handleInput()
{
}

void LifeObject::cargarContenido()
{
	Vec3<float> pos = getPosition();
	pos.addY(2.f);
	nodo_platform = GraphicEngine::i().createNode(m_renderState.getPosition(), Vec3<float>(1.f, 1.f, 1.f), "", "../media/Props/Plataforma.obj");
	m_nodo = GraphicEngine::i().createNode(pos, Vec3<float>(0.6f, 0.6f, 0.6f), "", "../media/Weapons/MedkitFinalV2.obj");
	m_renderState.setPosition(pos);

}

void LifeObject::borrarContenido()
{
}

void LifeObject::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {

		std::string ClassName = static_cast<Entity*>(message.data)->getClassName();

		if (ClassName == "Player" || ClassName == "Enemy_Bot") {

			if (estado == DISPONIBLE) {

				SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("health.mp3", "sounds"), getPosition(), Sound::type::sound);

				//PhysicsEngine::i().removeGhostObject(m_ghostObject);
				estado = USADO;
				clockRecargaLife.restart();

				TId s_id;
				s_id.id = m_id;

				NetworkManager::i().dispatchMessage(s_id, VIDA_COGIDA);
				
				m_nodo->setVisible(false);

				if (ClassName == "Player")
					static_cast<Player*>(message.data)->getLifeComponent().sumarVida();
				else if (ClassName == "Enemy_Bot") {

					Enemy_Bot* bot = static_cast<Enemy_Bot*>(message.data);
					bot->getLifeComponent().sumarVida();
					if (bot->getMachineState()->isInState("BuscarVida"))
						bot->getMachineState()->RevertToPreviousState();
				
				}

			}


		}
	}
}

bool LifeObject::handleTrigger(TriggerRecordStruct* Trigger) {

	if (Trigger->eTriggerType == kTrig_Explosion) {
		//printf("Has disparado cerca de un lifeObject\n");
	}
	else if (Trigger->eTriggerType == kTrig_EnemyNear) {
		//printf("Has saltado cerca de un lifeObject\n");

	}
	
	//m_nodo->setVisible(false);

	//VidaCogida();

	return true;
}

void LifeObject::setPosition(const Vec3<float>& pos)
{
	m_renderState.setPosition(pos);

	btTransform transform = m_ghostObject->getWorldTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_ghostObject->setWorldTransform(transform);

	m_nodo->setPosition(pos);
}

void LifeObject::setCollisionGroup(int group) {
	btBroadphaseProxy* proxy = m_ghostObject->getBroadphaseHandle();
	proxy->m_collisionFilterGroup = group;
}

void LifeObject::setCollisionMask(int mask) {
	btBroadphaseProxy* proxy = m_ghostObject->getBroadphaseHandle();
	proxy->m_collisionFilterMask = mask;

}

void LifeObject::asignaTiempo(Clock tiempo) {
	//ponemos el tiempo al tiempo real que el server te envia, cambiamos el estado a usado y quitamos la colision.
	clockRecargaLife = tiempo;
	
	estado = USADO;
	m_nodo->setVisible(false);
	if (m_ghostObject) {
		PhysicsEngine::i().removeGhostObject(m_ghostObject);
		m_ghostObject = nullptr;
	}
}

void LifeObject::VidaCogida()
{

	if (m_ghostObject) {
		PhysicsEngine::i().removeGhostObject(m_ghostObject);
		m_ghostObject = nullptr;
	}
	estado = USADO;
	m_nodo->setVisible(false);
	clockRecargaLife.restart();

	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("health.mp3", "sounds"), getPosition(),Sound::type::sound);

}

