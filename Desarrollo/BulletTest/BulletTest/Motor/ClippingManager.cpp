#include "ClippingManager.h"
#include <Clock.hpp>
#include <GUIManager.h>
#include <DebugMenuGUI.h>

void ClippingManager::addClippingZone(ClippingZone * zone)
{
	m_clippingZones.push_back(zone);
}

ClippingZone* ClippingManager::createClippingZone(Vec3<float> pos, Vec3<float> size, std::string name)
{
	ClippingZone* zona = new ClippingZone(pos,size,name,m_clippingZones.size());
	m_clippingZones.push_back(zona);
	return zona;
}

void ClippingManager::update()
{
	std::vector<ClippingZone*> lastZones;
	
	if (updateOclusions) {
		//Oclusiones, elimina del clipping aquellas zonas que por definicion no se pueden ver desde esa zona
		for (std::size_t i = 0; i < m_clippingZones.size(); i++) {
			if (m_clippingZones.at(i)->isPlayerinside()) {
				updateZoneOclusions(int(i), lastZones);
				break;
			}
		}
	}
	else {
		lastZones = m_clippingZones;
	}


	if (updateClipping) {
		//Updateamos los planos del frustrum y nos lo guardamos en variable para analizarla despues
		GraphicEngine::i().updateClippingPlanes();
		std::vector<std::vector<float>> planos;
		for (int i = 0; i < 6; i++) {
			std::vector<float> plane = { GraphicEngine::i().planes[i][0], GraphicEngine::i().planes[i][1], GraphicEngine::i().planes[i][2], GraphicEngine::i().planes[i][3] };
			planos.push_back(plane);
		}

		
		//Con last zones que son aquellas que se pueden ver desde esa zona se hace el clipping recorre todas las zonas y ver si tienes alguna esquina a la vista
		bool isVisible;
		bool pointVisible;

		if (!lastZones.empty()) {
			for (std::vector<ClippingZone*>::iterator it = lastZones.begin(); it != lastZones.end(); ++it) {
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

}

void ClippingManager::printZonesVisibility()
{
	std::cout << "---------------------------------------------------"<< std::endl;

	for (std::vector<ClippingZone*>::iterator it = m_clippingZones.begin(); it != m_clippingZones.end(); ++it) {
		std::cout << (*it)->m_name << "        " << (*it)->getVisible() << std::endl;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Mi zona es: " << mizona<<std::endl;
}

void ClippingManager::updateZoneOclusions(int id, std::vector<ClippingZone*> &zonesOclusionOut)
{
	for (int i = 0; i < 10; i++) {
		if (oclusionMatrix[id][i] == true) {
			if(id!=i)
				zonesOclusionOut.push_back(m_clippingZones.at(i));
			m_clippingZones.at(i)->setVisible(true);
		}
		else {
			m_clippingZones.at(i)->setVisible(false);
		}
	}
	;
	DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
}

bool ClippingManager::getUpdateClipping() const
{
	return updateClipping;
}

bool ClippingManager::getUpdateOclusions() const
{
	return updateOclusions;
}

void ClippingManager::setUpdateClipping(bool a)
{
	updateClipping = a;
}

void ClippingManager::setUpdateOclusions(bool a)
{
	updateOclusions = a;
}

ClippingManager::ClippingManager():updateClipping(false), updateOclusions(false)
{
	//oclusionMatrix = 
	//oclusionMatrix = p_oclusionMatrix;
	
}
