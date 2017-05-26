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

	virtual void removeEntity() override;

	virtual void beginDraw();
	virtual void beginDrawSombras();
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

	void calcularPosicionVista();

	Vec3<float> getVectorDireccion() const { return Vec3<float>(direccion.x, direccion.y, direccion.z); }

	void setTarget(const Vec3<float>& target);
	
	Vec3<float> getTarget();
	void setRotationDir(Vec3<float>& dir);

	void setInputEnable(bool b) { inputEnable = b; }

	void aumentarMira(float z);
	void resetMira();


	//projection
	void setNearPlane(float near);

	void setFarPlane(float far);

	void setPerspective(float fov, float screenwidth, float screeheight, float nearplane, float farplane);

	glm::mat4 getProjectionMatrix();

private:
	bool inputEnable;

	glm::vec3 getPositionglm();
	void updateCameraVectors();


	glm::mat4 view;
	glm::mat4 vista;
	glm::mat4 projection;
	glm::vec3 direccion;
	glm::vec3 derecha;
	glm::vec3 worldUp;
	float rotX = 0.0f;
	float rotY = 0.0f;

	// Camera options
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	GLfloat zoom;
	float nearPlane = 0.1f, farPlane = 100.0f;




};

