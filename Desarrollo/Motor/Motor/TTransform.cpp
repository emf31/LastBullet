#include "TTransform.h"
#include "SceneManager.h"
#include <glm/gtx/rotate_vector.hpp>


TTransform::TTransform() : sm(SceneManager::i()) {

	m_matrix = glm::mat4();
	m_rotation = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_position = Vec3<float>(0.0f, 0.0f, 0.0f);
	
}


TTransform::~TTransform() {
}


void TTransform::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTransform::invert() {
	m_matrix = glm::inverse(m_matrix);
}

void TTransform::setPosition(Vec3<float> position) {
	//setea al objeto en la posicion del mundo que le pasamos
	m_position = position;
	m_matrix = glm::mat4();
	m_matrix = glm::translate(m_matrix, glm::vec3(position.getX(), position.getY(), position.getZ()));
}
void TTransform::updatePosition(Vec3<float> position)
{	
	//le suma a la posicion que ya tenia el objeto la nueva posicion
	m_position += position;
	m_matrix = glm::translate(m_matrix, glm::vec3(position.getX(), position.getY(), position.getZ()));
}
void TTransform::setScale(Vec3<float> scale) {
	m_scale = scale;
	m_matrix = glm::mat4();
	m_matrix = glm::scale(m_matrix, glm::vec3(scale.getX(), scale.getY(), scale.getZ()));
}
void TTransform::setRotationX(float angu)
{	
	m_rotation.setX(angu);
	m_matrix = glm::rotate(m_matrix, glm::radians(angu), glm::vec3(1.0, 0.0, 0.0));
}
void TTransform::setRotationY(float angu)
{
	m_rotation.setY(angu);
	m_matrix = glm::rotate(m_matrix, glm::radians(angu), glm::vec3(0.0, 1.0, 0.0));

}
void TTransform::setRotationZ(float angu)
{
	m_rotation.setZ(angu);
	m_matrix = glm::rotate(m_matrix, glm::radians(angu), glm::vec3(0.0, 0.0, 1.0));
}

void TTransform::resetMatrix()
{
	m_matrix = glm::mat4();
}

Vec3<float> TTransform::getRotation()
{
	//este metodo lo necesitamos porque las rotaciones de los personajes en multijador se envian y reciben como la cantidad de grados rotados en X,Y,Z.
	return m_rotation;
}
Vec3<float> TTransform::getPosition()
{
	//este metodo lo necesitamos porque cuando enviamos paquetes de movimiento en el multijugador no podemos enviar matrices, enviamos vectores de 3 con la posicion en X,Y,Z del personaje.
	return m_position;
}
Vec3<float> TTransform::getScale()
{
	return m_scale;
}

glm::mat4 TTransform::getMatrix()
{
	return m_matrix;
}

void TTransform::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
}



void TTransform::loadMatrix(glm::mat4 mat) {
	m_matrix = mat;
}

void TTransform::beginDraw()
{
	sm.getPilaMatrices().push_back(sm.getMatrizActual());
	sm.setMatrizActual(m_matrix * sm.getMatrizActual());
}

void TTransform::beginDrawSombras()
{
	sm.getPilaMatrices().push_back(sm.getMatrizActual());
	sm.setMatrizActual(m_matrix * sm.getMatrizActual());
}

void TTransform::endDraw()
{
	sm.setMatrizActual(sm.getPilaMatrices().back());
	sm.getPilaMatrices().pop_back();
}

