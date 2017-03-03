#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "vec3.hpp"
#include "TTransform.h"

using namespace std;

// GL Includes
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "TMesh.h"

//class TNode;

class TModel : public TEntity {
	
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TModel(GLchar* path, Shader* shader=NULL);
	~TModel();


	

	virtual void beginDraw();

	virtual void endDraw();

	void setPosition(Vec3<float> pos);
	void updatePosition(Vec3<float> pos);
	void setRotation(Vec3<float> rot);
	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);
	void setScale(Vec3<float> esc);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();


	void setModelColor(float r, float g, float b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}

	

private:

	SceneManager &sm;


	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);
	




	/*  Model Data  */
	vector<TMesh*> meshes;
	string directory;
	vector<Texture*> textures_loaded;	// Guardamos todas las texturas que hemos guardado hasta ahora (así no las cargamos dos veces, OPTIMIZACIÓN)
	Shader *shader;
	/*  Funciones   */
	// Carga el modelo con ASSIMP
	void loadModel(const string& path);

	void processNode(aiNode* node, const aiScene* scene);

	TMesh* processMesh(aiMesh* mesh, const aiScene* scene);

	void loadMaterialTextures(vector<Texture*>& textVec, aiMaterial* mat, aiTextureType type, string typeName);

	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
	
	float m_r;
	float m_g;
	float m_b;
	
	friend class SceneManager;
};


