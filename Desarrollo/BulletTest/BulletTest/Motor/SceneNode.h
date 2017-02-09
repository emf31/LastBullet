#pragma once
#include "irrlicht.h"
#include <iostream>
#include <string>
#include <vec3.hpp>
#include "SceneNode.h"
#include <memory>
#include <Color4f.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class SceneNode
{
public:
	SceneNode(IrrlichtDevice * irrDevice);
	~SceneNode();

	virtual void setVisible(bool visible) = 0;
	virtual void addChild(std::shared_ptr<SceneNode> child) = 0;
	virtual void removeChild(std::shared_ptr<SceneNode> child) = 0;
	virtual void setTexture(const io::path& texture, int material) = 0;
	virtual void setPosition(Vec3<float> position) = 0;
	virtual void setRotation(Vec3<float> rotation) = 0;
	virtual Vec3<float> getPosition() = 0;
	virtual Vec3<float> getScale() = 0;

	virtual ISceneNode* getNodo() = 0;
	virtual void setAnimation(int start, int end)=0;
	virtual void setColor(const Color4f& color) = 0;

protected:
	IrrlichtDevice* m_irrDevice;

	
};

