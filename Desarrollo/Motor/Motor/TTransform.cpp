#include "TTransform.h"


TTransform::TTransform() {
	
}


TTransform::~TTransform() {
}

void TTransform::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTransform::invert() {
	m_matrix = glm::inverse(m_matrix);
}

void TTransform::translate(float x, float y, float z) {
	m_matrix = glm::translate(m_matrix,glm::vec3(x,y,z));
}

void TTransform::rotate(float f1, float f2, float f3, float angle) {
	m_matrix = glm::rotate(m_matrix,angle,glm::vec3(f1,f2,f3));
}

void TTransform::scale(float s1, float s2, float s3) {
	m_matrix = glm::scale(m_matrix, glm::vec3(s1,s2,s3));
}

void TTransform::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
}

void TTransform::multiply(glm::vec4 vec) {
	//m_matrix = vec * m_matrix ;
	//TODO
}

