#include "RocketBullet.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"


RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(300), m_rotation(rotation), radioExplosion(10)
{
	float distancia = Vec3<float>::getDistance(position, finalposition);
	m_lifetime = seconds(distancia / m_velocity);
	timelifeclock.restart();
	//NOTA: llevar cuidado con esto puede que pete aqui
	cargarContenido();
}


RocketBullet::~RocketBullet()
{
}

void RocketBullet::inicializar()
{
}

void RocketBullet::update(Time elapsedTime)
{
	m_renderState.updateVelocity(elapsedTime.asSeconds(), (m_direction*m_velocity));
	if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds() || timelifeclock.getElapsedTime().asSeconds() > 4) {
		//EntityManager::i().removeEntity(this);
		printf("Explosion en %f %f %f\n",m_renderState.getPosition().getX(), m_renderState.getPosition().getY(), m_renderState.getPosition().getZ());

		Message msg1(this, "BORRATE", NULL);

		MessageHandler::i().sendMessage(msg1);
	}

}

void RocketBullet::handleInput()
{
}

void RocketBullet::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(1, 1, 1), "", "");
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);
	m_renderState.setRenderRot(m_rotation);
}

void RocketBullet::borrarContenido()
{
}

void RocketBullet::handleMessage(const Message & message)
{
	if (message.mensaje == "BORRATE") {
		EntityManager::i().removeEntity(this);
		GraphicEngine::i().removeNode(m_nodo);

		///Explosion
		//EntityManager::i().getEntity()

		//delete this;
	}
}

std::string RocketBullet::getClassName()
{
	return "RocketBullet";
}