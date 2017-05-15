#pragma once
#include <stack>
#include <Estructuras.h>
#include <time.h>
#include <TimePerFrame.h>

class Enemy;

//Esta clase es un componente para un Enemy. Se encarga de realizar la interpolación de la entidad
//para suavizar el movimiento en caso de perdida de paquetes debido al lag en la comunicación.
class NetworkPrediction {

public:
	NetworkPrediction(Enemy* character);
	~NetworkPrediction();

	void addMovement(TMovimiento & mov);


	void interpolateWithPrediction();
	void interpolateWithoutPrediction();

private:
	

	void updateMovement(TMovimiento& mov);
	void updateState(TMovimiento& mov);

	void interpolate();

	Enemy* m_character;

	Time currentTime;
	Time startTime;
	Time targetTime;

	//Para calcular el delta time
	RakNet::TimeMS prevTime;

	
	Vec3<float> prevPosition;	//Hace un paquete
	Vec3<float> newPosition;	//Paquete actual
	Vec3<float> targetPosition;	//Posicion predecida

	Vec3<float> newRotation;

	//Valor actual de interpolacion entre 0 - 1
	float interpolation;

};