#pragma once

#include "Otros\Time.hpp"
#include "Otros/vec3.hpp"
#include "irrlicht.h"
#include <vector>
#include "Entities\Entity.h"
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

	void inicializarIrrlitch();
	void processEvents(); // Captura y procesa eventos
	void update(Time elapsedTime);
	void render(float interpolation, Time elapsedTime);

	ISceneNode* CreateBox(const Vec3<double> &TPosition, const Vec3<float> &TScale, float TMass);

	IrrlichtDevice *irrDevice;
	IVideoDriver *irrDriver;
	ISceneManager *irrScene;
	IGUIEnvironment *irrGUI;

	btDiscreteDynamicsWorld *World;
	list<btRigidBody *> Objects;

private:
	static const Time timePerFrame;
	float interpolation;

	std::vector<Entity*> entities;
	
	ICameraSceneNode *Camera;
};



