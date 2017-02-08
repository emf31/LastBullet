#pragma once
#include "TModel.h"
#include "vec3.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include "enum.h"


class TNode
{
public:
	TNode(TNode* nodoPadre=nullptr);
	~TNode();
	
	void setModel(TModel* model);

	TModel* getModel();

	TNode* getParentNode();

	void setParentNode(TNode* nodoPadre) {
		m_parentNode = nodoPadre;
	}

	bool removeChild(TNode *child);
	void addChild(TNode* child);
	//TODOOO antes estaba asi, pero creo que los nodos no tienen begin draw y end draw, solo tienen un draw, que ya llama al begin y end draw de las entities asociadas
	/*virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4 model);
	virtual void endDraw();
	*/
	void draw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	TEntity* getEntity() {
		return m_entity;
	}
	void setEntity(TEntity* entidad) {
		m_entity = entidad;
	}
	
	T_Nodos getNodeType() {
		return type;
	}
	T_Nodos getType() {
		return type;
	}
	void setType(T_Nodos tipo) {
		type = tipo;
	}

	//SceneManager *sceneManager_ptr;
	

private:
	//TModel *m_model;
	TEntity *m_entity;
	TNode *m_parentNode;
	std::vector<TNode*> m_childNodes;
	
	
	
	//glm::vec3 scale;
	//glm::vec3 position;
	//glm::vec3 rotation;
	T_Nodos type;
	
};

