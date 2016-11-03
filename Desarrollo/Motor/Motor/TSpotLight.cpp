#include "TSpotLight.h"



TSpotLight::TSpotLight() {
}


TSpotLight::~TSpotLight() {
}

void TSpotLight::setColor(int r, int g, int b, int a) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void TSpotLight::setColor(int r, int g, int b) {
	m_r = r;
	m_g = g;
	m_b = b;
}

void TSpotLight::beginDraw() {
}

void TSpotLight::endDraw() {
}
