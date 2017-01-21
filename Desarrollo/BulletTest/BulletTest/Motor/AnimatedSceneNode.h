#pragma once
#pragma once
#include "irrlicht.h"
#include <iostream>
#include <string>
#include <vec3.hpp>
#include "SceneNode.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class AnimatedSceneNode : public SceneNode
{
public:
	AnimatedSceneNode(IAnimatedMeshSceneNode* node, IVideoDriver* irrDriver);
	~AnimatedSceneNode();

	virtual void addChild(std::shared_ptr<SceneNode> child) override;
	virtual void removeChild(std::shared_ptr<SceneNode> child) override;
	virtual void setTexture(const io::path & texture, int material) override;
	virtual void setPosition(Vec3<float> position) override;
	virtual void setRotation(Vec3<float> rotation) override;

	virtual Vec3<float> getPosition() override;
	virtual Vec3<float> getScale() override;

	virtual ISceneNode* getNodo() override;
	virtual void setVisible(bool visible) override;
	virtual void setAnimation(int start,int end) override;

	virtual void updateAbsolutePosition() override {
		m_node->updateAbsolutePosition();
	}

private:
	IAnimatedMeshSceneNode* m_node;


	// Heredado vía SceneNode
	

};

