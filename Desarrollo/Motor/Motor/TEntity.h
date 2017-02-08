#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
class TEntity {
public:
	TEntity();
	virtual ~TEntity();

	virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual)=0;
	virtual void endDraw(glm::mat4& matrizActual)=0;

};

