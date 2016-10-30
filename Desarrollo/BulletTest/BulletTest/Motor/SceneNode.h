#pragma once
#include "irrlicht.h"
#include <iostream>
#include <string>
#include "../Otros/vec3.hpp"



using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class SceneNode
{
public:
	SceneNode(ISceneNode* node, IVideoDriver* irrDriver);
	~SceneNode();

	void setTexture(const io::path& texture);
	void setPosition(Vec3<float> position);
	Vec3<float> getPosition();
	void setRotation(Vec3<float> rotation);

	Vec3<float> getScale();

private:
	ISceneNode* m_node;
	IVideoDriver* m_irrDriver;
	ISceneManager *m_irrScene;
};

