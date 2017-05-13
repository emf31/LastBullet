#pragma once

#include <Util.h>
#include <Time.hpp>
#include <Clock.hpp>



class RegulatorIA
{

public:


	RegulatorIA(double NumUpdatesPerSecond);

	bool isReady();

private:


	double m_UpdatePeriod;


	double m_wNextUpdateTime;

	Clock m_Clock;
};