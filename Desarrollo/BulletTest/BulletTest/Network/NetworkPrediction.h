#pragma once
#include <stack>
#include <Estructuras.h>
#include <time.h>
#include <TimePerFrame.h>

class Enemy;

//Esta clase es un componente para un Character. Se encarga de realizar la interpolación de la entidad
//para suavizar el movimiento en caso de perdida de paquetes debido al lag en la comunicación.
class NetworkPrediction {

public:
	NetworkPrediction(Enemy* character);
	~NetworkPrediction();

	void addMovement(TMovimiento & mov);

	

	void interpolateWithPrediction();
	void interpolateWithoutPrediction();

private:
	bool compareVec3(const Vec3<float>& lhs, const Vec3<float>& rhs);
	void updateMovement(TMovimiento& mov);

	Enemy* m_character;

	Time currentTime;
	Time startTime;
	Time targetTime;

	
	Vec3<float> prevPosition;	//Hace un paquete
	Vec3<float> newPosition; //Para predecir el movimiento
	Vec3<float> targetPosition;	//Posicion destino


	//Valor actual de interpolacion entre 0 - 1
	float interpolation;
};