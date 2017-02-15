#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
class TEntity {
public:
	TEntity();
	virtual ~TEntity();

	virtual void beginDraw()=0;
	virtual void endDraw()=0;

};

