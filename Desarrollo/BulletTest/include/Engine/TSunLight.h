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
	void calcularMatrices() {
		GLfloat z = 45.0f;
		//ortografica
		//lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -1000.0f, 1000.0f);
		lightView = glm::lookAt(glm::vec3(90.0f, 5.0f, 90.0f), glm::vec3(0, 0, 0), glm::vec3(0.0, 1.0, 0.0));
		lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -1000.0f, 1000.0f);
		//perspectiva
		//lightProjection = glm::perspective(z, (float)1280 / (float)720, 1.0f, 1000.0f);
		//lightView = glm::lookAt(glm::vec3(-20.0f,5.0f, -5.0f), glm::vec3(0,0, 0), glm::vec3(0.0, 1.0, 0.0));
		lightSpaceMatrix = lightProjection * lightView;
	}
	

	//metodos para las pruebas de sombras
	void setPosition(Vec3<float> pos) {
		m_position = pos;
	}
	void setVectorDireccion(Vec3<float> dir) {
		m_direccion = dir;
	}

private:
	Vec3<float> m_direccion;
	Vec3<float> m_position;
	glm::mat4 lightProjection, lightView;
	glm::mat4 lightSpaceMatrix;

};