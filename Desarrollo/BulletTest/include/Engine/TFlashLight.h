#pragma once
#include "TLuz.h"
#include "vec3.hpp"

class TFlashLight : public TLuz {

public:
	TFlashLight(Vec3<float> pos, Vec3<float> direccion, float radioIn = 12.0f, float radioEx=17.0f);
	~TFlashLight();

	void pasarDatosAlShader(Shader *shader, int i = 0);
	
	Vec3<float> getPosition();
	Vec3<float> getDireccion();
	float getRadioInterior();
	float getRadioExterior();

	void setPosition(Vec3<float> pos);
	void setDirection(Vec3<float> dir);
	void setRadioInterior(float radio);
	void setRadioExterior(float radio);
	void updateVectorDireccion();
	

private:
	Vec3<float> m_posicion;
	Vec3<float> m_direccion;
	float m_radioInterior;
	float m_radioExterior;

};