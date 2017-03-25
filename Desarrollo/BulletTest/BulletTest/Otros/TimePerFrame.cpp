#include "TimePerFrame.h"

Time TimePerFrameClass::m_timePerFrame = seconds(1.f / 15.f);

Time TimePerFrameClass::GetTimePerFrame()
{
	return m_timePerFrame;
}

void TimePerFrameClass::timePerFrameDefault()
{
	m_timePerFrame = seconds(1.f / 15.f);
}

void TimePerFrameClass::timePerFrameLoadingState()
{
	m_timePerFrame = seconds(1.f/60.f);
}
