#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
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

class TModel {
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

	virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4 model);

	virtual void endDraw();
	

private:
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

};


