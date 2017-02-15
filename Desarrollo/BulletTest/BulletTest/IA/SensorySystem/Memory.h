#pragma once
#include <vec3.hpp>


class Memory {

	friend class SensoryMemory;
	
private:

	//Esta en el campo de vision
	bool m_inFOV;

	//Es disparable
	bool m_isShootable;

	//Tiempo que paso desde la ultima vez que lo noto
	double m_lastTimeSensed;

	//Tiempo que fue la ultima vez que lo viste
	double m_lastTimeVisible;

	//Tiempo que estuvo visible
	double m_TimeBecameVisible;

	//Ultima posicion vista
	Vec3<float> m_lastPosition;

public:
	
	Memory():m_inFOV(false),m_isShootable(false), m_lastTimeSensed(-1000), m_TimeBecameVisible(-1000), m_lastTimeVisible(0) {}

};