#pragma once
#include "TEntity.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>

#include "Shader.h"

#include "Texture.h"

struct Vertex {
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

class TMesh : public TEntity {
public:

	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	TMesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures, Shader *shader);
	~TMesh();

	void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	void endDraw(glm::mat4& matrizActual);


private:
	/*  Render data  */
	Shader *shader;
	GLuint VAO, VBO, EBO;
	void setupMesh();

};

