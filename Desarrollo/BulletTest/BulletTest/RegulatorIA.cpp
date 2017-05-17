#include "RegulatorIA.h"

RegulatorIA::RegulatorIA(double NumUpdatesPerSecond)
{
	m_wNextUpdateTime = (m_Clock.getElapsedTime().asMilliseconds() + Randf() * 1000);

	if (NumUpdatesPerSecond > 0)
	{
		m_UpdatePeriod = 1000.0 / NumUpdatesPerSecond;
	}
}

bool RegulatorIA::isReady()
{

	double CurrentTime = m_Clock.getElapsedTime().asMilliseconds();

	static const double UpdatePeriodVariator = (double)10.0;

	if (CurrentTime >= m_wNextUpdateTime)
	{
		m_wNextUpdateTime = CurrentTime + m_UpdatePeriod + Randf(-UpdatePeriodVariator, UpdatePeriodVariator);

		return true;
	}

	return false;
}