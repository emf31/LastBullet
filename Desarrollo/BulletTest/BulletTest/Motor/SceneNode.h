#pragma once

#include <iostream>
#include <string>
#include <vec3.hpp>
#include "SceneNode.h"
#include <memory>
#include <Color4f.h>
#include <TEntity.h>


class SceneNode
{
	friend class BasicSceneNode;
	friend class Camera;
public:
	SceneNode();
	~SceneNode();

	virtual void setVisible(bool visible) = 0;
	virtual void addChild(std::shared_ptr<SceneNode> child) = 0;
	virtual void removeChild(std::shared_ptr<SceneNode> child) = 0;
	//virtual void remove() = 0;
	virtual void setTexture(const std::string& texture, int material) = 0;
	virtual void setPosition(const Vec3<float>& position) = 0;
	virtual void setRotation(const Vec3<float>& rotation) = 0;
	virtual Vec3<float> getPosition() = 0;
	virtual Vec3<float> getRotation() = 0;
	virtual Vec3<float> getScale() = 0;


	
	virtual void setColor(const Color4f& color) = 0;

private:
	virtual TEntity* getEntityNode() = 0;

	
};

