#pragma once

#include <events/Event.h>

class Observer
{
public:
	virtual ~Observer() {}

	virtual void onNotify(Event& event) = 0;
};

