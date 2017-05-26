#include "TMesh.h"
#include "SceneManager.h"

TMesh::TMesh(Vertex* vertices, GLuint *indices, const std::vector<Texture*>& textures, Shader *shader, int tamVertices, int tamIndices) {
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	this->shader = shader;
	vertexCount = tamVertices;
	indexCount = tamIndices;

	this->setupMesh();
}


TMesh::~TMesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	delete vertices;
	delete indices;
	textures.clear();
}


void TMesh::draw() {

	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	int cont = 0;

	for (std::vector<Texture*>::iterator it = textures.begin(); it != textures.end(); it++) {

		
		// Bindeamos la textura
		if (SceneManager::i().billboardrendering==false) {

			glActiveTexture(GL_TEXTURE0 + cont); // Activamos la textura que toca primero
												 // + cont para la que toca ahora diffuseI (siendo I el número de la textura difusa)

			std::string name = (*it)->type;
			// Ponemos en el sampler la textura que toca
			if (name == "texture_diffuse")
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_diffuse"), cont);
			else if (name == "texture_specular")
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_specular"), cont);
			else if (name == "texture_normal")
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_normal"), cont);
			else if (name == "texture_tangent")
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_tangent"), cont);
			else if (name == "texture_bitangent")
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_bitangent"), cont);
			else if (name == "texture_emisivo") {
				glUniform1i(glGetUniformLocation(shader->Program, "material.texture_emisivo"), cont);
			}
			glBindTexture(GL_TEXTURE_2D, (*it)->id);
			cont++;
		}
		
	}



	// Dibujamos!
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	cont = 0;
	// Dejamos todo como estaba y activamos la primera textura
	for (std::vector<Texture*>::iterator it = textures.begin(); it != textures.end(); it++) {
		glActiveTexture(GL_TEXTURE0 + cont);
		glBindTexture(GL_TEXTURE_2D, 0);
		cont++;
	}

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}



void TMesh::setupMesh() {
	// Creamos los buffers y arrays
	glGenVertexArrays(1, &this->VAO); // Un VAO
	glGenBuffers(1, &this->VBO); // Un VBO
	glGenBuffers(1, &this->EBO); // Un EBO

	glBindVertexArray(this->VAO);
	// Cargamos datos en el VAO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

	// Vértices (0)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	// Normales (1)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	// Coordenadas de texturas (2)
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
	// Vertex Tangent
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Tangent));
	// Vertex Bitangent
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Bitangent));

	glBindVertexArray(0);
}