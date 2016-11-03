#pragma once

class TNode
{
public:
	TNode();
	~TNode();
	void addChild(TNode* child);

	int removeChild(TNode *child);

	void setEntity(TEntity* ent);

	TEntity* getEntity();

	TNode* getParentNode();

	void draw();
private:
	TEntity *m_entity;
	std::vector<TNode*> m_childNodes;
	TNode *m_parentNode;
};

