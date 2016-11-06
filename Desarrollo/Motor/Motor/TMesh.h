#pragma once
#include "TEntity.h"

// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// GL Includes Contains all the necessery OpenGL includes
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>

#include "Shader.h"

struct Vertex {
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

struct Texture {
	GLuint id;
	string type;
	aiString path;
};


class TMesh : public TEntity {
public:

	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	TMesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	~TMesh();

	void beginDraw(Shader Shader);
	void endDraw();

private:
	/*  Render data  */
	GLuint VAO, VBO, EBO;

	void setupMesh();

};

