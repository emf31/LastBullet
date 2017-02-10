#pragma once
#include <RakPeerInterface.h>
#include "Clock.hpp"
#include <Entity.h>

class LifeComponent {
public:
	LifeComponent(Entity* owner);
	~LifeComponent();

	void restaVida(float cantidad, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	void update();

	void resetVida();
	float getVida();

	void sumarVida();

	bool isDying();

private:
	float m_vida;
	bool m_isDying;
	Clock relojMuerte;

	Entity* m_pOwner;
};