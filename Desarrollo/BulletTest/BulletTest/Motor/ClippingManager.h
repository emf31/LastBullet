#pragma once
#include <ClippingZone.h>

class ClippingManager
{
public:

	static ClippingManager& i() {
		static ClippingManager singleton;
		return singleton;
	}

	void addClippingZone(ClippingZone* zone);
	ClippingZone* createClippingZone(Vec3<float> pos, Vec3<float> size,std::string name);
	void update();
	void printZonesVisibility();
	bool canUpdate;

private:
	ClippingManager();
	std::vector<ClippingZone*> m_clippingZones;

};