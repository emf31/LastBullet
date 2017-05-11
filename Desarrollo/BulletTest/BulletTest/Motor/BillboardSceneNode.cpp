/*
#include "BillboardSceneNode.h"


BillboardSceneNode::BillboardSceneNode(IBillboardSceneNode* node, IrrlichtDevice * irrDevice) : SceneNode(irrDevice),
m_node(node)
{
}


BillboardSceneNode::~BillboardSceneNode()
{
	m_node = nullptr;

}

void BillboardSceneNode::setTexture(const io::path & texture, int material)
{
	m_node->getMaterial(material).setTexture(0, m_irrDevice->getVideoDriver()->getTexture(texture));
}


void BillboardSceneNode::setPosition(Vec3<float> position)
{
	m_node->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

Vec3<float> BillboardSceneNode::getPosition()
{
	vector3df aux = m_node->getPosition();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

Vec3<float> BillboardSceneNode::getRotation()
{
	vector3df aux = m_node->getRotation();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

void BillboardSceneNode::setRotation(Vec3<float> rotation)
{
	m_node->setRotation(vector3df(rotation.getX(), rotation.getY(), rotation.getZ()));

}

Vec3<float> BillboardSceneNode::getScale()
{
	vector3df aux = m_node->getScale();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

void BillboardSceneNode::addChild(std::shared_ptr<SceneNode> child) {
	m_node->addChild(child->getNodo());
}

void BillboardSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	//child->getNodo()->grab();
	m_node->removeChild(child->getNodo());
}

ISceneNode* BillboardSceneNode::getNodo() {
	return m_node;
}

void BillboardSceneNode::setColor(const Color4f & color)
{
	m_node->setColor(video::SColor(color.a, color.r, color.g, color.b));
}

void BillboardSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}
*/