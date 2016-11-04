#pragma once
#include "TEntity.h"
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

	void translate(float x, float y, float z);
	void rotate(float f1, float f2, float f3, float angle);
	void scale(float s1, float s2, float s3);
	

	void multiply(glm::mat4 mat);
	void multiply(glm::vec4 vec);

	glm::mat4 m_matrix;
	
};

