#pragma once
#include "vec3.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include "TEntity.h"

class SceneManager;


class TNode
{
public:
	TNode(int entityID, TNode* nodoPadre = nullptr);
	~TNode();
	

	TNode* getParentNode();

	void setParentNode(TNode* nodoPadre);
	bool removeChild(TNode *child);
	void removeNode();
	void addChild(TNode* child);
	void addChild(TEntity* ent);
	void setVisible(bool b) { visible = b; }
	bool isVisible() const { return visible; }
	

	//TODOOO antes estaba asi, pero creo que los nodos no tienen begin draw y end draw, solo tienen un draw, que ya llama al begin y end draw de las entities asociadas
	/*virtual void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4 model);
	virtual void endDraw();
	*/
	void draw();
	TEntity* getEntity();
	void setEntity(TEntity* entidad);
	int getMyNodeEntityID();

private:
	TEntity *m_entity;
	TNode *m_parentNode;
	std::vector<TNode*> m_childNodes;
	int myNodeEntityID;
	bool visible;
	SceneManager& sm;
	

};

