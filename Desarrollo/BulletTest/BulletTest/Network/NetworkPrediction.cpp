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
	deltaTime = milliseconds(mov.timeStamp - prevTime);

	prevTime = mov.timeStamp;

	prevPosition = newPosition;
	newPosition = mov.position;

	//Deberiamos corregir la posicion predecida???
	if (!compareVec3(newPosition, targetPosition)) {
		//m_character->updateEnemigo(newPosition);
	}

	//Calcular target time y target position
	delta = (newPosition - prevPosition);
	
	targetPosition = newPosition + (delta * deltaTime.asSeconds());
	
	//TargetTime = tiempo actual + tiempo en moverse de posPrev a PosNew
	targetTime = milliseconds(RakNet::GetTimeMS()) + deltaTime;


}

//Esto se llama cuando hay que calcular una nueva posicion a partir de una ya predecida
void NetworkPrediction::calculateNextPositionFromPredictedOne() {
	//Tiempo en el que recibimos paquete
	startTime = milliseconds(RakNet::GetTimeMS());

	prevTime = RakNet::GetTimeMS() - deltaTime.asMilliseconds();

	prevPosition = newPosition;
	newPosition = targetPosition;

	targetPosition = newPosition + (delta * deltaTime.asSeconds());

	//TargetTime = tiempo actual + tiempo en moverse de posPrev a PosNew
	targetTime = milliseconds(RakNet::GetTimeMS()) + deltaTime;

}

void NetworkPrediction::updateState(TMovimiento & mov)
{
	newRotation = mov.rotation;
	m_character->setIsDying(mov.isDying);

}

void NetworkPrediction::interpolate()
{
	//No hacemos nada 0/0 = runtime_error
	if (targetTime == startTime)
	{
		return;
	}

	currentTime = milliseconds(RakNet::GetTimeMS());

	float interpolation = (float)(currentTime.asSeconds() - startTime.asSeconds()) / (float)(targetTime.asSeconds() - startTime.asSeconds());

	//Ya hemos alcanzado la posicion predecida, calcularmos una nueva a partir de la ya predecida
	if (interpolation >= 1.0f)
	{	
		calculateNextPositionFromPredictedOne();
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
