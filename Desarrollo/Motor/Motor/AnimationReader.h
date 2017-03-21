#pragma once

#include "ResourceManager.h"
#include "TMeshGroup.h"
#include <vector>

class AnimationReader {
public:
	static void LoadMeshesFromDirectory(const std::string& directory, std::vector<TMeshGroup*>& vector);


};