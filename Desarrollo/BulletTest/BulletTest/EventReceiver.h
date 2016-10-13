#pragma once
#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class EventReceiver : public IEventReceiver
{
public:
	virtual bool OnEvent(const SEvent &TEvent) {

		if (TEvent.EventType == EET_KEY_INPUT_EVENT && !TEvent.KeyInput.PressedDown) {
			switch (TEvent.KeyInput.Key) {
			case KEY_ESCAPE:
				break;
			default:
				return false;
				break;
			}

			return true;
		}

		return false;
	}
};

