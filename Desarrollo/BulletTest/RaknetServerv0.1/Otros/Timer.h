#pragma once

#include <time.h>
#include <windows.h>

class Timer
{
public:
	typedef double milliseconds;

public:
	Timer();
	~Timer();

	//devuelve true si ha pasado suficiente tiempo
	bool   shouldUpdate();

	const milliseconds& getDeltaTime() { return m_deltaTime; };
	const milliseconds& getElapsedTime() { return m_elapsedTime; };
private:
	//timer variables
	LARGE_INTEGER m_startTime;
	LARGE_INTEGER m_frequency;
	LARGE_INTEGER m_endTime;

	//cada cuanto hay que updatear raknet y elapsedTime
	milliseconds m_rakNetFrameTime, m_deltaTime, m_elapsedTime;

	//añadimos time
	void addDelta(milliseconds delta) { m_deltaTime += delta; };
	//calc elapsed time
	milliseconds calcDifferenceInMS();
};
