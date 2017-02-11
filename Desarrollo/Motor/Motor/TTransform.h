#pragma once
#include "TEntity.h"
#include "vec3.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
class TTransform : public TEntity {
public:

	TTransform();
	~TTransform();

	void transpose();
	void invert();

	/*
	void translate(float x, float y, float z);
	void rotate(float f1, float f2, float f3, float angle);
	void scale(float s1, float s2, float s3);
	*/

	void setPosition(Vec3<float> position);
	void setScale(Vec3<float> scale);
	void setRotation(Vec3<float> rotation);
	void setRotation2(float angu, Vec3<float> rotation);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

	void multiply(glm::mat4 mat);
	void multiply(glm::vec4 vec);
	void loadMatrix(glm::mat4 mat);

	

	virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	virtual void endDraw(glm::mat4& matrizActual);

private: 
	glm::vec3 m_scale;
	glm::vec3 m_position;
	glm::vec3 m_origen;
	glm::vec3 m_rotation;
	glm::vec3 m_rotation2;
	glm::mat4 m_matrix;
	glm::mat4 m_orientation;
	float angulo;
	
};

