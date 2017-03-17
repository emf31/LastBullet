#pragma once

#include <Engine/ResourceManager.h>
#include <Engine/TMeshGroup.h>
#include <vector>

class AnimationReader {
public:
	static void LoadMeshesFromDirectory(const std::string& directory, std::vector<TMeshGroup*>& vector);


};