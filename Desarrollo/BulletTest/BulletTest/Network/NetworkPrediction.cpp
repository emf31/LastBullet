#include "NetworkPrediction.h"
#include <algorithm>
#include <GUIManager.h>
#include <DebugMenuGUI.h>

NetworkPrediction::NetworkPrediction(Character * character)
{
}

NetworkPrediction::~NetworkPrediction()
{
}

void NetworkPrediction::addMovement(TMovimiento & mov)
{
	//if (m_positions.size() > 0) {
		//m_positions.push(mov);
	//}
		updateMovement(mov);

		/*DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
		menu->addPrintText("LLega Movimiento");*/
}



void NetworkPrediction::updateMovement(TMovimiento & mov)
{
	prevMovement = newMovement;
	newMovement = mov;
}

void NetworkPrediction::interpolate(Time elapsedTime)
{
	Time time = milliseconds(RakNet::GetTimeMS() - newMovement.time);

	interpolation = (float)std::min(1.f, (time.asSeconds())  / elapsedTime.asSeconds());

	/*if (interpolation == 1.f) {
		updateMovement(m_positions.top());

		while (!m_positions.empty()) {
			m_positions.pop();
		}
	}*/

	

	//New Pos
	Vec3<float> m_renderPos = Vec3<float>(
		prevMovement.position.getX() + ((newMovement.position.getX() - prevMovement.position.getX()) * interpolation),
		prevMovement.position.getY() + ((newMovement.position.getY() - prevMovement.position.getY()) * interpolation),
		prevMovement.position.getZ() + ((newMovement.position.getZ() - prevMovement.position.getZ()) * interpolation)
		);

	DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));

	std::string display = "( ";
	display.append(std::to_string(m_renderPos.getX()));
	display.append(" ,");
	display.append(std::to_string(m_renderPos.getY()));
	display.append(" ,");
	display.append(std::to_string(m_renderPos.getZ()));
	display.append(" )");

	menu->addPrintText(std::to_string(time.asSeconds()));
}
