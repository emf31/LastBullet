#include "ClippingZone.h"
#include <EntityManager.h>
#include <Player.h>

ClippingZone::ClippingZone(Vec3<float> center, Vec3<float> size,std::string name, int id) : m_name(name), id(id)
{
	Vec3<float> point1 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY() - (size.getY() / 2), center.getZ() - (size.getZ() / 2));
	Vec3<float> point2 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY() - (size.getY() / 2), center.getZ() + (size.getZ() / 2));
	Vec3<float> point3 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY() + (size.getY() / 2), center.getZ() - (size.getZ() / 2));
	Vec3<float> point4 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY() + (size.getY() / 2), center.getZ() + (size.getZ() / 2));
	Vec3<float> point5 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY() - (size.getY() / 2), center.getZ() - (size.getZ() / 2));
	Vec3<float> point6 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY() - (size.getY() / 2), center.getZ() + (size.getZ() / 2));
	Vec3<float> point7 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY() + (size.getY() / 2), center.getZ() - (size.getZ() / 2));
	Vec3<float> point8 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY() + (size.getY() / 2), center.getZ() + (size.getZ() / 2));


	Vec3<float> point9 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY(), center.getZ() - (size.getZ() / 2));
	Vec3<float> point10 = Vec3<float>(center.getX() - (size.getX() / 2), center.getY(), center.getZ() + (size.getZ() / 2));
	Vec3<float> point11 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY(), center.getZ() - (size.getZ() / 2));
	Vec3<float> point12 = Vec3<float>(center.getX() + (size.getX() / 2), center.getY(), center.getZ() + (size.getZ() / 2));
	Vec3<float> point13 = Vec3<float>(center.getX(), center.getY(), center.getZ());



	m_points.push_back(point1);
	m_points.push_back(point2);
	m_points.push_back(point3);
	m_points.push_back(point4);
	m_points.push_back(point5);
	m_points.push_back(point6);
	m_points.push_back(point7);
	m_points.push_back(point8);
	m_points.push_back(point9);
	m_points.push_back(point10);
	m_points.push_back(point11);
	m_points.push_back(point12);
	m_points.push_back(point13);

	nodo = new TNode(-1, SceneManager::i().getRootNode());
	SceneManager::i().getRootNode()->addChild(nodo);
	//nodo->setVisible(false);
}

void ClippingZone::addEntity(Entity * ent)
{
	nodo->addChild(ent->getNode()->getEntityNode());
}

std::vector<Vec3<float>> ClippingZone::getPoints()
{
	return m_points;
}

void ClippingZone::setVisible(bool visible)
{
	if (visible != m_visible) {
		m_visible = visible;
		nodo->setVisible(m_visible);
	}
}

bool ClippingZone::isPlayerinside()
{
	Vec3<float> playerPos = static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getRenderState()->getPosition();
	if (playerPos.getX() > m_points.at(0).getX() && playerPos.getY() > m_points.at(0).getY() && playerPos.getZ() > m_points.at(0).getZ()) {
		if (playerPos.getX() < m_points.at(7).getX() && playerPos.getY()  < m_points.at(7).getY() && playerPos.getZ() < m_points.at(7).getZ()) {
			setVisible(true);
			return true;
		}
	}
	return false;
}

void ClippingZone::putAllEntitiesInVisible(bool visible)
{
	//for (std::vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it) {
	//	(*it)->getNode()->setVisible(visible);
	//}
}
