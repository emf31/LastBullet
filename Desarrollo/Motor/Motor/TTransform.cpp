#include "TTransform.h"


TTransform::TTransform() {
	
}


TTransform::~TTransform() {
}

glm::mat4 TTransform::getIdentidad() {
	
	return m_matrix;
}

void TTransform::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTransform::invert() {
	m_matrix = glm::inverse(m_matrix);
}

void TTransform::translate(float x, float y, float z) {
	
}

void TTransform::rotate(float f1, float f2, float f3, float f4, int axis) {
	
}

void TTransform::scale(float s1, float s2, float s3) {
	
}

void TTransform::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
	
}

void TTransform::multiply(glm::vec4 vec) {
	//m_matrix = vec * m_matrix ;
}

