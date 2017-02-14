#include "TTraslacion.h"


TTraslacion::TTraslacion() {

	m_position = glm::vec3(0.f);
	m_matrix = glm::mat4();
}


TTraslacion::~TTraslacion() {
}


void TTraslacion::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTraslacion::invert() {
	m_matrix = glm::inverse(m_matrix);
}
void TTraslacion::setPosition(Vec3<float> position) {
	m_position = glm::vec3(position.getX(), position.getY(), position.getZ());
}
Vec3<float> TTraslacion::getPosition() {
	return Vec3<float>(m_position.x, m_position.y, m_position.z);
}
void TTraslacion::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
}

void TTraslacion::multiply(glm::vec4 vec) {
	//m_matrix = vec * m_matrix ;
	//TODO

}

void TTraslacion::loadMatrix(glm::mat4 mat) {
	m_matrix = mat;
}

void TTraslacion::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual)
{
	m_matrix = matrizActual;
	matrizActual = glm::translate(matrizActual, m_position);
	std::cout << "TRASLADO:" << std::endl;
	for (int i = 0; i < matrizActual.length(); i++) {
	for (int j = 0; j < matrizActual[0].length(); j++) {
	std::cout << matrizActual[i][j] << " ";
	}
	std::cout<<std::endl;
	}
	

}

void TTraslacion::endDraw(glm::mat4& matrizActual)
{
	matrizActual = m_matrix;
}

