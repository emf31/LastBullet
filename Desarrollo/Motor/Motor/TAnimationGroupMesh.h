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


//This class represents the data of a Model. Every loaded model can have a group of meshes that are stored in a vector of TMesh.
//Inherits from TEntity to have access to beginDraw and endDraw. This class should be managed with ResourceManager,
//preventing mulitple instances from the same path.

class TAnimationGroupMesh : public TEntity {
	
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TAnimationGroupMesh(const std::string & directory, unsigned int numAnimations);
	~TAnimationGroupMesh();

	virtual void beginDraw();

	virtual void endDraw();
	
	std::vector<AnimationMesh*> vectorModelos;
private:

	SceneManager &sm;

	
	/*  Model Data  */

	std::vector<std::string> paths;
	
	std::string directory;
	aiMaterial** material;


	void processAnimations();
	/*  Funciones   */
	// Carga el modelo con ASSIMP
	
	unsigned int NumFrames;
	
	friend class SceneManager;
};


