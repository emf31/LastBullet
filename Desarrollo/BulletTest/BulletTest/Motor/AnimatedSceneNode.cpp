
#include "AnimatedSceneNode.h"


AnimatedSceneNode::AnimatedSceneNode(IAnimatedMeshSceneNode* node, IVideoDriver* irrDriver) : SceneNode(irrDriver),
	m_node(node)
{
}


AnimatedSceneNode::~AnimatedSceneNode()
{
	m_node = nullptr;
	m_irrDriver = nullptr;
}

void AnimatedSceneNode::setTexture(const io::path & texture, int material)
{
	m_node->getMaterial(material).setTexture(0, m_irrDriver->getTexture(texture));
}


void AnimatedSceneNode::setPosition(Vec3<float> position)
{
	m_node->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}



Vec3<float> AnimatedSceneNode::getPosition()
{
	vector3df aux = m_node->getPosition();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

void AnimatedSceneNode::setRotation(Vec3<float> rotation)
{
	m_node->setRotation(vector3df(rotation.getX(), rotation.getY(), rotation.getZ()));


}

Vec3<float> AnimatedSceneNode::getScale()
{
	vector3df aux = m_node->getScale();
	return Vec3<float>(aux.X, aux.Y, aux.Z);
}

ISceneNode* AnimatedSceneNode::getNodo() {
	return m_node;
}

void AnimatedSceneNode::addChild(std::shared_ptr<SceneNode> child) {
	m_node->addChild(child->getNodo());
}

void AnimatedSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	//child->getNodo()->grab();
	m_node->removeChild(child->getNodo());
}


void AnimatedSceneNode::setAnimation(int start, int end)
{
	m_node->setMD2Animation(scene::EMAT_STAND);
	m_node->setFrameLoop(start, end);
}

void AnimatedSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}
