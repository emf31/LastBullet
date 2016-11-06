#include "TNode.h"

TNode::TNode()
{
}


TNode::~TNode()
{
}

void TNode::addChild(TNode * child) {
	m_childNodes.push_back(child);
}

int TNode::removeChild(TNode * child) {
	auto result = std::find(m_childNodes.begin(), m_childNodes.end(), child);

	if (result != m_childNodes.end()) {
		//Esta en la lista -> lo quitamos

		m_childNodes.erase(result);
		return 1;
	} else {
		return 0;
	}
}

void TNode::setEntity(TEntity * ent) {
	m_entity = ent;
}

TEntity * TNode::getEntity() {
	return m_entity;
}

TNode * TNode::getParentNode() {
	return m_parentNode;
}

void TNode::draw() {
	if (m_entity != nullptr) {
		m_entity->beginDraw();
	}
	
	for (int i = 0; i < m_childNodes.size(); i++) {
		m_childNodes.at(i)->draw();
	}
}
