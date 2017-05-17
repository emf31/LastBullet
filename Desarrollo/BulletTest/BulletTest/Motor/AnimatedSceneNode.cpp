#include "AnimatedSceneNode.h"
#include <GraphicEngine.h>

AnimatedSceneNode::AnimatedSceneNode(TAnimation * node) :
	m_node(node)
{
}

AnimatedSceneNode::~AnimatedSceneNode()
{
}

void AnimatedSceneNode::addChild(std::shared_ptr<SceneNode> child)
{
}

void AnimatedSceneNode::removeChild(std::shared_ptr<SceneNode> child)
{
	//m_node->removeChild(child->getEntityNode());
}

void AnimatedSceneNode::setTexture(const std::string & texture, int material)
{
}

void AnimatedSceneNode::setPosition(const Vec3<float>& position)
{
	m_node->setPosition(Vec3<float>(position.getX(), position.getY(), position.getZ()));
}

void AnimatedSceneNode::setScale(Vec3<float>& scale)
{
	m_node->setScale(scale);
}

void AnimatedSceneNode::setRotationXYZ(Vec3<float>& rot)
{
	m_node->setRotationXYZ(rot);
}

void AnimatedSceneNode::setOrientation(Vec3<float>& orientation)
{
	//m_node->setOrientation(orientation);

	glm::mat4 m_matrix = glm::mat4();
	glm::vec3 column1;
	glm::vec3 column2;
	glm::vec3 column3;
	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::vec3 direction = glm::vec3(orientation.getX(), orientation.getY(), orientation.getZ());

	glm::vec3 xaxis = glm::cross(up, direction);
	xaxis = glm::normalize(xaxis);

	glm::vec3 yaxis = glm::cross(direction, xaxis);

	yaxis = glm::normalize(yaxis);

	column1.x = xaxis.x;
	column1.y = yaxis.x;
	column1.z = direction.x;

	column2.x = xaxis.y;
	column2.y = yaxis.y;
	column2.z = direction.y;

	column3.x = xaxis.z;
	column3.y = yaxis.z;
	column3.z = direction.z;

	m_matrix[0][0] = column1.x;
	m_matrix[1][0] = column1.y;
	m_matrix[2][0] = column1.z;

	m_matrix[0][1] = column2.x;
	m_matrix[1][1] = column2.y;
	m_matrix[2][1] = column2.z;

	m_matrix[0][2] = column3.x;
	m_matrix[1][2] = column3.y;
	m_matrix[2][2] = column3.z;

	//m_node->setRotationMatrix(m_matrix);
}

Vec3<float> AnimatedSceneNode::getPosition()
{
	return m_node->getPosition();
}

Vec3<float> AnimatedSceneNode::getRotation()
{
	return m_node->getRotation();
}

Vec3<float> AnimatedSceneNode::getScale()
{
	return m_node->getScale();
}

void AnimatedSceneNode::setVisible(bool visible)
{
	m_node->setVisible(visible);
}

void AnimatedSceneNode::setFrameTime(Time time)
{
	m_node->setFrameTime(time);
}

void AnimatedSceneNode::setCurrentAnimation(const std::string & str)
{
	m_node->setCurrentAnimation(str);
}

void AnimatedSceneNode::setAnimation(const std::string & str, int desde, int hasta, bool loop)
{
	m_node->setAnimation(str, desde, hasta, loop);
}

void AnimatedSceneNode::setColor(const Vec3<float> color)
{
}
