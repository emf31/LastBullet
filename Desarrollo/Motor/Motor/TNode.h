#pragma once
#include "TModel.h"
#include "vec3.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
class TNode
{
public:
	TNode();
	~TNode();
	
	void setModel(TModel* model);

	TModel* getModel();

	TNode* getParentNode();

	bool removeChild(TNode *child);
	void addChild(TNode* child);

	virtual void beginDraw(glm::mat4 projection, glm::mat4 view);
	virtual void endDraw();

	void setScale(Vec3<float> scale);
	void setPosition(Vec3<float> position);
	void rotate(Vec3<float> rotation);
	
	//SceneManager *sceneManager_ptr;
private:
	TModel *m_model;
	TNode *m_parentNode;
	std::vector<TNode*> m_childNodes;
	
	glm::vec3 scale;
	glm::vec3 position;
	
};

