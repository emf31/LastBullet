#pragma once
#include "TEntity.h"
class TCamera : public TEntity {
public:
	TCamera();
	~TCamera();
	virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	virtual void endDraw(glm::mat4& matrizActual);
};

