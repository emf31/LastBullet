#pragma once
#include <glm/glm.hpp>
#include "Shader.h"

class TNode;
class TTransform;


class TEntity {
public:
	TEntity();
	virtual ~TEntity();

	virtual void beginDraw()=0;
	virtual void endDraw()=0;
	void addChild(TEntity* ent);

	void removeNode();
	void removeChild(TEntity* ent);

	void setVisible(bool b);
	bool isVisible() const;

	void setMiNodo(TNode * nodo);
	TNode* getMiNodo();

private:
	int entityID = -1;
	TNode * miNodo;

protected:
	int getID();
	void setID(int id);
	
	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);

	
	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
};

