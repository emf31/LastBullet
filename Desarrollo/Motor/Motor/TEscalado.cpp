#include "TEscalado.h"


TEscalado::TEscalado() {

	m_scale = glm::vec3(1.f);
}


TEscalado::~TEscalado() {
}


void TEscalado::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TEscalado::invert() {
	m_matrix = glm::inverse(m_matrix);
}
void TEscalado::setScale(Vec3<float> scale) {
	m_scale = glm::vec3(scale.getX(), scale.getY(), scale.getZ());
}

Vec3<float> TEscalado::getScale() {
	return Vec3<float>(m_scale.x, m_scale.y, m_scale.z);
}
void TEscalado::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
}

void TEscalado::multiply(glm::vec4 vec) {
	//m_matrix = vec * m_matrix ;
	//TODO

}

void TEscalado::loadMatrix(glm::mat4 mat) {
	m_matrix = mat;
}

void TEscalado::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual)
{
	m_matrix = matrizActual;
	matrizActual = glm::scale(matrizActual, m_scale);
	std::cout << "ESCALO:" << std::endl;
	for (int i = 0; i < matrizActual.length(); i++) {
		for (int j = 0; j < matrizActual[0].length(); j++) {
			std::cout << matrizActual[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void TEscalado::endDraw(glm::mat4& matrizActual)
{
	matrizActual = m_matrix;
}

