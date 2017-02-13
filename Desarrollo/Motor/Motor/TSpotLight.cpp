#include "TSpotLight.h"



TSpotLight::TSpotLight() {
	
	lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
	setColor(0.30f, 1.0f, 0.50f);
	m_matrix = glm::mat4();
	setLight();
}


TSpotLight::~TSpotLight() {
}

void TSpotLight::setColor(int r, int g, int b, int a) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void TSpotLight::setColor(int r, int g, int b) {
	m_r = r;
	m_g = g;
	m_b = b;
}

void TSpotLight::setLight()
{
	GLuint lightVAO;
	GLuint lightVBO;
	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO); // Un VBO
	glBindVertexArray(lightVAO);
	// We only need to bind to the VBO, the container's VBO's data already contains the correct data.
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	// Set the vertex attributes (only position data for our lamp)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}

void TSpotLight::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual) {
	m_matrix = matrizActual;
	matrizActual = glm::translate(matrizActual, lightPos);
	//matrizActual = glm::scale(matrizActual, glm::vec3(0.2f));
}

void TSpotLight::endDraw(glm::mat4& matrizActual) {
	 matrizActual= m_matrix;
}
