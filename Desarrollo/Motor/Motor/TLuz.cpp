#include "TLuz.h"
#include "SceneManager.h"




TLuz::TLuz() : sm(SceneManager::i()) {

	
	gradoLuzAmbiente = 0.1f;
	gradoLuzDifusa = 0.5f;
	gradoLuzEspecular = 1.0f;
	setColor(1.0f, 1.0f, 1.0f);
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
}


TLuz::~TLuz() {
}

void TLuz::setColorAlpha(float r, float g, float b, float a) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void TLuz::setColor(float r, float g, float b) {
	m_r = r;
	m_g = g;
	m_b = b;
	ambiente = Vec3<float>(r, g, b) * gradoLuzAmbiente;
	difusa = Vec3<float>(r, g, b) * gradoLuzDifusa;
	especular = Vec3<float>(r, g, b) * gradoLuzEspecular;
}

float TLuz::getR()
{
	return m_r;
}

float TLuz::getG()
{
	return m_g;
}

float TLuz::getB()
{
	return m_b;
}

void TLuz::setIntensidadAmbiente(float intensidad)
{
	gradoLuzAmbiente = intensidad;
	ambiente = Vec3<float>(m_r, m_g, m_b) * gradoLuzAmbiente;
	
}

void TLuz::setIntensidadDifusa(float intensidad)
{
	gradoLuzDifusa = intensidad;
	difusa = Vec3<float>(m_r, m_g, m_b) * gradoLuzDifusa;
	
}

void TLuz::setIntensidadEspecular(float intensidad)
{
	gradoLuzEspecular = intensidad;
	especular = Vec3<float>(m_r, m_g, m_b) * gradoLuzEspecular;
}

Vec3<float> TLuz::getColor() {
	return Vec3<float>(m_r, m_g, m_b);
}

void TLuz::beginDraw() {
}

void TLuz::beginDrawSombras()
{
}

void TLuz::endDraw() {
}

Vec3<float> TLuz::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TLuz::getPosition()
{
	return transTraslacion->getPosition();
}




