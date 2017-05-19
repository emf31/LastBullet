#pragma once
#include "TLuz.h"
#include "vec3.hpp"

class TSunLight : public TLuz {

public:
	//TSunLight(Vec3<float> lightColor = Vec3<float>(1.0f,1.0f,1.0f), float intAmbiente = 0.1, float intDifusa = 0.5 , float intEspecular = 1.0f);
	TSunLight(Vec3<float> direccion);
	~TSunLight();

	void pasarDatosAlShader(Shader *shader, int i=0);
	Vec3<float> getDireccion();
	void setRotationXYZ(Vec3<float> dir);
	void updateVectorDireccion();
	glm::mat4 getLightProjection();
	glm::mat4 getLightView();
	glm::mat4 getLightSpaceMatrix();
	void calcularMatrices();
	//metodos para las pruebas de sombras
	void setPosition(Vec3<float> pos);
	void setVectorDireccion(Vec3<float> dir);

private:
	Vec3<float> m_direccion;
	Vec3<float> m_position;
	glm::mat4 lightProjection, lightView;
	glm::mat4 lightSpaceMatrix;

};