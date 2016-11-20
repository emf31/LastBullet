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

bool TNode::removeChild(TNode * child) {
	auto result = std::find(m_childNodes.begin(), m_childNodes.end(), child);

	if (result != m_childNodes.end()) {
		//Esta en la lista -> lo quitamos
		m_childNodes.erase(result);
		return 1;
	} else {
		return 0;
	}
}

void TNode::setModel(TModel * model) {
	m_model = model;
}

TModel * TNode::getModel() {
	return m_model;
}

TNode * TNode::getParentNode() {
	return m_parentNode;
}

void TNode::beginDraw(glm::mat4 projection, glm::mat4 view) {
	if (m_model != nullptr) {
		glm::mat4 model;
		model = glm::translate(model, position);
		model = glm::scale(model, scale);

		m_model->beginDraw(projection, view, model);
		m_model->endDraw();
	} //ELSE el modelo es null ¿cargar un modelo de "ERROR"?
	
	for (int i = 0; i < m_childNodes.size(); i++) {
		m_childNodes.at(i)->beginDraw(projection, view);
	}
}

void TNode::endDraw() {

}

void TNode::setScale(Vec3<float> scale) {
	this->scale = glm::vec3(scale.getX(),scale.getY(), scale.getZ());
}

void TNode::setPosition(Vec3<float> position) {
	this->position = glm::vec3(position.getX(), position.getY(), position.getZ());
}

void TNode::rotate(Vec3<float> rotation) {

}

