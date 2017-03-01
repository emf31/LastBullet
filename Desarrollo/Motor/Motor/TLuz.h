#pragma once
#include "TEntity.h"
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include "TTransform.h"
class TLuz : public TEntity {
	friend class SceneManager;
public:
	TLuz();
	virtual ~TLuz();
	void beginDraw();
	void endDraw();
	virtual void pasarDatosAlShader(Shader *shader, int i=0) = 0;

	void setLight();
	void setColorAlpha(float r, float g, float b, float a);
	void setColor(float r, float g, float b);
	float getR();
	float getG();
	float getB();
	void setIntensidadAmbiente(float intensidad);
	void setIntensidadDifusa(float intensidad);
	void setIntensidadEspecular(float intensidad);
	


	void setPosition(Vec3<float> pos);
	void setRotationX(float angu);
	void setRotationY(float angu);
	void setRotationZ(float angu);
	void setRotation(Vec3<float> dir);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getColor();

protected:

	Vec3<float> ambiente;
	Vec3<float> difusa;
	Vec3<float> especular;

	float m_r, m_g, m_b, m_a;
	float gradoLuzAmbiente;
	float gradoLuzDifusa;
	float gradoLuzEspecular;
	TTransform* transRotacion;
	TTransform* transTraslacion;

private:


	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionTraslacion(TTransform* tras);


	Shader* shaderLuz;
	GLuint lightVAO;
	GLuint lightVBO;




};

