#pragma once

#include <Time.hpp>

class TimePerFrameClass {
private:
	 static Time m_timePerFrame ;
public:
	static Time GetTimePerFrame();
	static void timePerFrameDefault() ;
	static void timePerFrameLoadingState();

};




