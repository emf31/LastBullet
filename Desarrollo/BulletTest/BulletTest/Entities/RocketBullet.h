#pragma once

#include <vec3.hpp>
#include <EntActive.h>
#include <EntityManager.h>
#include <Time.hpp>
#include <Clock.hpp>
#include <BulletCollision\CollisionDispatch\btGhostObject.h>
#include <Character.h>

class RocketBullet : public EntActive
{
public:
	RocketBullet(Character* owner, Vec3<float> position, Vec3<float> direction, Vec3<float> rotation);
	virtual ~RocketBullet();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual std::string getClassName() override;
	virtual void setPosition(const Vec3<float> &pos) override;

private:
	float radioExplosion;
	Vec3<float> m_direction;
	Vec3<float> m_position;
	Vec3<float> m_rotation;
	float m_velocity;
	Time m_lifetime;
	Clock timelifeclock;

	btRigidBody* m_rigidBody;
	int estado = DISPONIBLE;

	//Entity que dispara la bala
	Character* m_owner;

	float explosion(Character* player, const Vec3<float>& posExplosion, float radio);


};