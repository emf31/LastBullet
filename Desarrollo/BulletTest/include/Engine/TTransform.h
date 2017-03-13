#pragma once
#include "TEntity.h"
#include "vec3.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "TNode.h"

#define M_PI 3.1415926535897932384626433832795
class TTransform : public TEntity {
public:

	TTransform();
	~TTransform();

	void transpose();
	void invert();

	void setPosition(Vec3<float> position);
	void updatePosition(Vec3<float> position);
	void setScale(Vec3<float> scale);

	void setRotationDirection(Vec3<float> vecDir);
	void setRotationRadians(Vec3<float> rotation);
	void setRotationDegrees(Vec3<float> rotation);

	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);


	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

	glm::mat4 getRotationMatrix();
	glm::mat4 getPositionMatrix();
	glm::mat4 getScaleMatrix();

	void multiply(glm::mat4 mat);
	void multiply(glm::vec4 vec);
	void loadMatrix(glm::mat4 mat);

	

	virtual void beginDraw();
	virtual void endDraw();


private: 

	SceneManager &sm;

	glm::mat4 m_matrix;
	Vec3<float> m_rotation;
	glm::vec3 m_rotation2;
	Vec3<float> m_position;
	Vec3<float> m_scale;
	TNode *miNodo;
	float angulo;
	
	
};

