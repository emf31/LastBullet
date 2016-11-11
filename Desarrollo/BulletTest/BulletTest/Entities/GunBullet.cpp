#include "GunBullet.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"


GunBullet::GunBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(450), m_rotation(rotation)
{
	float distancia = Vec3<float>::getDistance(position, finalposition);
	m_lifetime = seconds(distancia / m_velocity);
	timelifeclock.restart();
	//NOTA: llevar cuidado con esto puede que pete aqui
	cargarContenido();
}


GunBullet::~GunBullet()
{
}

void GunBullet::inicializar()
{
}

void GunBullet::update(Time elapsedTime)
{
	m_renderState.updateVelocity(elapsedTime.asSeconds(), (m_direction*m_velocity));
	if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds() || timelifeclock.getElapsedTime().asSeconds() > 4) {
		//EntityManager::i().removeEntity(this);
		

		Message msg1(this, "BORRATE", NULL);

		MessageHandler::i().sendMessage(msg1);
	}
	
}

void GunBullet::handleInput()
{
}

void GunBullet::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(0.1, 0.1, 0.1), "", "../media/bullet.obj");
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);
	m_renderState.setRenderRot(m_rotation);
}

void GunBullet::borrarContenido()
{
}

void GunBullet::handleMessage(const Message & message)
{
	if (message.mensaje == "BORRATE") {
		EntityManager::i().removeEntity(this);
		GraphicEngine::i().removeNode(m_nodo);
		//delete this;
	}
}

std::string GunBullet::getClassName()
{
	return "Bullet";
}
