#pragma once
#include "vec3.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include "enum.h"
#include "TEntity.h"


class TNode
{
	friend class SceneManager;
public:
	TNode(int entityID, TNode* nodoPadre=nullptr);
	~TNode();
	

	TNode* getParentNode();

	void setParentNode(TNode* nodoPadre);
	bool removeChild(TNode *child);
	void addChild(TNode* child);
	


	//TODOOO antes estaba asi, pero creo que los nodos no tienen begin draw y end draw, solo tienen un draw, que ya llama al begin y end draw de las entities asociadas
	/*virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4 model);
	virtual void endDraw();
	*/
	void draw();
	TEntity* getEntity();
	void setEntity(TEntity* entidad);
	T_Nodos getNodeType();
	T_Nodos getType();
	void setType(T_Nodos tipo);
	int getMyNodeEntityID();

private:
	TEntity *m_entity;
	TNode *m_parentNode;
	std::vector<TNode*> m_childNodes;
	int myNodeEntityID;
	
	
	
	//glm::vec3 scale;
	//glm::vec3 position;
	//glm::vec3 rotation;
	T_Nodos type;
	
};

