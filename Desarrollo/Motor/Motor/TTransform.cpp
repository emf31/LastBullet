#include "TTransform.h"
#include "SceneManager.h"
#include <glm/gtx/rotate_vector.hpp>


TTransform::TTransform() : sm(SceneManager::i()) {

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
	m_matrix = glm::mat4();
	m_matrix = glm::rotate(m_matrix, glm::radians(angu), glm::vec3(0.0, 1.0, 0.0));

}
void TTransform::setRotationZ(float angu)
{
	m_rotation.setZ(angu);
	m_matrix = glm::rotate(m_matrix, glm::radians(angu), glm::vec3(0.0, 0.0, 1.0));
}

void TTransform::setRotationDirection(Vec3<float> vecDir)
{
	m_matrix = glm::mat4();
	glm::vec3 column1;
	glm::vec3 column2;
	glm::vec3 column3;
	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::vec3 direction = glm::vec3(vecDir.getX(), vecDir.getY(), vecDir.getZ());

	glm::vec3 xaxis = glm::cross(up, direction);
	xaxis = glm::normalize(xaxis);

	glm::vec3 yaxis = glm::cross(direction, xaxis);
		
	yaxis = glm::normalize(yaxis);

	column1.x = xaxis.x;
	column1.y = yaxis.x;
	column1.z = direction.x;

	column2.x = xaxis.y;
	column2.y = yaxis.y;
	column2.z = direction.y;

	column3.x = xaxis.z;
	column3.y = yaxis.z;
	column3.z = direction.z;

	m_matrix[0][0] = column1.x;
	m_matrix[1][0] = column1.y;
	m_matrix[2][0] = column1.z;

	m_matrix[0][1] = column2.x;
	m_matrix[1][1] = column2.y;
	m_matrix[2][1] = column2.z;

	m_matrix[0][2] = column3.x;
	m_matrix[1][2] = column3.y;
	m_matrix[2][2] = column3.z;
	


}
void TTransform::setRotationRadians(Vec3<float> rotation)
{
	m_matrix = glm::mat4(); //reiniciamos la matriz
	const double ch = cos(rotation.getY());
	const double sh = sin(rotation.getY());
	const double ca = cos(rotation.getX());
	const double sa = sin(rotation.getX());
	const double cb = cos(rotation.getZ());
	const double sb = sin(rotation.getZ());

	m_matrix[0][0] = float(ch * ca);
	m_matrix[0][1] = float(sh*sb - ch*sa*cb);
	m_matrix[0][2] = float(ch*sa*sb + sh*cb);

	m_matrix[1][0] = float(sa);
	m_matrix[1][1] = float(ca*cb);
	m_matrix[1][2] = float(-ca*sb);

	m_matrix[2][0] = float(-sh*ca);
	m_matrix[2][1] = float(sh*sa*cb + ch*sb);
	m_matrix[2][2] = float(-sh*sa*sb + ch*cb);

		    
}
void TTransform::setRotationDegrees(Vec3<float> rotation)
{
	setRotationRadians(rotation * (PI_MOTOR /180));
}
void TTransform::setRotationDegreesLeftHand(Vec3<float> rotation)
{
	setRotationRadiansLeftHand(rotation * (PI_MOTOR / 180));
}
void TTransform::setRotationRadiansLeftHand(Vec3<float> rotation)
{
	m_matrix = glm::mat4(); //reiniciamos la matriz
	const double cr = cos(rotation.getX());
	const double sr = sin(rotation.getX());
	const double cp = cos(rotation.getY());
	const double sp = sin(rotation.getY());
	const double cy = cos(rotation.getZ());
	const double sy = sin(rotation.getZ());

	m_matrix[0][0] = float(cp*cy);
	m_matrix[0][1] = float(cp*sy);
	m_matrix[0][2] = float(-sp);

	const float srsp = float(sr*sp);
	const float crsp = float(cr*sp);

	m_matrix[1][0] = float(srsp*cy - cr*sy);
	m_matrix[1][1] = float(srsp*sy + cr*cy);
	m_matrix[1][2] = float(sr*cp);

	m_matrix[2][0] = float(crsp*cy + sr*sy);
	m_matrix[2][1] = float(crsp*sy - sr*cy);
	m_matrix[2][2] = float(cr*cp);
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
glm::mat4 TTransform::getRotationMatrix() {
	return m_matrix;
}
glm::mat4 TTransform::getPositionMatrix() {
	return m_matrix;
}
glm::mat4 TTransform::getScaleMatrix() {
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
	sm.getPilaMatrices().push_back(sm.getMatrizActual());
	sm.setMatrizActual(m_matrix * sm.getMatrizActual());
}

void TTransform::endDraw()
{
	sm.setMatrizActual(sm.getPilaMatrices().back());
	sm.getPilaMatrices().pop_back();
}

