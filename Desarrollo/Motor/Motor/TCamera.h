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
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.05f;
const GLfloat ZOOM = 45.0f;


class TCamera : public TEntity {
	friend class SceneManager;
public:
	~TCamera();
	virtual void beginDraw();
	virtual void endDraw();

	void setPosition(Vec3<float> pos);
	void updatePosition(Vec3<float> pos);
	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);
	Vec3<float> getRotation();
	Vec3<float> getPosition();

	TCamera();
	glm::mat4 GetViewMatrix();
	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset);
	void ProcessMouseScroll(GLfloat yoffset);

	glm::vec3 calcularPosicionVista();

	Vec3<float> getVectorDireccion() const { return Vec3<float>(direccion.x, direccion.y, direccion.z); }

	void setTarget(const Vec3<float>& target);
	
	Vec3<float> getTarget();

	void setRotationDir(const Vec3<float>& dir);

	void setInputEnable(bool b) { inputEnable = b; }


private:
	bool inputEnable;

	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionTraslacion(TTransform* tras);
	glm::vec3 getPositionglm();
	void updateCameraVectors();


	TTransform* transRotacion;
	TTransform* transTraslacion;

	glm::mat4 view;
	glm::mat4 vista;
	glm::vec3 direccion;
	glm::vec3 derecha;
	glm::vec3 worldUp;
	float rotX = 0.0f;
	float rotY = 0.0f;

	// Camera options
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	GLfloat zoom;



};

