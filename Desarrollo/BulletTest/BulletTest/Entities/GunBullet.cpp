#include "GunBullet.h"
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include <TimePerFrame.h>

GunBullet::GunBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation) : EntActive(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(450), m_rotation(rotation)
{
	float distancia = Vec3<float>::getDistance(position, finalposition);
	m_lifetime = seconds(distancia / m_velocity);
	timelifeclock.restart();
}


GunBullet::~GunBullet()
{
}


void GunBullet::inicializar()
{
}

void GunBullet::update(Time elapsedTime)
{

		//float velocity = 10 * timelifeclock.getElapsedTime().asMilliseconds()+42;

		m_renderState.updateVelocity(TimePerFrameClass::GetTimePerFrame().asSeconds(), (m_direction*m_velocity));

		if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds() || timelifeclock.getElapsedTime().asSeconds() > 4) {

			//Enviamos mensaje de borrado para no borrar la entity mientras iteramos el mapa de entities
			Message msg1(this, "BORRATE", NULL);
			MessageHandler::i().sendMessage(msg1);
		}
	


	
}

void GunBullet::handleInput()
{
}

void GunBullet::cargarContenido()
{
	ResourceProvider& resourceProvider = Settings::i().GetResourceProvider();
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(0.05f, 0.05f, 0.05f), "", "../media/bullets/bulletCapsula3.obj");

	m_renderState.setPosition(m_position);


	Vec3<float> vecDir = GraphicEngine::i().getActiveCamera()->getVectorDirection();
	Vec3<float> newPos = vecDir * 0.5f;
	m_nodo->setOrientation(vecDir);
	m_renderState.setPosition(m_position);
	//m_nodo->updatePosition(newPos);
	m_renderState.setRotation(m_rotation);
	m_renderState.setRenderRot(m_rotation);
}

void GunBullet::borrarContenido()
{
	GraphicEngine::i().removeNode(m_nodo);
}

void GunBullet::handleMessage(const Message & message)
{
	if (message.mensaje == "BORRATE") {
		EntityManager::i().removeEntity(this);
		
	}
}

std::string GunBullet::getClassName()
{
	return "Bullet";
}

bool GunBullet::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void GunBullet::setPosition(const Vec3<float>& pos)
{
}
