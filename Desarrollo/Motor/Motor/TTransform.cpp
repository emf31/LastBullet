#include "TTransform.h"
#include "SceneManager.h"


TTransform::TTransform() {

	m_matrix = glm::mat4();
	angulo = 0.0f;
	m_rotation = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_scale = Vec3<float>(1.0f, 1.0f, 1.0f);
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
	m_position += position;
	m_matrix = glm::translate(m_matrix, glm::vec3(position.getX(), position.getY(), position.getZ()));
}
void TTransform::setScale(Vec3<float> scale) {
	m_scale = m_scale * scale;
	m_matrix = glm::scale(m_matrix, glm::vec3(scale.getX(), scale.getY(), scale.getZ()));
}
void TTransform::setRotationX(float angu)
{	
	m_rotation.setX(m_rotation.getX() + angu);
	m_matrix = glm::rotate(m_matrix, angulo, glm::vec3(1.0, 0.0, 0.0));
}
void TTransform::setRotationY(float angu)
{

	m_rotation.setY(m_rotation.getY() + angu);
	m_matrix = glm::rotate(m_matrix, angu, glm::vec3(0.0, 1.0, 0.0));

}
void TTransform::setRotationZ(float angu)
{
	m_rotation.setZ(m_rotation.getZ() + angu);
	m_matrix = glm::rotate(m_matrix, angulo, glm::vec3(0.0, 0.0, 1.0));
}
void TTransform::setRotation(Vec3<float> rotation) {
	/*
	
	
	glm::vec3 a = m_rotation;
	glm::vec3 b = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	m_rotation = glm::cross(b, a);
	angulo = acos(glm::dot(b, a) / (glm::length(b) * glm::length(a)));

	m_orientation = glm::rotate(m_orientation, rotation.getX(), glm::vec3(1.0, 0.0, 0.0));
	m_orientation = glm::rotate(m_orientation, rotation.getY(), glm::vec3(0.0, 1.0, 0.0));
	m_orientation = glm::rotate(m_orientation, rotation.getZ(), glm::vec3(0.0, 0.0, 1.0));

	m_rotation2 = glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ());
	std::cout << "El angulo es: " << angulo << "y el vector: " << m_rotation.x << "," << m_rotation.y << "," << m_rotation.z << std::endl;
	*/
}
Vec3<float> TTransform::getRotation()
{
	return m_rotation;
}
Vec3<float> TTransform::getPosition()
{
	return m_position;
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
	SceneManager::i().pilaMatrices.push_back(m_matrix);
	/*
	std::cout << "APILO MATRIZ: " << std::endl;
	for (int i = 0; i < m_matrix.length(); i++) {
		for (int j = 0; j < m_matrix[0].length(); j++) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/



	/*
	Pruebas Antiguas
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
	
	matrizActual = glm::rotate(matrizActual, angulo, glm::vec3(0.0, 1.0, 0.0));
	matrizActual = glm::scale(matrizActual, m_scale);
	matrizActual = glm::translate(matrizActual, m_position);
	/*
	glm::mat4 trans;
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	trans = glm::translate(trans, m_position);
	matrizActual = trans;
	
	/*
	for (int i = 0; i < matrizActual.length(); i++) {
	for (int j = 0; j < matrizActual[0].length(); j++) {
	std::cout << matrizActual[i][j] << " ";
	}
	std::cout<<std::endl;
	}
	


	//NOTA: lo que nos ha dicho en clase es que hagamos un unico nodo de transformacion que tenga rotacion, escalado y trasladado como hicimos antes, pero que el nodo rotacion solo rote y asi
	//la cosa es que cuando llamo a rotacion lo que tiene que hacer es actualizar la matriz de este nodo aplicandole el glm rotate (cada nodo transformacion tiene una matriz) y asi se irian acumulando
	//las rotaciones, luego en el begin draw lo que hacemos es apilar esta matriz ya rotada y en el end draw lo que hacemos es desapilar.
	//y luego donde se multiplican todas las matrices es en el begin draw del model que coge las 3 matrices una de cada nodo y las multiplica y esto es la matrices del modelo.
	
	*/

	
	
}

void TTransform::endDraw()
{
	//PREGUNTA , COMO TENEMOS QUE DESAPILAR EN EL END DRAW? PORQUE YA ESTAMOS DESAPILANDO LAS MATRICES PARA PODER OBTENERLAS Y MULTIPLICARLAS A LA HORA DE DIBUJAR
	//SceneManager::i().pilaMatrices.pop();
	/*
	
	std::cout << "DESAPILO MATRIZ: " << std::endl;
	for (int i = 0; i < m_matrix.length(); i++) {
		for (int j = 0; j < m_matrix[0].length(); j++) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/
}

