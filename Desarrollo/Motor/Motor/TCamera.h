#pragma once
#include "TEntity.h"
#include "TTransform.h"
class TCamera : public TEntity {
public:
	TCamera();
	~TCamera();
	virtual void beginDraw();
	virtual void endDraw();
};

