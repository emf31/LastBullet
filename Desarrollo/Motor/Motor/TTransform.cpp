#include "TTransform.h"


TTransform::TTransform() {

	m_scale = glm::vec3(1.f);
	m_position = glm::vec3(1.f);
	m_rotation = glm::vec3(1.f);
	m_matrix = glm::mat4();
	angulo = 0.0f;
}


TTransform::~TTransform() {
}


void TTransform::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTransform::invert() {
	m_matrix = glm::inverse(m_matrix);
}
/*
Esto ya no lo tenemos asi porque cuando llamas a trasladar y rotar lo que hace es cambiar los vectores correspondientes
y estos vectores ya se multiplicaran por la matrizactual que acumula las transformaciones de los padres cuando le toque en el begin draw
porque si multiplicamos por la matriz propia de cada TTransform no estariamos teniendo en cuenta las transformaciones de los padres.

Entonces cuando nosotros movemos una malla lo que hacemos es cambiarle el vector posicion y este ya se multiplicara por la matriz cuando se llame a su begindraw

void TTransform::translate(float x, float y, float z) {
	m_matrix = glm::translate(m_matrix,glm::vec3(x,y,z));
}

void TTransform::rotate(float f1, float f2, float f3, float angle) {
	m_matrix = glm::rotate(m_matrix,angle,glm::vec3(f1,f2,f3));
}

void TTransform::scale(float s1, float s2, float s3) {
	m_matrix = glm::scale(m_matrix, glm::vec3(s1,s2,s3));
}
*/
void TTransform::multiply(glm::mat4 mat) {
	m_matrix = m_matrix * mat;
}

void TTransform::multiply(glm::vec4 vec) {
	//m_matrix = vec * m_matrix ;
	//TODO
	
}

void TTransform::loadMatrix(glm::mat4 mat) {
	m_matrix = mat;
}

void TTransform::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual)
{
	m_matrix = matrizActual;

	matrizActual = glm::rotate(matrizActual, angulo, m_rotation);
	matrizActual = glm::scale(matrizActual, m_scale);
	matrizActual = glm::translate(matrizActual, m_position);
}

void TTransform::endDraw(glm::mat4& matrizActual)
{
	matrizActual = m_matrix;
}

