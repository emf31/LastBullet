#pragma once
#include "irrlicht.h"
#include "../Otros/vec3.hpp"
#include "../Otros/Timer.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Entity
{
public:
	Entity(ISceneNode *node);
	virtual ~Entity();

	void update(float elapsedTime);

	Vec3<float> m_posicion;
	Vec3<float> m_velocidad;

	bool isMovingBackward;
	bool isMovingForward;
	bool isMovingLeft;
	bool isMovingRight;
private:
	

	ISceneNode *m_nodo;
};

