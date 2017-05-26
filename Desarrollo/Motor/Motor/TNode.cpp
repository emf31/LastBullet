#include "TNode.h"
#include "SceneManager.h"
TNode::TNode(int entityID, TNode* nodoPadre) : sm(SceneManager::i()), visible(true)
{
	m_parentNode = nodoPadre;
	myNodeEntityID = entityID;
	m_entity = nullptr;
	
}


TNode::~TNode()
{
	for (auto it = m_childNodes.begin(); it != m_childNodes.end(); ++it) {
		delete *it;
	}

	delete m_entity;
	
}
void TNode::addChild(TNode* child) {
	//child va a ser un nodo hoja es decir, un nodo malla, nodo luz o nodo camara
	m_childNodes.push_back(child);

}

void TNode::addChild(TEntity * ent) {
	TNode* nuevoHijo = ent->getMiNodo();
	TNode* padre = ent->getMiNodo()->getParentNode();

	while (padre->getParentNode() != nullptr && padre->getMyNodeEntityID() == ent->getID()) {

		nuevoHijo = nuevoHijo->getParentNode();
		padre = padre->getParentNode();
	}
	padre->removeChild(nuevoHijo);
	//NOTA PARA NUESTROS FUTUROS YO: ¿porque en setParent se pasa el madre de miNodo y no directamente miNodo?
	//pues es bien sencillo, simplemente porque estamos en un nodo malla que son a los que se tiene acceso desde el juego
	//y el padre no puede ser el nodo malla sino la transformacion de la que depende este nodo malla , es decir, el padre del nodo malla. De nada futuro yo ;)
	nuevoHijo->setParentNode(this);
	this->addChild(nuevoHijo);

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

void TNode::removeNode()
{
	m_parentNode->removeChild(this);
	setParentNode(NULL);

	delete this;
}

TNode * TNode::getParentNode() {
	return m_parentNode;
}

void TNode::setParentNode(TNode * nodoPadre) {
	m_parentNode = nodoPadre;
}

void TNode::draw() {
	//Solo continua el arbol(recorrido de sus hijos) si el nodo es visible
	if (visible) {
		if (getEntity() != nullptr) {

			getEntity()->beginDraw();
			for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
				(*it)->draw();
			}
			getEntity()->endDraw();

		}

		else {
			//si es el nodo raiz o un nodo zona (para el clipping y oclusion mediante portales) se dibuja sus hijos directamente
			for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
				//si hemos vuelto a la raiz antes de pasar al siguiente hijo volvemos a resetear la matrizActual a la Identidad
				
				sm.setMatrizActual(glm::mat4());

				(*it)->draw();
			}
		}
	}

}
void TNode::drawSombras() {
	if (getEntity() != nullptr) {
		getEntity()->beginDrawSombras();
		for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
			(*it)->drawSombras();
		}
		getEntity()->endDraw();
	}
	else {
		for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
			sm.setMatrizActual(glm::mat4());
			(*it)->drawSombras();

		}
	}
	

}

TEntity * TNode::getEntity() {
	return m_entity;
}

void TNode::setEntity(TEntity * entidad) {
	m_entity = entidad;
}

int TNode::getMyNodeEntityID() {
	return myNodeEntityID;
}


