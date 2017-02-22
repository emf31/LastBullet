#include "TTransform.h"
#include "SceneManager.h"
#include <glm/gtx/rotate_vector.hpp>


TTransform::TTransform() {

	m_matrix = glm::mat4();
	angulo = 0.0f;
	m_rotation = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_scale = Vec3<float>(1.0f, 1.0f, 1.0f);
	m_position = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_rotation2 = glm::vec3(0.0f, 0.0f, 0.0f);
	
}


TTransform::~TTransform() {
}


void TTransform::transpose() {
	m_matrix = glm::transpose(m_matrix);
}

void TTransform::invert() {
	m_matrix = glm::inverse(m_matrix);
}
//TODO necesitamos el setPosition que te ponga la posicion donde le pasamos sin que vaya acumulando como ahora, ahora seria un update position
void TTransform::setPosition(Vec3<float> position) {
	//setea al objeto en la posicion del mundo que le pasamos
	m_position = position;
	m_matrix = glm::mat4();
	m_matrix = glm::translate(m_matrix, glm::vec3(position.getX(), position.getY(), position.getZ()));
	//std::cout << "Vector posicion: " << m_position.getX()<<","<< m_position.getY()<<","<< m_position.getZ() << std::endl;
	//std::cout << "MATRIZ posicion: " << m_matrix[3][0] << "," << m_matrix[3][1] << "," << m_matrix[3][2] << std::endl;
}
void TTransform::updatePosition(Vec3<float> position)
{	
	//le suma a la posicion que ya tenia el objeto la nueva posicion
	m_position += position;
	m_matrix = glm::translate(m_matrix, glm::vec3(position.getX(), position.getY(), position.getZ()));
	//std::cout << "Vector posicion: " << m_position.getX()<<","<< m_position.getY()<<","<< m_position.getZ() << std::endl;
	//std::cout << "MATRIZ posicion: " << m_matrix[3][0] << "," << m_matrix[3][1] << "," << m_matrix[3][2] << std::endl;
}
void TTransform::setScale(Vec3<float> scale) {
	m_scale = m_scale * scale;
	m_matrix = glm::scale(m_matrix, glm::vec3(scale.getX(), scale.getY(), scale.getZ()));
}
void TTransform::setRotationX(float angu)
{	
	m_rotation.setX(angu);
	m_matrix = glm::rotate(m_matrix, angu, glm::vec3(1.0, 0.0, 0.0));
}
void TTransform::setRotationY(float angu)
{
	m_rotation.setY(angu);
	m_matrix = glm::mat4();
	m_matrix = glm::rotate(m_matrix, angu, glm::vec3(0.0, 1.0, 0.0));
	
	//m_rotation.setY(m_rotation.getY() + angu);
	//m_matrix = glm::rotate(m_matrix, angu, glm::vec3(0.0, 1.0, 0.0));
	//std::cout << "Angulo de rotacion es:" << angu << std::endl;
	//std::cout << "matriz rotacion : " << std::endl;
	//for (int i = 0; i < m_matrix.length(); i++) {
	//	for (int j = 0; j < m_matrix[0].length(); j++) {
	//		std::cout << m_matrix[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

}
void TTransform::setRotationZ(float angu)
{
	m_rotation.setZ(m_rotation.getZ() + angu);
	m_matrix = glm::rotate(m_matrix, angulo, glm::vec3(0.0, 0.0, 1.0));
}
void TTransform::setRotation(Vec3<float> rotation) {
	
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	//glm::vec3 X = glm::vec3(0.0f, 1.0f, 0.0f);
	//glm::vec3 Z = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 normal = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());

	glm::vec3 rot2 = glm::cross(up, normal);
	float anguX = acos(glm::dot(normal, up));
	//float anguY = acos(glm::dot(normal, X));
	//float anguZ = acos(glm::dot(normal, Z));
	rot2.z = 0.0f;
	m_matrix = glm::mat4();
	m_matrix = glm::rotate(m_matrix, anguX, rot2);
	//setRotationY(anguY);
	//setRotationX(anguX);
	//setRotationZ(anguZ);
	//m_matrix = glm::mat4();
	//m_matrix = glm::orientation(normal, up);
	
	std::cout << "matriz orientacion : " << std::endl;
	for (int i = 0; i < m_matrix.length(); i++) {
		for (int j = 0; j < m_matrix[0].length(); j++) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}




	/*
	glm::vec3 rot = glm::vec3(rotation.getX(), rotation.getX(), rotation.getX());
	std::cout<<"vector rotacion camara: " << rot.x << "," << rot.y << "," << rot.z << std::endl;
	std::cout << "matriz rotacion : " << std::endl;
	m_matrix = glm::orientation(rot, up);
	for (int i = 0; i < m_matrix.length(); i++) {
	for (int j = 0; j < m_matrix[0].length(); j++) {
	std::cout << m_matrix[i][j] << " ";
	}
	std::cout << std::endl;
	}
	*/



	


	//glm::vec3 a = m_rotation2;
	//glm::vec3 b = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	//m_rotation2 = glm::cross(b, a);
	//angulo = acos(glm::dot(b, a) / (glm::length(b) * glm::length(a)));

	//m_orientation = glm::rotate(m_orientation, rotation.getX(), glm::vec3(1.0, 0.0, 0.0));
	//m_matrix = glm::rotate(m_matrix, angulo, glm::vec3(0.0, 1.0, 0.0));
	//m_orientation = glm::rotate(m_orientation, rotation.getZ(), glm::vec3(0.0, 0.0, 1.0));

	//m_rotation2 = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	//std::cout << "El angulo es: " << angulo << "y el vector: " << m_rotation.x << "," << m_rotation.y << "," << m_rotation.z << std::endl;
	
}
Vec3<float> TTransform::getRotation()
{
	return m_rotation;
}
Vec3<float> TTransform::getPosition()
{
	return m_position;
	//return Vec3<float>(m_matrix[3][0], m_matrix[3][1], m_matrix[3][2]);
}
Vec3<float> TTransform::getScale()
{
	return m_scale;
}
glm::mat4 TTransform::getRotation2() {
	return m_matrix;
}
glm::mat4 TTransform::getPosition2() {
	return m_matrix;
}
glm::mat4 TTransform::getScale2() {
	return m_matrix;
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

void TTransform::beginDraw()
{
	//el begin draw lo primero que hace es apilar la matriz actual y multiplicar esta por la suya, y esta multiplicacion seria la nueva matriz acutual
	//que el siguiente nodo se encargaria de apilarla

	//el enddraw desapilaria una matriz y pondria esa desapilada como actual.
	SceneManager::i().pilaMatrices.push_back(SceneManager::i().m_matrizActual);
	SceneManager::i().m_matrizActual = m_matrix*SceneManager::i().m_matrizActual;
}

void TTransform::endDraw()
{
	//PREGUNTA , COMO TENEMOS QUE DESAPILAR EN EL END DRAW? PORQUE YA ESTAMOS DESAPILANDO LAS MATRICES PARA PODER OBTENERLAS Y MULTIPLICARLAS A LA HORA DE DIBUJAR
	SceneManager::i().m_matrizActual = SceneManager::i().pilaMatrices.back();
	SceneManager::i().pilaMatrices.pop_back();
}

