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
}


TCamera::~TCamera() {
	
}


glm::mat4 TCamera::GetViewMatrix() {
	view = glm::mat4();
	calcularPosicionVista();
	view = glm::inverse(view);
	return view;
	//return glm::lookAt(posCamara, posCamara + direccion, glm::vec3(0.0f,1.0f,0.0f));
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
	

		// Update Front, Right and Up Vectors using the updated Eular angles
	
		transRotacion->setRotationY(rotY);
		transRotacion->setRotationX(rotX);
		updateCameraVectors();
		//transRotacion->setRotationDirection(vecFront);
		//std::cout << "El vector rotacion es: " << vecFront.getX() << "," << vecFront.getY() << "," << vecFront.getZ() << "," << std::endl;
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

	glm::mat4 tras = transTraslacion->getPositionMatrix() ;
	glm::mat4 rotmatrix = transRotacion->getRotationMatrix();
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

	return dir + transTraslacion->getPosition();

}

void TCamera::setRotationDir(const Vec3<float>& dir) {
	transRotacion->setRotationDirection(dir);

}



void TCamera::beginDraw() {

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

void TCamera::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TCamera::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
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
	glm::mat4 rot = transRotacion->getRotationMatrix();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	direccion = glm::vec3(destino.x, destino.y, destino.z);
	derecha = glm::cross(direccion, worldUp);
	derecha = glm::normalize(derecha);

}