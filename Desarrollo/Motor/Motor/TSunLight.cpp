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


void TSunLight::setRotationXYZ(Vec3<float> dir)
{
	transRotacion->resetMatrix();
	transRotacion->setRotationY(dir.getY());
	transRotacion->setRotationX(dir.getX() - 90.0f);
	transRotacion->setRotationZ(dir.getZ());

	updateVectorDireccion();
}

Vec3<float> TSunLight::getDireccion()
{
	return m_direccion;
}

void TSunLight::updateVectorDireccion()
{
	glm::vec4 destino = glm::vec4(0, 0, 1, 1);
	glm::mat4 rot = transRotacion->getRotationMatrix();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	m_direccion = Vec3<float>(destino.x, destino.y, destino.z);

}