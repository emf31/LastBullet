#pragma once
#include <stack>
#include <Estructuras.h>
#include <time.h>
#include <TimePerFrame.h>

class Character;

//Esta clase es un componente para un Character. Se encarga de realizar la interpolación de la entidad
//para suavizar el movimiento en caso de perdida de paquetes debido al lag en la comunicación.
class NetworkPrediction {

public:
	NetworkPrediction(Character* character);
	~NetworkPrediction();

	void addMovement(TMovimiento & mov);

	

	void interpolate(Time elapsedTime);

private:
	void updateMovement(TMovimiento& mov);

	std::stack<TMovimiento> m_positions;

	Character* m_character;

	Time lastPacketReceived;

	TMovimiento newMovement;
	TMovimiento prevMovement;


	//Valor actual de interpolacion entre 0 - 1
	float interpolation;
};