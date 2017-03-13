#include "TSunLight.h"

TSunLight::TSunLight(Vec3<float> direccion)
{
	m_direccion = direccion;
}

TSunLight::~TSunLight()
{
}

void TSunLight::pasarDatosAlShader(Shader * shader, int i)
{
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.ambiente"),ambiente.getX(), ambiente.getY(), ambiente.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.difusa"), difusa.getX(), difusa.getY(), difusa.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.especular"), especular.getX(), especular.getY(), especular.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, "sunlight.direction"), m_direccion.getX(), m_direccion.getY(), m_direccion.getZ());
}

void TSunLight::setDirection(Vec3<float> dir)
{
	m_direccion = dir;
	transRotacion->setRotationDirection(dir);
}

Vec3<float> TSunLight::getDireccion()
{
	return m_direccion;
}
