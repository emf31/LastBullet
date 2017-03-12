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


//This class represents the data from a Model. Every loaded model can have a group of meshes that are stored in a vector of TMesh.
//Inherits from TEntity to have a access to beginDraw and endDraw. This class should be managed with ResourceManager,
//preventing mulitple instances from the same path.

class TMeshGroup : public TEntity {
	
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TMeshGroup(GLchar* path, Shader* shader=NULL);
	~TMeshGroup();

	virtual void beginDraw();

	virtual void endDraw();
	

private:

	SceneManager &sm;


	/*  Model Data  */

	std::vector<TMesh*> meshes;
	std::string directory;
	std::vector<Texture*> textures_loaded;	// Guardamos todas las texturas que hemos guardado hasta ahora (así no las cargamos dos veces, OPTIMIZACIÓN)

	/*  Funciones   */
	// Carga el modelo con ASSIMP
	void loadModel(const std::string& path);

	void processNode(aiNode* node, const aiScene* scene);

	TMesh* processMesh(aiMesh* mesh, const aiScene* scene);

	void loadMaterialTextures(std::vector<Texture*>& textVec, aiMaterial* mat, aiTextureType type, std::string typeName);

	
	friend class SceneManager;
};


