#include "EngineDevice.h"



EngineDevice::EngineDevice() {
}


EngineDevice::~EngineDevice() {
}

SceneManager * EngineDevice::getSceneManager() {
	if (sm != nullptr) {
		return sm;
	} else {
		sm = new SceneManager();
	}
}
