#pragma once
#include "TEntity.h"
#include "vec3.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
class TTraslacion : public TEntity {
public:

	TTraslacion();
	~TTraslacion();

	void transpose();
	void invert();

	/*
	void translate(float x, float y, float z);
	void rotate(float f1, float f2, float f3, float angle);
	void scale(float s1, float s2, float s3);
	*/

	void setPosition(Vec3<float> position);
	Vec3<float> getPosition();

	void multiply(glm::mat4 mat);
	void multiply(glm::vec4 vec);
	void loadMatrix(glm::mat4 mat);



	virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	virtual void endDraw(glm::mat4& matrizActual);

private:
	
	glm::vec3 m_position;
	glm::mat4 m_matrix;

};

