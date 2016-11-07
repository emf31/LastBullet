#pragma once

#include "Otros\Time.hpp"
#include "Otros/vec3.hpp"
#include "irrlicht.h"
#include <vector>
#include "Entities\Entity.h"
#include "Entities\Player.h"
#include "Motor\Camera.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <cstdlib>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


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


private:
	static const Time timePerFrame;
	float interpolation;

	Player *player;
	

};



