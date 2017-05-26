#pragma once

#include <iostream>
#include <string>
#include <vec3.hpp>
#include "SceneNode.h"
#include <memory>
#include <Color4f.h>
#include <Engine/TEntity.h>

#include <Time.hpp>

class SceneNode
{
	friend class BasicSceneNode;
	friend class Camera;
	friend class GraphicEngine;
	friend class ClippingZone;
public:
	SceneNode();
	~SceneNode();

	virtual void setVisible(bool visible) = 0;
	virtual void addChild(std::shared_ptr<SceneNode> child) = 0;
	virtual void removeChild(std::shared_ptr<SceneNode> child) = 0;
	//virtual void remove() = 0;
	virtual void setTexture(const std::string& texture, int material) = 0;
	virtual void setPosition(const Vec3<float>& position) = 0;
	virtual void setOrientation(Vec3<float>& orientation) = 0;
	virtual void setScale(Vec3<float>& scale) = 0;
	virtual void setRotationXYZ(Vec3<float>& rot) = 0;
	virtual void updatePosition(Vec3<float> pos) = 0;

	virtual Vec3<float> getPosition() = 0;
	virtual Vec3<float> getRotation() = 0;
	virtual Vec3<float> getScale() = 0;

	virtual void setFrameTime(Time time) = 0;
	virtual void setCurrentAnimation(const std::string& str) = 0;
	virtual void setAnimation(const std::string& str, int desde, int hasta, bool loop) = 0;
	virtual void setCurrentFrame(int frame) = 0;
	virtual int getCurrentFrame() const = 0;

	virtual bool isVisible() { return true; }

	virtual void setTransformationMatriz(Vec3<float> position, Vec3<float> rotation, Vec3<float> scale) { }
	
	virtual void setColor(const Vec3<float> color) = 0;
	virtual TEntity* getEntityNode() = 0;

private:
	

	
};

