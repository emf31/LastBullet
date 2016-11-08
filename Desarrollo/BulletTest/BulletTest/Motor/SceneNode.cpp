
#include "SceneNode.h"


SceneNode::SceneNode(ISceneNode* node, IVideoDriver* irrDriver) :
	m_node(node),
	m_irrDriver(irrDriver)
{
}


SceneNode::~SceneNode()
{
	delete m_node;
	m_irrDriver = nullptr;
}

void SceneNode::setTexture(const io::path & texture)
{
	m_node->setMaterialTexture(0, m_irrDriver->getTexture(texture));
}


void SceneNode::setPosition(Vec3<float> position)
{
	m_node->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

Vec3<float> SceneNode::getPosition()
{
	vector3df aux = m_node->getPosition();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

void SceneNode::setRotation(Vec3<float> rotation)
{
	m_node->setRotation(vector3df(rotation.getX(), rotation.getY(), rotation.getZ()));
	
}

Vec3<float> SceneNode::getScale()
{
	vector3df aux = m_node->getScale();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

ISceneNode* SceneNode::getNodo() {
	return m_node;
}