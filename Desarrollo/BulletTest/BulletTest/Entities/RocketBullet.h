#pragma once

#include "../Otros/vec3.hpp"
#include "Entity.h"
#include "EntityManager.h"
#include "../Otros/Time.hpp"
#include "../Otros/Clock.hpp"
#include "BulletCollision\CollisionDispatch\btGhostObject.h"

class RocketBullet : public Entity
{
public:
	RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation);
	~RocketBullet();

private:
	float radioExplosion;
	Vec3<float> m_direction;
	Vec3<float> m_position;
	Vec3<float> m_rotation;
	float m_velocity;
	Time m_lifetime;
	Clock timelifeclock;

	float radioExplosion;

//	btGhostObject* m_explosion;
	btGhostObject* m_ghostObject;


	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message & message) override;

	virtual std::string getClassName() override;

	float explosion(Vec3<float>posExplosion,Vec3<float>posCharacter,float radio);

	void setPosition() {

		Vec3<float> pos=m_renderState.getPosition();
		//m_currentPosition = m_ghostObject->getWorldTransform().getOrigin();

		btTransform transform = m_ghostObject->getWorldTransform();
		transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
		m_ghostObject->setWorldTransform(transform);

		m_nodo->setPosition(pos);
	}

};