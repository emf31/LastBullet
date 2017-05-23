#include "TFlashLight.h"

TFlashLight::TFlashLight(Vec3<float> pos, Vec3<float> direccion, float radioIn, float radioEx)
{
	
	m_posicion = pos;
	m_direccion = direccion;
	m_radioInterior = radioIn;
	m_radioExterior = radioEx;
}

TFlashLight::~TFlashLight()
{
}

void TFlashLight::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}

void TFlashLight::pasarDatosAlShader(Shader * shader, int i)
{
	glUniform3f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].ambiente").c_str()), ambiente.getX(), ambiente.getY(), ambiente.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].difusa").c_str()), difusa.getX(), difusa.getY(), difusa.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].especular").c_str()), especular.getX(), especular.getY(), especular.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].position").c_str()), m_posicion.getX(), m_posicion.getY(), m_posicion.getZ());
	glUniform3f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].direction").c_str()), m_direccion.getX(), m_direccion.getY(), m_direccion.getZ());
	glUniform1f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].radioInterior").c_str()), glm::cos(glm::radians(m_radioInterior)));
	glUniform1f(glGetUniformLocation(shader->Program, std::string("flashlight[" + std::to_string(i) + "].radioExterior").c_str()), glm::cos(glm::radians(m_radioExterior)));
}

void TFlashLight::setPosition(Vec3<float> pos)
{
	m_posicion = pos;
	transTraslacion->setPosition(pos);
}

Vec3<float> TFlashLight::getPosition()
{
	return m_posicion;
}

void TFlashLight::setRotationXYZ(Vec3<float> dir)
{
	//nos pasan un vector de rotacion por ejemplo (30,45,60) que seria 
	//rotar 30º en X, 45º en Y y 60º en Z
	//primero reseteamos la matriz de rotacion para que no se acumule
	// esta rotacion nueva a la anterior que ya tenia
	//luego llamamos a los metodos de rotacion en cada eje (los 3 son 
	//iguales ahora) el -90 era por las diferencias en los sistemas 
	//de coordenadas.
	transRotacion->resetMatrix();
	transRotacion->setRotationY(dir.getY());
	transRotacion->setRotationX(dir.getX() - 90.0f);
	transRotacion->setRotationZ(dir.getZ());

	//en este punto ya tenemos la matriz de rotacion actual, ahora una 
	//vez que tenemos esta matriz con la rotacion buena calculamos el 
	//vector direccion a partir de esta matriz que este vector direccion
	//es el que nos sirve para pasarle al shader
	updateVectorDireccion();
}

void TFlashLight::setRadioInterior(float radio)
{
	m_radioInterior = radio;
}

void TFlashLight::setRadioExterior(float radio)
{
	m_radioExterior = radio;
}

void TFlashLight::updateVectorDireccion()
{
	//en este metodo calculamos el vector de direccion a partir de
	//nuestra matriz de rotacion
	glm::vec4 destino = glm::vec4(0, 0, 1, 1);
	//matriz de rotacion actual modificada con los setRotation anteriores
	glm::mat4 rot = transRotacion->getMatrix();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	//nos guardamos el vector direccion en una variable para no tener que
	//calcularla en cada frame y asi enviamos esta al shader cada vez que
	//se dibuja
	m_direccion = Vec3<float>(destino.x, destino.y, destino.z);

}

Vec3<float> TFlashLight::getDireccion()
{
	return m_direccion;
}

float TFlashLight::getRadioInterior()
{
	return m_radioInterior;
}

float TFlashLight::getRadioExterior()
{
	return m_radioExterior;
}
