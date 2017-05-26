#pragma once
#include "TEntity.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

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
	// Tangent
	glm::vec3 Tangent;
	// Bitangent
	glm::vec3 Bitangent;
};

class TMesh {
public:

	
	Vertex *vertices;
	GLuint *indices;
	std::vector<Texture*> textures;

	TMesh(Vertex* vertices, GLuint *indices, const std::vector<Texture*>& textures, Shader *shader, int tamVertices, int tamIndices);
	~TMesh();

	void draw();



private:
	
	Shader *shader;
	GLuint VAO, VBO, EBO;
	void setupMesh();
	int vertexCount, indexCount;

};

