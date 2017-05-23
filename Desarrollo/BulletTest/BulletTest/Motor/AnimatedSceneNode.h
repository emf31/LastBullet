
#pragma once
#include <Engine/TAnimation.h>
#include <iostream>
#include <string>
#include <vec3.hpp>
#include "SceneNode.h"

class AnimatedSceneNode : public SceneNode
{
public:
	AnimatedSceneNode(TAnimation* node);
	~AnimatedSceneNode();

	virtual void addChild(std::shared_ptr<SceneNode> child) override;
	virtual void removeChild(std::shared_ptr<SceneNode> child) override;
	virtual void setTexture(const std::string& texture, int material) override;
	virtual void setPosition(const Vec3<float>& position) override;
	virtual void setScale(Vec3<float>& scale) override;
	virtual void setRotationXYZ(Vec3<float>& rot) override;

	virtual void setOrientation(Vec3<float>& orientation) override;

	virtual void updatePosition(Vec3<float> pos) override { m_node->updatePosition(pos); }

	virtual Vec3<float> getPosition() override;
	virtual Vec3<float> getRotation() override;
	virtual Vec3<float> getScale() override;
	virtual void setVisible(bool visible) override;

	virtual void setFrameTime(Time time) override;
	virtual void setCurrentAnimation(const std::string& str) override;
	virtual void setAnimation(const std::string& str, int desde, int hasta, bool loop) override;

	//TModel* getNodo();
	virtual void setColor(const Vec3<float> color) override;

	virtual void setCurrentFrame(int frame) override { m_node->setCurrentFrame(frame); }
	virtual int getCurrentFrame() const override { return m_node->getCurrentFrame(); }
	

private:
	TAnimation* m_node;
	virtual TEntity* getEntityNode() override { return m_node; }

};

