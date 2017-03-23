#pragma once

#include "ResourceManager.h"
#include "TMeshGroup.h"
#include <vector>

class AnimationReader {
public:
	static void LoadMeshesFromDirectory(const std::string& directory, unsigned int numAnimations, std::vector<TMeshGroup*>& vector);


};