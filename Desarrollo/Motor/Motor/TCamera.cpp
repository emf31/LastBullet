#include "TCamera.h"
#include "SceneManager.h"



// Constructor with vectors

TCamera::TCamera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM) {

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//this->Position = position;
	//setPosition(Vec3<float>(position.x, position.y, position.z));
	this->WorldUp = up;
	this->Yaw = yaw;
	this->Pitch = pitch;
	this->updateCameraVectors();
}

// Constructor with scalar values

TCamera::TCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM) {
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//this->Position = glm::vec3(posX, posY, posZ);
	//setPosition(Vec3<float>(posX, posY, posZ));
	this->WorldUp = glm::vec3(upX, upY, upZ);
	this->Yaw = yaw;
	this->Pitch = pitch;
	this->updateCameraVectors();
}

TCamera::~TCamera() {
}


glm::mat4 TCamera::GetViewMatrix() {
	return glm::lookAt(getPositionglm(), getPositionglm() + this->Front, this->Up);
}

void TCamera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
	GLfloat velocity = this->MovementSpeed * deltaTime;
	glm::vec3 result;
	if (direction == FORWARD) {
		result = Front * velocity;
		setPosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position += this->Front * velocity;
	}
	if (direction == BACKWARD) {
		result = Front * -velocity;
		setPosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position -= this->Front * velocity;
	}

	if (direction == LEFT) {
		result = Right * -velocity;
		setPosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position -= this->Right * velocity;
	}

	if (direction == RIGHT) {
		result = Right * velocity;
		setPosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position += this->Right * velocity;
	}

}

void TCamera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch) {
	xoffset *= this->MouseSensitivity;
	yoffset *= this->MouseSensitivity;

	this->Yaw += xoffset;
	this->Pitch += yoffset;

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch) {
		if (this->Pitch > 89.0f)
			this->Pitch = 89.0f;
		if (this->Pitch < -89.0f)
			this->Pitch = -89.0f;
	}

	// Update Front, Right and Up Vectors using the updated Eular angles
	this->updateCameraVectors();
}

void TCamera::ProcessMouseScroll(GLfloat yoffset) {
	if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
		this->Zoom -= yoffset;
	if (this->Zoom <= 1.0f)
		this->Zoom = 1.0f;
	if (this->Zoom >= 45.0f)
		this->Zoom = 45.0f;
}



void TCamera::beginDraw() {
}

void TCamera::endDraw() {
}

void TCamera::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
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
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	front.y = sin(glm::radians(this->Pitch));
	front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	this->Front = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}