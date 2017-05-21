#pragma once

#include <vec3.hpp>
#include "EntActive.h"
#include "EntityManager.h"
#include <Time.hpp>
#include <Clock.hpp>

class GunBullet : public EntActive
{
public:
	GunBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> finalposition, Vec3<float> rotation, Vec3<float> orientation);
	~GunBullet();

	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message & message) override;

	virtual std::string getClassName() override;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void setPosition(const Vec3<float> &pos) override;
	
private:
	Vec3<float> m_direction;
	Vec3<float> m_position;
	Vec3<float> m_rotation;
	Vec3<float> m_orientation;
	float m_velocity;
	Time m_lifetime;
	Clock timelifeclock;

};

