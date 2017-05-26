#include "TSunLight.h"
#include "SceneManager.h"

TSunLight::TSunLight(Vec3<float> direccion)
{
	m_direccion = direccion;

	calcularMatrices();
}

TSunLight::~TSunLight()
{
}

void TSunLight::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}

void TSunLight::pasarDatosAlShader(Shader * shader, int i)
{
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.ambiente"),ambiente.getX(), ambiente.getY(), ambiente.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.difusa"), difusa.getX(), difusa.getY(), difusa.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.especular"), especular.getX(), especular.getY(), especular.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.direction"), m_direccion.getX(), m_direccion.getY(), m_direccion.getZ());
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "sunlight.lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
}


void TSunLight::setRotationXYZ(Vec3<float> dir)
{
	transRotacion->resetMatrix();
	transRotacion->setRotationY(dir.getY());
	transRotacion->setRotationX(dir.getX() - 90.0f);
	transRotacion->setRotationZ(dir.getZ());

	updateVectorDireccion();
}

Vec3<float> TSunLight::getDireccion()
{
	return m_direccion;
}

void TSunLight::updateVectorDireccion()
{
	glm::vec4 destino = glm::vec4(0, 0, 1, 1);
	glm::mat4 rot = transRotacion->getMatrix();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	m_direccion = Vec3<float>(destino.x, destino.y, destino.z);

	calcularMatrices();
}

glm::mat4 TSunLight::getLightProjection()
{
	return lightProjection;
}

glm::mat4 TSunLight::getLightView()
{
	return lightView;
}

glm::mat4 TSunLight::getLightSpaceMatrix()
{
	return lightSpaceMatrix;
}


void TSunLight::calcularMatrices() {
	GLfloat z = 45.0f;
	lightProjection = glm::perspective(z, (float)1280 / (float)720, 1.0f, 500.0f);
	lightView = glm::lookAt(glm::vec3(m_position.getX(), m_position.getY(), m_position.getZ()), glm::vec3(m_direccion.getX(), m_direccion.getY(), m_direccion.getZ()), glm::vec3(0.0, 1.0, 0.0));
	lightSpaceMatrix = lightProjection * lightView;
}


//Aunque este tipo de luces direccionales no tienen posicion sino que son rayos paralelos que se emiten desde todas partes para que se 
//puedan generar sombras necesitamos poner la luz en un punto especifico de la escena, por eso se necesita un setPosition.
void TSunLight::setPosition(Vec3<float> pos) {
	m_position = pos;
	calcularMatrices();
}
void TSunLight::setVectorDireccion(Vec3<float> dir) {
	m_direccion = dir;
	calcularMatrices();
}

Vec3<float> TSunLight::getPosition() {
	return m_position;
}
