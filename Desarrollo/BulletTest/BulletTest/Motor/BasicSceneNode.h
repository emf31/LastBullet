#pragma once

#include <Engine/TModel.h>

#include <SceneNode.h>


class BasicSceneNode : public SceneNode
{
public:
	BasicSceneNode(TModel* node);
	~BasicSceneNode();

	virtual void addChild(std::shared_ptr<SceneNode> child) override;
	virtual void removeChild(std::shared_ptr<SceneNode> child) override;
	virtual void setTexture(const std::string& texture, int material) override;
	virtual void setPosition(const Vec3<float>& position) override;
	virtual void setRotation(Vec3<float>& rotation) override;
	virtual void setScale(Vec3<float>& scale) override;
	virtual void setRotationXYZ(Vec3<float>& rot) override;
	virtual void setRotationRightHand(Vec3<float>& rot) override;

	virtual void setOrientation(Vec3<float>& orientation) override;

	virtual void updatePosition(Vec3<float> pos) override { m_node->updatePosition(pos); }

	virtual Vec3<float> getPosition() override;
	virtual Vec3<float> getRotation() override;
	virtual Vec3<float> getScale() override;
	virtual void setVisible(bool visible) override;
	//TModel* getNodo();
	virtual void setColor(const Vec3<float> color) override;
	
private:

	TModel* m_node;

	virtual TEntity* getEntityNode() override  { return m_node; }
	
};

