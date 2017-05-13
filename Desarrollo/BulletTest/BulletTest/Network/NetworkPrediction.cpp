#include "NetworkPrediction.h"
#include <algorithm>
#include <GUIManager.h>
#include <DebugMenuGUI.h>
#include <Enemy.h>

NetworkPrediction::NetworkPrediction(Enemy * character)
{
	m_character = character;
}

NetworkPrediction::~NetworkPrediction()
{
}

void NetworkPrediction::addMovement(TMovimiento & mov)
{
		updateMovement(mov);
}



void NetworkPrediction::updateMovement(TMovimiento & mov)
{
	//Tiempo en el que recibimos paquete
	startTime = milliseconds(RakNet::GetTimeMS());


	prevPosition = newPosition;
	newPosition = mov.position;

	//Calcular target time y target position
	Vec3<float> delta = (newPosition - prevPosition);
	Time deltaTime = milliseconds(RakNet::GetTimeMS()) - milliseconds(mov.timeStamp);
	targetPosition = newPosition + (delta * deltaTime.asSeconds());-
	
	//TargetTime = tiempo actual + tiempo en recibir pauete
	targetTime = milliseconds(RakNet::GetTimeMS()) + (milliseconds(RakNet::GetTimeMS()) - milliseconds(mov.timeStamp));

	if (!compareVec3(targetPosition, newPosition)) {
		int a = 0;
	}


}


bool NetworkPrediction::compareVec3(const Vec3<float>& lhs, const Vec3<float>& rhs) {
	return (lhs.getX() == rhs.getX())
		&& (lhs.getY() == rhs.getY())
		&& (lhs.getZ() == rhs.getZ());
}

void NetworkPrediction::interpolateWithPrediction()
{
	if (compareVec3(targetPosition, newPosition)) {
		Enemy* ene = static_cast<Enemy*>(m_character);
		ene->setPosition(targetPosition);

		return;
	}
	//No hacemos nada
	if (targetTime == startTime)
	{
		return;
	}

	currentTime = milliseconds(RakNet::GetTimeMS());

	float interpolation = (float)(currentTime.asSeconds() - startTime.asSeconds()) / (float)(targetTime.asSeconds() - startTime.asSeconds());

	if (interpolation >= 1.0f)
	{
		m_character->setPosition(targetPosition);
	}
	else if (interpolation < 0)
	{
		m_character->setPosition(targetPosition);
	}
	else {
		Vec3<float> finalPos = Vec3<float>(
			newPosition.getX() + ((targetPosition.getX() - newPosition.getX()) * interpolation),
			newPosition.getY() + ((targetPosition.getY() - newPosition.getY()) * interpolation),
			newPosition.getZ() + ((targetPosition.getZ() - newPosition.getZ()) * interpolation)
			);

		m_character->updateEnemigo(finalPos);
	}
}

void NetworkPrediction::interpolateWithoutPrediction()
{
	m_character->updateEnemigo(newPosition);
}
