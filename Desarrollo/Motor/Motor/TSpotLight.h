#pragma once
#include "TEntity.h"
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include "TTransform.h"
class TSpotLight : public TEntity {
	friend class SceneManager;
public:
	TSpotLight();
	~TSpotLight();
	void setColor(int r, int g, int b, int a);
	void setColor(int r, int g, int b);
	void setLight();
	void pruebaColores() {

	}

	void beginDraw();
	void endDraw();
	int m_r, m_g, m_b, m_a;



	void setPosition(Vec3<float> pos);
	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);
	void setScale(Vec3<float> esc);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

private:


	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);








	Shader* shaderLuz;
	GLuint lightVAO;
	GLuint lightVBO;
	
	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
	
	
};

