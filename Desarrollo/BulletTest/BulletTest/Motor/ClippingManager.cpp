#include "ClippingManager.h"

void ClippingManager::addClippingZone(ClippingZone * zone)
{
	m_clippingZones.push_back(zone);
}

ClippingZone* ClippingManager::createClippingZone(Vec3<float> pos, Vec3<float> size, std::string name)
{
	ClippingZone* zona = new ClippingZone(pos,size,name);
	m_clippingZones.push_back(zona);
	return zona;
}

void ClippingManager::update()
{
	if (canUpdate) {

		//Updateamos los planos del frustrum y nos lo guardamos en variable para analizarla despues

		GraphicEngine::i().updateClippingPlanes();
		std::vector<std::vector<float>> planos;
		for (int i = 0; i < 6; i++) {
				std::vector<float> plane = { GraphicEngine::i().planes[i][0], GraphicEngine::i().planes[i][1], GraphicEngine::i().planes[i][2], GraphicEngine::i().planes[i][3] };
				planos.push_back(plane);
		}


		bool isVisible;
		bool pointVisible;

		for (std::vector<ClippingZone*>::iterator it = m_clippingZones.begin(); it != m_clippingZones.end(); ++it) {
			if (!(*it)->isPlayerinside()) {
				std::vector<Vec3<float>> points = (*it)->getPoints();
				isVisible = false;
				for (std::vector<Vec3<float>>::iterator it2 = points.begin(); it2 != points.end(); ++it2) {
					pointVisible = true;
					for (int i = 0; i < 6; i++) {
						if (it2->getX()*planos.at(i)[0] + it2->getY()*planos.at(i)[1] + it2->getZ()*planos.at(i)[2] + planos.at(i)[3] < 0) {
							pointVisible = false;
						}
					}
					if (pointVisible) {
						isVisible = true;
						break;
					}
				}
				(*it)->setVisible(isVisible);
			}
		}
	}
}

void ClippingManager::printZonesVisibility()
{
	std::cout << "---------------------------------------------------"<< std::endl;
	for (std::vector<ClippingZone*>::iterator it = m_clippingZones.begin(); it != m_clippingZones.end(); ++it) {
		std::cout << (*it)->m_name << "        " << (*it)->getVisible() << std::endl;
	}
	std::cout << "---------------------------------------------------" << std::endl;
}

ClippingManager::ClippingManager():canUpdate(false)
{
}
