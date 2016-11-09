#include "Bullet.h"
#include "../Motor/GraphicEngine.h"


Bullet::Bullet(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition) : Entity(-1, NULL),
m_position(position), m_direction(direction), m_velocity(2)
{
	float distancia = Vec3<float>::getDistance(position, finalposition);
	m_lifetime = seconds(distancia / m_velocity);
	timelifeclock.restart();
	//NOTA: llevar cuidado con esto puede que pete aqui
	cargarContenido();
}


Bullet::~Bullet()
{
}

void Bullet::inicializar()
{
}

void Bullet::update(Time elapsedTime)
{
	m_renderState.updateVelocity(elapsedTime.asSeconds(), (m_direction*m_velocity));
	if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds() || timelifeclock.getElapsedTime().asSeconds() > 20) {
		EntityManager::i().removeEntity(this);
	}
	
}

void Bullet::handleInput()
{
}

void Bullet::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(0.1, 0.1, 0.1), "", "../media/bullet.obj");
	m_renderState.setPosition(m_position);
}

void Bullet::borrarContenido()
{
}

void Bullet::handleMessage(const Message & message)
{
}

std::string Bullet::getClassName()
{
	return "Bullet";
}
