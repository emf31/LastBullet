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
	virtual void beginDrawSombras()=0;
	virtual void endDraw()=0;
	void addChild(TEntity* ent);
	/*void addParent(TNode* node){
		TNode* nuevoHijo = node;
		TNode* padre = node->getParentNode();

		while (padre->getParentNode() != nullptr && padre->getMyNodeEntityID() != entityID) {
			//haciendo esta asignacion si luego cambio padre tambien se cambia nuevoHijo? al ser un puntero que apunta a otro puntero
			nuevoHijo = nuevoHijo->getParentNode();
			padre = padre->getParentNode();
		}
		
	}
	*/
	void removeNode();
	void removeChild(TEntity* ent);


	void setVisible(bool b);
	bool isVisible() const;

	void setMiNodo(TNode * nodo);

	TNode* getMiNodo();
	int getID();

private:
	int entityID = -1;
	TNode * miNodo;

protected:
	
	void setID(int id);

	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);

	
	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
};

