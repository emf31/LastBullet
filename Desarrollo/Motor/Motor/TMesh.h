#pragma once
#include "TEntity.h"
class TMesh : public TEntity {
public:
	TMesh();
	~TMesh();

	void loadMesh();

	void beginDraw();
	void endDraw();
};

