#pragma once
#include <vector>
// GL Includes
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "TEntity.h"
#include "TTransform.h"

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.1f;
const GLfloat ZOOM = 45.0f;


class TCamera : public TEntity {
	friend class SceneManager;
public:
	~TCamera();
	virtual void beginDraw();
	virtual void endDraw();

	//void setPosition(Vec3<float> pos);
	//void updatePosition(Vec3<float> pos);
	//void setRotationX(float angu);
	//void setRotationY(float angu);
	//void setRotationZ(float angu);
	//Vec3<float> getRotation();
	Vec3<float> getPosition();

	// Constructor with vectors
	TCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
	// Constructor with scalar values
	TCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);
	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();
	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(GLfloat yoffset);

	glm::vec3 calcularPosicionVista();

	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// Eular Angles
	GLfloat Yaw;
	GLfloat Pitch;
	// Camera options
	GLfloat MovementSpeed;
	GLfloat MouseSensitivity;
	GLfloat Zoom;

	Vec3<float> vecFrontCam() {
		return vecFront;
	}
	float rotX = 0.0f;
	float rotY = 0.0f;
private:


	Vec3<float> vecFront;
	//void setTransformacionRotacion(TTransform* rot);
	//void setTransformacionTraslacion(TTransform* tras);
	void setTransformacion(TTransform* trans);
	glm::vec3 getPositionglm();
	// Calculates the front vector from the Camera's (updated) Eular Angles
	void updateCameraVectors();
	glm::mat4 miMatriz;
	//TTransform* transRotacion;
	//TTransform* transTraslacion;
	TTransform* transformacion;



};

