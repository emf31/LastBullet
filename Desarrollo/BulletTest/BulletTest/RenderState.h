#pragma once
#include "Otros\vec3.hpp"
#include "Otros\Time.hpp"
#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



class RenderState
{
public:
	RenderState();
	~RenderState();
	void setPosition(Vec3<float> position);
	void setVelocity(Vec3<float> velocity);
	Vec3<float> getPosition();
	Vec3<float> getVelocity();
	void update(Time elapsedTime);
	void updateRender(float interpolation, ISceneNode *m_nodo);

	Vec3<float> renderPos;

private:
	Vec3<float> posPrev;
	Vec3<float> posNew;
	Vec3<float> Velocity;
	
};

