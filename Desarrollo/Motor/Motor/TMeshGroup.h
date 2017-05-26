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

#include "TMesh.h"

class SceneManager;



class TMeshGroup {
	
public:

	TMeshGroup(GLchar* path, Shader* shader=NULL);
	~TMeshGroup();

	void draw();
	

private:

	SceneManager &sm;


	

	std::vector<TMesh*> meshes;
	std::string directory;

	// Carga el modelo con ASSIMP
	void loadModel(const std::string& path);

	void processNode(aiNode* node, const aiScene* scene);

	TMesh* processMesh(aiMesh* mesh, const aiScene* scene);

	void loadMaterialTextures(std::vector<Texture*>& textVec, aiMaterial* mat, aiTextureType type, const std::string& typeName);

	
	
};


