#pragma once
#include "TEntity.h"
class TCamera : public TEntity {
public:
	TCamera();
	~TCamera();
	virtual void beginDraw();
	virtual void endDraw();
};

