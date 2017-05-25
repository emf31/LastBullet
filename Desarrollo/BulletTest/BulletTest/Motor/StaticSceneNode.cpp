
#include "StaticSceneNode.h"
#include <GraphicEngine.h>
#include <Util.h>
StaticSceneNode::StaticSceneNode(TModelEstatico* node) :
	m_node(node)
{
}


StaticSceneNode::~StaticSceneNode()
{
	//m_node->removeNode();
	//m_node = nullptr;

	//m_node->removeNode();
	//delete m_node;
}




Vec3<float> StaticSceneNode::getPosition()
{
	return m_node->getPosition();
}

Vec3<float> StaticSceneNode::getRotation()
{
	return m_node->getRotation();
}

Vec3<float> StaticSceneNode::getScale()
{
	return m_node->getScale();
}

void StaticSceneNode::addChild(std::shared_ptr<SceneNode> child) {
	//m_node->addChild(child->getEntityNode());
}

void StaticSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	m_node->removeChild(child->getEntityNode());
}


void StaticSceneNode::setColor(const Vec3<float> color)

{
	m_node->setModelColor(color.getX(), color.getY(), color.getZ());
}

void StaticSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}
