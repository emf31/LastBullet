#pragma once
#include "TEntity.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "TTransform.h"
class TLuz : public TEntity {
	friend class SceneManager;
public:
	TLuz();
	virtual ~TLuz();
	void beginDraw();
	void beginDrawSombras();
	void endDraw();
	virtual void pasarDatosAlShader(Shader *shader, int i=0) = 0;

	
	void setColorAlpha(float r, float g, float b, float a);
	void setColor(float r, float g, float b);
	float getR();
	float getG();
	float getB();
	void setIntensidadAmbiente(float intensidad);
	void setIntensidadDifusa(float intensidad);
	void setIntensidadEspecular(float intensidad);
	


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


private:
	SceneManager &sm;
};

