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
		//haciendo esta asignacion si luego cambio padre tambien se cambia nuevoHijo? al ser un puntero que apunta a otro puntero
		nuevoHijo = nuevoHijo->getParentNode();
		padre = padre->getParentNode();
	}
	padre->removeChild(nuevoHijo);
	//NOTA PARA NUESTROS FUTUROS YO: porque en setParent se pasa el madre de miNodo y no directamente miNodo
	//pues es bien sencillo, simplemente pork estamos en un nodo malla que son a los que se tiene acceso desde el juego
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
			//primero se dibuja el nodo actual (la entity) y luego los hijos
			//explicacion: el primer begin draw sera el nodo rotacion, se encarga de multiplicar la matriz actual por su rotacion
			//el segundo nodo es el de escala multiplica la matriz actual que ya estaba rotada y la escala
			//el tercer nodo seria el de traslacion que se encargaria de aplicar una traslacion a la matriz que ya ha sido rotada y escalada
			//el cuarto nodo ya seria el nodo malla que su begin draw se encargaria de dibujar el modelo con la rotacion,escala y posicion de la matriz actual
			getEntity()->beginDraw();//apilo la transformacion de la entidad a la matriz correspondiente
			for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
				(*it)->draw();
			}
			getEntity()->endDraw();//desapilo la transformacion que hice antes

		}
		else {
			//si es el nodo raiz se dibuja sus hijos directamente
			for (std::vector<TNode*>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); it++) {
				//si hemos vuelto a la raiz antes de pasar al siguiente hijo volvemos a resetear la matrizActual a la Identidad
				//if (getEntity() == nullptr) {
					sm.setMatrizActual(glm::mat4());
				//}
				
				(*it)->draw();
			}
			//desactivo el gBuffer que estaba activo pork hemos ido recorriendo el arbol dibujando todos los modelos

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


