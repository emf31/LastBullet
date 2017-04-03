
#include "BasicSceneNode.h"
#include <GraphicEngine.h>
#include <Util.h>
BasicSceneNode::BasicSceneNode(TModel* node) : 
	m_node(node)
{
}


BasicSceneNode::~BasicSceneNode()
{
	//m_node->removeNode();
	//m_node = nullptr;

	//m_node->removeNode();
	//delete m_node;
}

void BasicSceneNode::setTexture(const std::string & texture, int material)
{
	//m_node->getMaterial(material).setTexture(0, m_irrDevice->getVideoDriver()->getTexture(texture));
}


void BasicSceneNode::setPosition(const Vec3<float>& position)
{
	m_node->setPosition(Vec3<float>(position.getX(), position.getY(), position.getZ()));
}

Vec3<float> BasicSceneNode::getPosition()
{
	return m_node->getPosition();
}

Vec3<float> BasicSceneNode::getRotation()
{
	return m_node->getRotation();
}

void BasicSceneNode::setRotation(Vec3<float>& rotation)
{
	m_node->setRotationLeftHand(rotation);
	//rotation.display();
	/*rotation.normalise();
	m_node->setOrientation(rotation);*/
}

void BasicSceneNode::setScale(Vec3<float>& scale)
{
	m_node->setScale(scale);
}

void BasicSceneNode::setRotationXYZ(Vec3<float>& rot)
{
	m_node->setRotationXYZ(rot);
}

void BasicSceneNode::setRotationRightHand(Vec3<float>& rot)
{
	m_node->setRotation(rot);
}

void BasicSceneNode::setOrientation(Vec3<float>& orientation)
{
	m_node->setOrientation(orientation);
}

Vec3<float> BasicSceneNode::getScale()
{
	return m_node->getScale();
}

void BasicSceneNode::addChild(std::shared_ptr<SceneNode> child) {
	//m_node->addChild(child->getEntityNode());
}

void BasicSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	m_node->removeChild(child->getEntityNode());
}


void BasicSceneNode::setColor(const Vec3<float> color)

{
	m_node->setModelColor(color.getX(), color.getY(), color.getZ());
}

void BasicSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}
