
#include "BasicSceneNode.h"


BasicSceneNode::BasicSceneNode(ISceneNode* node, IVideoDriver* irrDriver) : SceneNode(irrDriver),
	m_node(node)
{
}


BasicSceneNode::~BasicSceneNode()
{
	m_node = nullptr;

}

void BasicSceneNode::setTexture(const io::path & texture, int material)
{
	m_node->getMaterial(material).setTexture(0, m_irrDriver->getTexture(texture));
}


void BasicSceneNode::setPosition(Vec3<float> position)
{
	m_node->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

Vec3<float> BasicSceneNode::getPosition()
{
	vector3df aux = m_node->getPosition();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

void BasicSceneNode::setRotation(Vec3<float> rotation)
{
	m_node->setRotation(vector3df(rotation.getX(), rotation.getY(), rotation.getZ()));
	
}

Vec3<float> BasicSceneNode::getScale()
{
	vector3df aux = m_node->getScale();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

ISceneNode* BasicSceneNode::getNodo() {
	return m_node;
}