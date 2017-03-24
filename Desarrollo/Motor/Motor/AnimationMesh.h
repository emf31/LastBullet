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


//This class represents the data of a Model. Every loaded model can have a group of meshes that are stored in a vector of TMesh.
//Inherits from TEntity to have access to beginDraw and endDraw. This class should be managed with ResourceManager,
//preventing mulitple instances from the same path.

class AnimationMesh : public TEntity {
	
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	AnimationMesh(const std::string& path, /*std::vector<Texture*>& text, aiMaterial* mat,*/ Shader* shader = NULL);
	~AnimationMesh();

	virtual void beginDraw();

	virtual void endDraw();
	
	aiMaterial ** AnimationMesh::getMaterials() const { return scene->mMaterials; }

	void processNode(aiMaterial** mat);

private:

	SceneManager &sm;


	/*  Model Data  */

	std::vector<TMesh*> meshes;
	std::string directory;
	std::vector<Texture*> textures_loaded;	// Guardamos todas las texturas que hemos guardado hasta ahora (así no las cargamos dos veces, OPTIMIZACIÓN)
	aiMaterial** materialArray;

	/*  Funciones   */
	// Carga el modelo con ASSIMP
	void loadModel(const std::string& path);

	void processNodeRecursively(aiNode * node, const aiScene * scene);

	TMesh* processMesh(aiMesh* mesh, const aiScene* scene);

	void loadMaterialTextures(std::vector<Texture*>& textVec, aiMaterial* mat, aiTextureType type, const std::string& typeName);

	const aiScene* scene;

	Assimp::Importer importer;




	friend class TAnimationGroupMesh;
	friend class SceneManager;
};


