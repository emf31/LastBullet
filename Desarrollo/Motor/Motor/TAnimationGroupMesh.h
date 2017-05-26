#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "vec3.hpp"


// GL Includes
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "AnimationReader.h"
#include "AnimationMesh.h"

class SceneManager;

class TAnimationGroupMesh {
	
public:

	TAnimationGroupMesh(const std::string & directory, unsigned int numAnimations);
	~TAnimationGroupMesh();

	void draw();
	
	std::vector<AnimationMesh*> vectorModelos;
private:

	SceneManager &sm;



	std::vector<std::string> paths;
	
	std::string directory;
	aiMaterial** material;


	void processAnimations();

	
	unsigned int NumFrames;
	
};


