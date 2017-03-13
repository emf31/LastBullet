#include "TMesh.h"

TMesh::TMesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture*>& textures, Shader *shader) {
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	this->shader = shader;

	this->setupMesh();
}


TMesh::~TMesh() {
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	vertices.clear();
	indices.clear();
	textures.clear();
}


void TMesh::beginDraw() {

	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	for (GLuint i = 0; i < this->textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i); // Activamos la textura que toca primero
										  // + i para la que toca ahora diffuseI (siendo I el número de la textura difusa)

		std::string name = this->textures[i]->type;
		// Ponemos en el sampler la textura que toca
		if (name == "texture_diffuse")
			glUniform1i(glGetUniformLocation(shader->Program, "material.texture_diffuse"), i);
		else if (name == "texture_specular")
			glUniform1i(glGetUniformLocation(shader->Program, "material.texture_specular"), i);
		else if (name == "texture_normal")
			glUniform1i(glGetUniformLocation(shader->Program, "material.texture_normal"), i);
		
		// Bindeamos la textura
		glBindTexture(GL_TEXTURE_2D, this->textures[i]->id);
	}

	// Ponemos el brillo a su valor por defecto (se podría cambiar el valor??)
	//glUniform1f(glGetUniformLocation(shader->Program, "material.brillo"), 128.0f);

	// Dibujamos!
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Dejamos todo como estaba y activamos la primera textura
	for (GLuint i = 0; i < this->textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TMesh::endDraw() {

}

void TMesh::setupMesh() {
	// Creamos los buffers y arrays
	glGenVertexArrays(1, &this->VAO); // Un VAO
	glGenBuffers(1, &this->VBO); // Un VBO
	glGenBuffers(1, &this->EBO); // Un EBO

	glBindVertexArray(this->VAO);
	// Cargamos datos en el VAO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

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