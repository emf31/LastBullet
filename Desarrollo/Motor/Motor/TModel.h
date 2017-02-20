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
	friend class SceneManager;
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TModel(GLchar* path, Shader* shader=NULL);
	~TModel();


	static GLint TextureFromFile(const char* path, string directory) {
		// Generamos un ID de textura y cargamos la imagen con SOIL 
		string filename = string(path);
		filename = directory + '/' + filename;
		cout << filename << endl;
		GLuint textureID;
		glGenTextures(1, &textureID);
		int width, height;
		unsigned char* image = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB); // Podrian cambiarse a RGBA para imagenes con Alpha channel (es mejor?)
		// Assignamos la textura al nuevo ID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		// Parametros de filtrado
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		SOIL_free_image_data(image); // Liberamos la imagen de SOIL (Ya no hace falta)
		return textureID;
	}

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




	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);
	




	/*  Model Data  */
	vector<TMesh> meshes;
	string directory;
	vector<Texture> textures_loaded;	// Guardamos todas las texturas que hemos guardado hasta ahora (así no las cargamos dos veces, OPTIMIZACIÓN)
	Shader *shader;
	/*  Funciones   */
	// Carga el modelo con ASSIMP
	void loadModel(const string& path);

	void processNode(aiNode* node, const aiScene* scene);

	TMesh processMesh(aiMesh* mesh, const aiScene* scene);

	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

	//TNode* transRotacion;
	//TNode* transEscalado;
	//TNode* transTraslacion;
	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
	
	float m_r;
	float m_g;
	float m_b;
	

};


