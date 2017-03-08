#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "enum.h"

class TNode;


class TEntity {
public:
	TEntity();
	virtual ~TEntity();

	virtual void beginDraw()=0;
	virtual void endDraw()=0;
	void addChild(TEntity* ent);

	void removeNode();
	void removeChild(TEntity* ent);

private:
	int entityID = -1;
	TNode * miNodo;
	



protected:
	int getID();
	void setID(int id);
	void setMiNodo(TNode * nodo);
	TNode* getMiNodo();
};

