#pragma once
#include <RakPeerInterface.h>
#include "Clock.hpp"

//Fordward declaration para evitar referencia circular
class Player;

class LifeComponent {
public:
	LifeComponent(Player* player);
	~LifeComponent();

	void restaVida(float cantidad, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	bool update();

	void resetVida();
	float getVida();

	void sumarVida();

	bool isDying();

private:
	float m_vida;
	bool m_isDying;
	Clock relojMuerte;

	Player* m_player;
};