#include "NetworkPrediction.h"
#include <algorithm>
#include <GUIManager.h>
#include <DebugMenuGUI.h>
#include <Enemy.h>
#include <Util.h>

NetworkPrediction::NetworkPrediction(Enemy * character) :
	interpolation(0.f)
{
	m_character = character;
}

NetworkPrediction::~NetworkPrediction()
{
}

void NetworkPrediction::addMovement(TMovimiento & mov)
{
		updateMovement(mov);
		updateState(mov);
}


//A este metodo se llama cada vez que se recibe un mensaje de movimiento del cliente que representa este enemigo.
void NetworkPrediction::updateMovement(TMovimiento & mov)
{
	//Tiempo en el que recibimos paquete
	startTime = milliseconds(RakNet::GetTimeMS());

	//Calculamos delta time (tiempo que pasa entre 2 movimientos)
	Time deltaTime = milliseconds(mov.timeStamp - prevTime);

	prevTime = mov.timeStamp;

	prevPosition = newPosition;
	newPosition = mov.position;

	//Deberiamos corregir la posicion predecida???
	if (!compareVec3(newPosition, targetPosition)) {
		//m_character->updateEnemigo(newPosition);
	}

	//Calcular target time y target position
	Vec3<float> delta = (newPosition - prevPosition);
	
	targetPosition = newPosition + (delta * deltaTime.asSeconds());
	
	//TargetTime = tiempo actual + tiempo en moverse de posPrev a PosNew
	targetTime = milliseconds(RakNet::GetTimeMS()) + deltaTime;


}

void NetworkPrediction::updateState(TMovimiento & mov)
{
	newRotation = mov.rotation;
	m_character->setIsDying(mov.isDying);
	m_character->setOnGround(mov.isOnGround);
	m_character->setCurrentWeapon(mov.currentWeapon);
	m_character->setIsMoving(mov.isMoving);
}

void NetworkPrediction::interpolate()
{
	//No hacemos nada 0/0 error
	if (targetTime == startTime)
	{
		return;
	}

	currentTime = milliseconds(RakNet::GetTimeMS());

	float interpolation = (float)(currentTime.asSeconds() - startTime.asSeconds()) / (float)(targetTime.asSeconds() - startTime.asSeconds());

	if (interpolation >= 1.0f)
	{
		m_character->updateEnemigo(targetPosition);

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




void NetworkPrediction::interpolateWithPrediction()
{
	//Updateamos Rotacion
	m_character->getRenderState()->updateRotations(newRotation);

	//No hacemos nada
	if (compareVec3(targetPosition, newPosition)) {
		Enemy* ene = static_cast<Enemy*>(m_character);
		ene->setPosition(targetPosition);

		return;
	}

	//Ahora si interpolamos
	interpolate();
}

void NetworkPrediction::interpolateWithoutPrediction()
{
	m_character->updateEnemigo(newPosition);

	//Updateamos Rotacion
	m_character->getRenderState()->updateRotations(newRotation);
}
