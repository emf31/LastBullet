#include "TSpotLight.h"
#include "SceneManager.h"




TSpotLight::TSpotLight() {
	
	setColor(1.0f, 1.0f, 1.0f);
	this->shaderLuz = ResourceManager::i().getShader("assets/luz_loading.vs", "assets/luz_loading.frag");
	setLight();
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
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
	

	glm::mat4 view = SceneManager::i().view;
	glm::mat4 projection = SceneManager::i().projection;
	glm::mat4 actual = SceneManager::i().m_matrizActual;
	glm::mat4 model = glm::mat4();
	int tam = SceneManager::i().pilaMatrices.size();
	for (int i = 0; i < tam; i++) {
		model = SceneManager::i().pilaMatrices.front()*model;
		SceneManager::i().pilaMatrices.pop_front();
	}
	//por si dependemos de la transformacion del padre, tenemos que multiplicar nuestra modelo por la de los padres que es la actual.
	model = actual * model;
	//seteamos la matrizActual a la del modelo por si acaso tiene algun hijo que necesita su matriz modelo
	SceneManager::i().m_matrizActual = model;

	/*
	m_matrix = SceneManager::i().m_matrizActual;
	m_matrix = glm::scale(m_matrix, glm::vec3(1.2f));
	m_matrix = glm::translate(m_matrix, lightPos);
	glm::mat4 view = SceneManager::i().view;
	glm::mat4 projection = SceneManager::i().projection;
	
	//por si algo dependiera de la transformacion de la luz tenemos que cambiar la matriz actual a la nueva matriz de luz, si no depende nada de esto cuando lleguemos al nodo raiz se resetearia a la identidad
	SceneManager::i().m_matrizActual = m_matrix;
	*/

	shaderLuz->Use();
	// Le pasamos las matrices
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(shaderLuz->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));


	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);


}

void TSpotLight::endDraw() {
	//SceneManager::i().m_matrizActual = m_matrix;
}


void TSpotLight::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TSpotLight::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TSpotLight::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TSpotLight::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}

void TSpotLight::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}

void TSpotLight::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TSpotLight::setTransformacionEscalado(TTransform * esc) {
	transEscalado = esc;
}

void TSpotLight::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
}

Vec3<float> TSpotLight::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TSpotLight::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TSpotLight::getScale()
{
	return transEscalado->getScale();
}

Vec3<float> TSpotLight::getColor() {
	return Vec3<float>(m_r, m_g, m_b);
}

