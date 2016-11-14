#pragma once
#include "TEntity.h"
#include <algorithm>
#include <vector>
#include <iterator>
class TNode
{
public:
	TNode();
	~TNode();
	
	void setEntity(TEntity* ent);

	TEntity* getEntity();

	TNode* getParentNode();

	int removeChild(TNode *child);
	void addChild(TNode* child);

	void draw();
	
private:
	TEntity *m_entity;
	std::vector<TNode*> m_childNodes;
	TNode *m_parentNode;
};

