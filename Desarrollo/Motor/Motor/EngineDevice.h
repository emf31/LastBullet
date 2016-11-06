#pragma once
#include "SceneManager.h"
class EngineDevice {
public:
	EngineDevice();
	~EngineDevice();
	SceneManager* getSceneManager();

private:
	SceneManager *sm;
};

