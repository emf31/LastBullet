#include "LifeObject.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor de Red/Cliente.h"

LifeObject::LifeObject(std::shared_ptr<SceneNode> nodo, const std::string& name) : Entity(-1, nodo, name)
{

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
}

void LifeObject::update(Time elapsedTime)
{


	if (estado == USADO) {
		if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
			estado = DISPONIBLE;
			m_ghostObject = PhysicsEngine::i().createBoxGhostObject(this, Vec3<float>(1.f, 1.f, 1.f));
			m_nodo->setVisible(true);
		}
	}
	
}

void LifeObject::handleInput()
{
}

void LifeObject::cargarContenido()
{


}

void LifeObject::borrarContenido()
{
}

void LifeObject::handleMessage(const Message & message)
{
	if (message.mensaje == "COLLISION") {
		if (static_cast<Entity*>(message.data)->getClassName() == "Player") {

			if (estado == DISPONIBLE) {
				PhysicsEngine::i().removeGhostObject(m_ghostObject);
				estado = USADO;
				clockRecargaLife.restart();

				if (Cliente::i().isConected())
					Cliente::i().vidaCogida(m_id);

				
				m_nodo->setVisible(false);

				static_cast<Player*>(message.data)->sumarVida();

			}


		}
	}
}

void LifeObject::asignaTiempo(Clock tiempo) {
	//ponemos el tiempo al tiempo real que el server te envia, cambiamos el estado a usado y quitamos la colision.
	clockRecargaLife = tiempo;
	PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
	estado = USADO;
	m_nodo->setVisible(false);
}

void LifeObject::VidaCogida()
{
	PhysicsEngine::i().m_world->removeCollisionObject(m_ghostObject);
	estado = USADO;
	m_nodo->setVisible(false);
	clockRecargaLife.restart();
	

}
