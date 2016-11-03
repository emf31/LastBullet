#pragma once
#include "TEntity.h"
class TSpotLight : public TEntity {
public:
	TSpotLight();
	~TSpotLight();
	void setColor(int r, int g, int b, int a);
	void setColor(int r, int g, int b);

	void beginDraw();
	void endDraw();
	int m_r, m_g, m_b, m_a;
};

