#pragma once

#include "ResourceManager.h"
#include "TMeshGroup.h"
#include <vector>
#include "AnimationMesh.h"

class AnimationReader {
public:
	static void LoadMeshesFromDirectory(const std::string& directory, unsigned int numAnimations, std::vector<std::string>& vector);


};