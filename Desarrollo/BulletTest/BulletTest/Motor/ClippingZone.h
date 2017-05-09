#pragma once
#include <GraphicEngine.h>
#include <vec3.hpp>
#include <vector>

class ClippingZone {
public:
	ClippingZone(Vec3<float> center, Vec3<float> size, std::string name);
	~ClippingZone() {};
	void addEntity(Entity* ent);
	std::vector<Vec3<float>> getPoints();
	void setVisible(bool visible);
	bool getVisible() { return m_visible; };
	bool isPlayerinside();
	std::string m_name;

private:
	std::vector<Entity*> m_entities;
	std::vector<Vec3<float>> m_points;
	bool m_visible;
	void putAllEntitiesInVisible(bool visible);
	
};