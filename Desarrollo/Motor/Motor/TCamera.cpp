#include "TCamera.h"
#include "SceneManager.h"

#define PI 3.141592654 



// Constructor with vectors

TCamera::TCamera() {

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//paramtros camara
	movementSpeed = SPEED*3;
	mouseSensitivity = SENSITIVTY;
	zoom=ZOOM;

	//rotacion y vectores iniciales
	rotX = 0.0f;
	rotY = 0.0f;
	direccion = glm::vec3(0.0f, 0.0f, -1.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	derecha= glm::cross(direccion, worldUp);
	derecha = glm::normalize(derecha);
	inputEnable = true;
	projection = glm::perspective(zoom, (float)1280 / (float)720, nearPlane, farPlane);
}


TCamera::~TCamera() {
	
}


glm::mat4 TCamera::GetViewMatrix() {
	view = glm::mat4();
	calcularPosicionVista();
	view = glm::inverse(view);
	return view;
}

void TCamera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
	GLfloat velocity = movementSpeed * deltaTime;
	glm::vec3 result;
	if (inputEnable) {
		if (direction == FORWARD) {
				result = direccion * velocity;
				updatePosition(Vec3<float>(result.x, result.y, result.z));
			}
		if (direction == BACKWARD) {
			result = direccion * -velocity;
			updatePosition(Vec3<float>(result.x, result.y, result.z));
		}

		if (direction == LEFT) {
			result = derecha * -velocity;
			updatePosition(Vec3<float>(result.x, result.y, result.z));
		}

		if (direction == RIGHT) {
			result = derecha * velocity;
			updatePosition(Vec3<float>(result.x, result.y, result.z));
		}
	}
	
}

void TCamera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset) {
	if (inputEnable) {
		xoffset *= mouseSensitivity;
		yoffset *= mouseSensitivity;

		rotY -= xoffset;
		rotX += yoffset;

		if (rotX > 89.9f)	  
			rotX = 89.9f;	  
		if (rotX < -89.9f)  
			rotX = -89.9f;
	

		
		transRotacion->resetMatrix();
		transRotacion->setRotationY(rotY);
		transRotacion->setRotationX(rotX);
		updateCameraVectors();
		
	}
	
}

void TCamera::ProcessMouseScroll(GLfloat yoffset) {
	if (inputEnable) {
		if (zoom >= 1.0f && zoom <= 45.0f)
			zoom -= yoffset;
		if (zoom <= 1.0f)
			zoom = 1.0f;
		if (zoom >= 45.0f)
			zoom = 45.0f;
	}

	
	
}

void TCamera::calcularPosicionVista()
{

	glm::mat4 tras = transTraslacion->getMatrix() ;
	glm::mat4 rotmatrix = transRotacion->getMatrix();
	view = tras * rotmatrix;
}

void TCamera::setTarget(const Vec3<float>& target) {
	direccion = glm::vec3(target.getX(),target.getY(),target.getZ());
	direccion = glm::normalize(direccion);
	setRotationDir(Vec3<float>(direccion.x,direccion.y,direccion.z));
}

Vec3<float> TCamera::getTarget() {
	Vec3<float> dir = Vec3<float>(direccion.x, direccion.y, direccion.z);
	//return dir * 1000;

	return dir /*+ transTraslacion->getPosition()*/;

}

void TCamera::setRotationDir(Vec3<float>& vecDir)
{
	glm::mat4 m_matrix = glm::mat4();
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

	transTraslacion->loadMatrix(m_matrix);
}

void TCamera::aumentarMira(float z)
{
	//38.0f
	zoom = z;
	movementSpeed = (GLfloat)SPEED*0.3f;
	mouseSensitivity = (GLfloat)SENSITIVTY*0.4f;
	setPerspective(zoom, 1280.0f ,720.0f, nearPlane, farPlane);
}

void TCamera::resetMira()
{
	zoom = ZOOM;
	movementSpeed = SPEED;
	mouseSensitivity = SENSITIVTY;
	setPerspective(zoom, 1280.0f, 720.0f, nearPlane, farPlane);
}





void TCamera::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}

void TCamera::beginDraw() {

}

void TCamera::beginDrawSombras()
{
}

void TCamera::endDraw() {
}

void TCamera::setPosition(Vec3<float> pos)
{
	transTraslacion->setPosition(pos);
}

void TCamera::updatePosition(Vec3<float> pos) {
	transTraslacion->updatePosition(pos);
}

void TCamera::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TCamera::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TCamera::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}
glm::vec3 TCamera::getPositionglm() {
	return glm::vec3(transTraslacion->getPosition().getX(), transTraslacion->getPosition().getY(), transTraslacion->getPosition().getZ());
}

Vec3<float> TCamera::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TCamera::getRotation() {
	return transRotacion->getRotation();
}

void TCamera::updateCameraVectors() {

	glm::vec4 destino = glm::vec4(0, 0, -1, 1);
	glm::mat4 rot = transRotacion->getMatrix();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	direccion = glm::vec3(destino.x, destino.y, destino.z);
	derecha = glm::cross(direccion, worldUp);
	derecha = glm::normalize(derecha);

}

void TCamera::setNearPlane(float near) {
	nearPlane = near;
}

void TCamera::setFarPlane(float far) {
	farPlane = far;
}

void TCamera::setPerspective(float fov, float screenwidth, float screeheight, float nearplane, float farplane)
{
	projection = glm::perspective(fov, screenwidth / screeheight, nearplane, farplane);
}

glm::mat4 TCamera::getProjectionMatrix()
{
	return projection;
}
