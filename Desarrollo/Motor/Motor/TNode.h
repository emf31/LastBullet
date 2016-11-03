#pragma once
#include <vector>
class TNode
{
public:
	TNode();
	~TNode();
	int addChild(TNode* child) {
		m_childNodes.push_back(child);
	}

	int removeChild(TNode *child) {
		
	}

	void setEntity(TEntity* ent) {
		m_entity = ent;
	}

	TEntity* getEntity() {
		return m_entity;
	}

	TNode* getParentNode() {
		return m_parentNode;
	}

	void draw();
private:
	TEntity *m_entity;
	std::vector<TNode*> m_childNodes;
	TNode *m_parentNode;
};

