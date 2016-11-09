#pragma once
#include "irrlicht.h"
#include <iostream>
#include <string>
#include "../Otros/vec3.hpp"
#include "SceneNode.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class BasicSceneNode : public SceneNode
{
public:
	BasicSceneNode(ISceneNode* node, IVideoDriver* irrDriver);
	~BasicSceneNode();

	virtual void setTexture(const io::path& texture) override;
	virtual void setPosition(Vec3<float> position) override;
	virtual void setRotation(Vec3<float> rotation) override;

	virtual Vec3<float> getPosition() override;
	virtual Vec3<float> getScale() override;

	virtual ISceneNode* getNodo() override;

private:
	ISceneNode* m_node;
};

