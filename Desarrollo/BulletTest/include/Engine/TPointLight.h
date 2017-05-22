#pragma once
#include "TLuz.h"
#include "vec3.hpp"

class TPointLight : public TLuz {

public:
	TPointLight(Vec3<float> posicion, float radioIn = 6.3f, float radioEx = 10.3f);
	~TPointLight();

	//Llamar a esto desencadena que todos los hijos de este TPointLight se borren
	virtual void removeEntity() override;

	void pasarDatosAlShader(Shader *shader, int i = 0);
	void setPosition(Vec3<float> pos);
	Vec3<float> getPosition();

private:
	Vec3<float> m_posicion;
	float m_radioInterior;
	float m_radioExterior;

};