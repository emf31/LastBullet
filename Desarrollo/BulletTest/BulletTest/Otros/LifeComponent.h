#pragma once
#include <RakPeerInterface.h>
#include "Clock.hpp"


class Character;

class LifeComponent {
public:
	LifeComponent(Character* owner);
	~LifeComponent();

	void restaVida(float cantidad, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	void update();

	void resetVida();
	float getVida();

	void sumarVida();

	bool isDying();

	void setIsDying(bool a) { m_isDying = a; }

private:
	float m_vida;
	bool m_isDying;
	Clock relojMuerte;

	Character* m_pOwner;
};