#include "TSpotLight.h"
#include "SceneManager.h"




TSpotLight::TSpotLight() {
	
	lightPos = glm::vec3(3.0f, 5.0f, 2.0f);
	setColor(0.30f, 1.0f, 0.50f);
	m_matrix = glm::mat4();
	this->shaderLuz = ResourceManager::i().getShader("assets/luz_loading.vs", "assets/luz_loading.frag");
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
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO); // Un VBO

	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindVertexArray(lightVAO);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}

void TSpotLight::beginDraw() {
	m_matrix = SceneManager::i().m_matrizActual;
	SceneManager::i().m_matrizActual = glm::scale(SceneManager::i().m_matrizActual, glm::vec3(1.2f));
	SceneManager::i().m_matrizActual = glm::translate(SceneManager::i().m_matrizActual, lightPos);
	
	shaderLuz->Use();
	// Le pasamos las matrices
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "projection"), 1, GL_FALSE, glm::value_ptr(SceneManager::i().projection));
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "view"), 1, GL_FALSE, glm::value_ptr(SceneManager::i().view));
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "model"), 1, GL_FALSE, glm::value_ptr(SceneManager::i().m_matrizActual));


	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);


}

void TSpotLight::endDraw() {
	SceneManager::i().m_matrizActual = m_matrix;
}
