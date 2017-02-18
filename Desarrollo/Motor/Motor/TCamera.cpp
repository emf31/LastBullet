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

Vec3<float> TCamera::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TCamera::getPosition()
{
	return transTraslacion->getPosition();
}

