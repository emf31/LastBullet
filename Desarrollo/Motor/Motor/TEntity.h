#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
class TEntity {
public:
	TEntity();
	~TEntity();

	virtual void beginDraw()=0;
	virtual void endDraw()=0;

	glm::vec3 position;
	glm::vec3 scale;
};

