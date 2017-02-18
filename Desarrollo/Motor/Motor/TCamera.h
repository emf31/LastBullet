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


	void setPosition(Vec3<float> pos);
	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);
	Vec3<float> getRotation();
	Vec3<float> getPosition();






	// Camera Attributes
	//glm::vec3 Position;
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

	// Constructor with vectors
	TCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
	// Constructor with scalar values
	TCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);

	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix() {
		return glm::lookAt(getPositionglm(), getPositionglm() + this->Front, this->Up);
	}
	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
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

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true) {
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

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(GLfloat yoffset) {
		if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
			this->Zoom -= yoffset;
		if (this->Zoom <= 1.0f)
			this->Zoom = 1.0f;
		if (this->Zoom >= 45.0f)
			this->Zoom = 45.0f;
	}


private:



	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionTraslacion(TTransform* tras);
	glm::vec3 getPositionglm() {
		return glm::vec3 (transTraslacion->getPosition().getX(), transTraslacion->getPosition().getY(), transTraslacion->getPosition().getZ());
	}

	TTransform* transRotacion;
	TTransform* transTraslacion;




	// Calculates the front vector from the Camera's (updated) Eular Angles
	void updateCameraVectors() {
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



};

