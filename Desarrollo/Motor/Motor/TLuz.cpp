#include "TLuz.h"


#include "SceneManager.h"




TLuz::TLuz() {

	std::cout << "SI QUE ENTRO AL CONTRUCTOR DE LUZ CUANDO CREO UNA LUZ DE CUALQUIER TIPO" << std::endl;
	gradoLuzAmbiente = 0.1f;
	gradoLuzDifusa = 0.5f;
	gradoLuzEspecular = 1.0f;
	setColor(1.0f, 1.0f, 1.0f);
	setLight();
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
}


TLuz::~TLuz() {
}

void TLuz::setColorAlpha(float r, float g, float b, float a) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void TLuz::setColor(float r, float g, float b) {
	m_r = r;
	m_g = g;
	m_b = b;
	ambiente = Vec3<float>(r, g, b) * gradoLuzAmbiente;
	difusa = Vec3<float>(r, g, b) * gradoLuzDifusa;
	especular = Vec3<float>(r, g, b) * gradoLuzEspecular;
}

float TLuz::getR()
{
	return m_r;
}

float TLuz::getG()
{
	return m_g;
}

float TLuz::getB()
{
	return m_b;
}

void TLuz::setIntensidadAmbiente(float intensidad)
{
	gradoLuzAmbiente = intensidad;
	ambiente = Vec3<float>(m_r, m_g, m_b) * gradoLuzAmbiente;
	
}

void TLuz::setIntensidadDifusa(float intensidad)
{
	gradoLuzDifusa = intensidad;
	difusa = Vec3<float>(m_r, m_g, m_b) * gradoLuzDifusa;
	
}

void TLuz::setIntensidadEspecular(float intensidad)
{
	gradoLuzEspecular = intensidad;
	especular = Vec3<float>(m_r, m_g, m_b) * gradoLuzEspecular;
}

Vec3<float> TLuz::getColor() {
	return Vec3<float>(m_r, m_g, m_b);
}


void TLuz::setLight()
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
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	
	

}
void TLuz::beginDraw() {

	SceneManager &sm = SceneManager::i();
	glm::mat4 view = sm.view;
	glm::mat4 projection = sm.projection;
	glm::mat4 model = sm.m_matrizActual;

	sm.shaderBombillas->Use();
	// Le pasamos las matrices
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderBombillas->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderBombillas->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderBombillas->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));


	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);


}

void TLuz::endDraw() {
}


void TLuz::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TLuz::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TLuz::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TLuz::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}

void TLuz::setRotation(Vec3<float> dir)
{
	transRotacion->setRotationDirection(dir);
}

void TLuz::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}
void TLuz::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
}

Vec3<float> TLuz::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TLuz::getPosition()
{
	return transTraslacion->getPosition();
}




