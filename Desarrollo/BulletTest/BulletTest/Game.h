#pragma once

#include "Otros\Time.hpp"
#include "Otros/vec3.hpp"
#include "irrlicht.h"
#include <vector>
#include "Entities\Entity.h"
#include "Entities\Player.h"
#include "Entities\Enemy.h"
#include "Entities\Granada.h"
#include "Motor\Camera.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <cstdlib>

#include <InGameHUD.h>
#include <DebugMenuGUI.h>
#include <Partida.h>

#include <Enemy_Bot.h>

#include <World.h>

class Game
{
public:
	Game();
	virtual ~Game();

	void run();
	void inicializar();
	bool processEvents(); // Captura y procesa eventos
	void update(Time elapsedTime);
	void render(float interpolation, Time elapsedTime);
	
	static const int server_port;
	static const Time timePerFrame;

private:
	InGameHUD ingameGUI;
	DebugMenuGUI debugMenu;
	float interpolation;

	//Partida partida;
	Player* player;

	Enemy_Bot *e;
	Enemy_Bot *e2;

	World world;
};