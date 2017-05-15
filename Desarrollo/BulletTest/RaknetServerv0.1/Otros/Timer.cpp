#include "Timer.h"
#include <iostream>

Timer::Timer()
{
	//Updateamos cada 60 para asegurarnos que el servidor no ralentiza el trafico
	m_rakNetFrameTime = 1000.0 / 120.0; //60 fps 
	m_deltaTime = 0.0; //no time has elapsed yet

	QueryPerformanceFrequency(&m_frequency); //get frequency

	
	QueryPerformanceCounter(&m_startTime); //start timer
}

Timer::~Timer() {}

Timer::milliseconds Timer::calcDifferenceInMS()
{
	milliseconds difference = (milliseconds)(m_endTime.QuadPart - m_startTime.QuadPart) / (milliseconds)(m_frequency.QuadPart);
	return difference * 1000;
}

bool Timer::shouldUpdate()
{
	bool shouldUpdate = false;


	QueryPerformanceCounter(&m_endTime); //end timer

	addDelta(calcDifferenceInMS()); //calculate and add elapsed time
	m_elapsedTime = calcDifferenceInMS();

	if (m_deltaTime >= m_rakNetFrameTime) //comprueba si hay que updatear raknet
	{
		m_deltaTime = m_deltaTime - m_rakNetFrameTime; //no olvidar el tiempo excedido

		shouldUpdate = true; //return true
	}

	QueryPerformanceCounter(&m_startTime); //reset start time

	return shouldUpdate; //else return false
}