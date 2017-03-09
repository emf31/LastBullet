#pragma once
#include "TLuz.h"
#include "vec3.hpp"

class TPointLight : public TLuz {

public:
	TPointLight(Vec3<float> posicion);
	~TPointLight();

	void pasarDatosAlShader(Shader *shader, int i = 0);
	void setPosition(Vec3<float> pos);
	Vec3<float> getPosition();

private:
	Vec3<float> m_posicion;

};