#include "TPointLight.h"

TPointLight::TPointLight(Vec3<float> posicion)
{
	m_posicion = posicion;
}

TPointLight::~TPointLight()
{
}

void TPointLight::pasarDatosAlShader(Shader * shader, int i)
{

	float radio = 6.3f;

	glUniform3f(glGetUniformLocation(shader->Program, std::string("pointlight[" + std::to_string(i) + "].ambiente").c_str()), ambiente.getX(), ambiente.getY(), ambiente.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("pointlight[" + std::to_string(i) + "].difusa").c_str()), difusa.getX(), difusa.getY(), difusa.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("pointlight[" + std::to_string(i) + "].especular").c_str()), especular.getX(), especular.getY(), especular.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("pointlight[" + std::to_string(i) + "].position").c_str()), m_posicion.getX(), m_posicion.getY(), m_posicion.getZ());
	glUniform1f(glGetUniformLocation(shader->Program, std::string("pointlight[" + std::to_string(i) + "].radio").c_str()), radio);
}

void TPointLight::setPosition(Vec3<float> pos)
{
	m_posicion = pos;
	transTraslacion->setPosition(pos);
}

Vec3<float> TPointLight::getPosition()
{
	return m_posicion;
}
