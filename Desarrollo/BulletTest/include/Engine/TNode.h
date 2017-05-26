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

	void draw();
	void drawSombras();
	TEntity* getEntity();
	void setEntity(TEntity* entidad);
	int getMyNodeEntityID();

	std::vector<TNode*>& getChildNodes() { return m_childNodes; }

private:
	TEntity *m_entity;
	TNode *m_parentNode;
	std::vector<TNode*> m_childNodes;
	int myNodeEntityID;
	bool visible;
	SceneManager& sm;
	

};

