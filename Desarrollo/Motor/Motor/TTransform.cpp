#include "TTransform.h"


TTransform::TTransform() {

	m_scale = glm::vec3(1.f);
	m_position = glm::vec3(0.f);
	m_origen = glm::vec3(0.f);
	m_rotation = glm::vec3(1.f);
	m_matrix = glm::mat4();
	m_orientation = glm::mat4();
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
void TTransform::setPosition(Vec3<float> position) {
	m_position = glm::vec3(position.getX(), position.getY(), position.getZ());
}
void TTransform::setScale(Vec3<float> scale) {
	m_scale = glm::vec3(scale.getX(), scale.getY(), scale.getZ());
}
void TTransform::setRotation(Vec3<float> rotation) {
	
	glm::vec3 a = m_rotation;
	glm::vec3 b = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	m_rotation = glm::cross(b, a);
	angulo = acos(glm::dot(b, a) / (glm::length(b) * glm::length(a)));

	m_orientation = glm::rotate(m_orientation, rotation.getX(), glm::vec3(1.0, 0.0, 0.0));
	m_orientation = glm::rotate(m_orientation, rotation.getY(), glm::vec3(0.0, 1.0, 0.0));
	m_orientation = glm::rotate(m_orientation, rotation.getZ(), glm::vec3(0.0, 0.0, 1.0));

	m_rotation2 = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	std::cout << "El angulo es: " << angulo << "y el vector: " << m_rotation.x << "," << m_rotation.y << "," << m_rotation.z << std::endl;
}
void TTransform::setRotation2(float angu, Vec3<float> rotation)
{
	m_rotation = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	angulo = angu;
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
Vec3<float> TTransform::getRotation() {
	return Vec3<float>(m_rotation.x, m_rotation.y, m_rotation.z);
}
Vec3<float> TTransform::getPosition() {
	return Vec3<float>(m_position.x, m_position.y, m_position.z);
}
Vec3<float> TTransform::getScale() {
	return Vec3<float>(m_scale.x, m_scale.y, m_scale.z);
}
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
	/*
		//matrizActual = glm::translate(matrizActual, m_origen);
	//matrizActual = glm::rotate(matrizActual, 90.f, m_rotation);
	matrizActual = glm::rotate(matrizActual, angulo, m_rotation);
	//matrizActual *= m_orientation;
	matrizActual = glm::scale(matrizActual, m_scale);
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
	vec = trans * vec;
	std::cout << vec.x << vec.y << vec.z << std::endl;
	matrizActual = glm::translate(matrizActual, m_position);
	
	*/
	matrizActual = glm::rotate(matrizActual, angulo, glm::vec3(0.0, 1.0, 0.0));
	matrizActual = glm::scale(matrizActual, m_scale);
	matrizActual = glm::translate(matrizActual, m_position);
	/*
	glm::mat4 trans;
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	trans = glm::translate(trans, m_position);
	matrizActual = trans;
	*/


	/*
		for (int i = 0; i < matrizActual.length(); i++) {
		for (int j = 0; j < matrizActual[0].length(); j++) {
			std::cout << matrizActual[i][j] << " ";
		}
		std::cout<<std::endl;
	}
	*/

	
	
}

void TTransform::endDraw(glm::mat4& matrizActual)
{
	matrizActual = m_matrix;
}

