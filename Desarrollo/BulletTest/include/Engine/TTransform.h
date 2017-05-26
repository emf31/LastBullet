#pragma once
#include "TEntity.h"
#include "vec3.hpp"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include "TNode.h"

static const float PI_MOTOR = 3.1415926535897932384626433832795f;
class TTransform : public TEntity {
public:

	
	TTransform();
	~TTransform();

	//No hace nada porque no trabajamos desde fuera con transformaciones
	virtual void removeEntity() override { }

	void transpose();
	void invert();

	void setPosition(Vec3<float> position);
	void updatePosition(Vec3<float> position);

	void setScale(Vec3<float> scale);

	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);

	void resetMatrix();


	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

	glm::mat4 getMatrix();

	void multiply(glm::mat4 mat);
	void loadMatrix(glm::mat4 mat);

	

	virtual void beginDraw();
	virtual void beginDrawSombras();
	virtual void endDraw();


private: 

	SceneManager &sm;
	glm::mat4 m_matrix;
	Vec3<float> m_rotation;
	Vec3<float> m_position;
	Vec3<float> m_scale;
};

