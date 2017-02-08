#include "TMesh.h"

TMesh::TMesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures, Shader *shader) {
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	this->shader = shader;

	this->setupMesh();
}


TMesh::~TMesh() {
}


void TMesh::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual) {

	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	for (GLuint i = 0; i < this->textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i); // Activamos la textura que toca primero
										  // + i para la que toca ahora diffuseI (siendo I el número de la textura difusa)
		stringstream ss;
		string number;
		string name = this->textures[i].type;
		if (name == "texture_diffuse")
			ss << diffuseNr++; // GLuit << stream
		else if (name == "texture_specular")
			ss << specularNr++; // GLuit << stream
		number = ss.str();
		// Ponemos en el sampler la textura que toca
		glUniform1i(glGetUniformLocation(shader->Program, (name + number).c_str()), i);
		// Bindeamos la textura
		glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
	}

	// Ponemos el brillo a su valor por defecto (se podría cambiar el valor??)
	glUniform1f(glGetUniformLocation(shader->Program, "material.shininess"), 16.0f);

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
	//std::cout << "SE SUPONE QUE DIBUJO " << std::endl;
}

void TMesh::endDraw(glm::mat4& matrizActual) {

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

	glBindVertexArray(0);
}