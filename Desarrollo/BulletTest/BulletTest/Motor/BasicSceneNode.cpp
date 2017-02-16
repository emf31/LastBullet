
#include "BasicSceneNode.h"


BasicSceneNode::BasicSceneNode(IMeshSceneNode* node, IrrlichtDevice * irrDevice) : SceneNode(irrDevice),
	m_node(node)
{
}


BasicSceneNode::~BasicSceneNode()
{
	m_node = nullptr;

}

void BasicSceneNode::setTexture(const io::path & texture, int material)
{
	m_node->getMaterial(material).setTexture(0, m_irrDevice->getVideoDriver()->getTexture(texture));
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

Vec3<float> BasicSceneNode::getRotation()
{
	vector3df aux = m_node->getRotation();
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

void BasicSceneNode::addChild(std::shared_ptr<SceneNode> child) {
	m_node->addChild(child->getNodo());
}

void BasicSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	//child->getNodo()->grab();
	m_node->removeChild(child->getNodo());
}

ISceneNode* BasicSceneNode::getNodo() {
	return m_node;
}

void BasicSceneNode::setColor(const Color4f & color)
{
	IMesh* mesh = m_node->getMesh();
	m_irrDevice->getSceneManager()->getMeshManipulator()->setVertexColors(mesh, video::SColor(color.a, color.r, color.g, color.b));
}

void BasicSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}
