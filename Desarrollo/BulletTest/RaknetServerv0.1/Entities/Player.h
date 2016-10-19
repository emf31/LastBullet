#pragma once

#include "../BulletTest/BulletTest/Otros/Time.hpp"
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

private:

	float m_speedFactor;
	Clock tiempoSalto;

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
};

