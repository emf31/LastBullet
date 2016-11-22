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

	btRigidBody* m_rigidBody;
	int estado=DISPONIBLE;

	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message & message) override;

	virtual std::string getClassName() override;

	float explosion(Vec3<float>posExplosion,Vec3<float>posCharacter,float radio);

	btGhostObject* m_explosion;

};