#pragma once

#include <TModel.h>

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
	virtual void setRotation(const Vec3<float>& rotation) override;

	virtual Vec3<float> getPosition() override;
	virtual Vec3<float> getRotation() override;
	virtual Vec3<float> getScale() override;
	virtual void setVisible(bool visible) override;
	//TModel* getNodo();
	virtual void setColor(const Color4f& color) override;
	
private:
	TModel* m_node;

	virtual TEntity* getEntityNode() override  { return m_node; }
	
};

