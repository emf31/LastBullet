#pragma once
#include "TEntity.h"
class TSpotLight : public TEntity {
public:
	TSpotLight();
	~TSpotLight();
	void setColor(int r, int g, int b, int a);
	void setColor(int r, int g, int b);

	void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	void endDraw(glm::mat4& matrizActual);
	int m_r, m_g, m_b, m_a;
};

