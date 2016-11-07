#pragma once
#include <glm/glm.hpp>
class TEntity {
public:
	TEntity();
	~TEntity();

	virtual void beginDraw();
	virtual void endDraw();

	glm::vec3 position;
	glm::vec3 scale;
};

