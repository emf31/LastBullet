#include "TNode.h"
#include "SceneManager.h"
TNode::TNode(int entityID, TNode* nodoPadre)
{
	m_parentNode = nodoPadre;
	myNodeEntityID = entityID;
	
}


TNode::~TNode()
{
	delete m_entity;
}
void TNode::addChild(TNode* child) {
	//child va a ser un nodo hoja es decir, un nodo malla, nodo luz o nodo camara
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

TNode * TNode::getParentNode() {
	return m_parentNode;
}

void TNode::setParentNode(TNode * nodoPadre) {
	m_parentNode = nodoPadre;
}

void TNode::draw() {
	if (type != T_RAIZ) {
		//primero se dibuja el nodo actual (la entity) y luego los hijos
		//explicacion: el primer begin draw sera el nodo rotacion, se encarga de multiplicar la matriz actual por su rotacion
		//el segundo nodo es el de escala multiplica la matriz actual que ya estaba rotada y la escala
		//el tercer nodo seria el de traslacion que se encargaria de aplicar una traslacion a la matriz que ya ha sido rotada y escalada
		//el cuarto nodo ya seria el nodo malla que su begin draw se encargaria de dibujar el modelo con la rotacion,escala y posicion de la matriz actual
		getEntity()->beginDraw();//apilo la transformacion de la entidad a la matriz correspondiente
		for (int i = 0; i < m_childNodes.size(); i++) {
			m_childNodes.at(i)->draw();
		}
		getEntity()->endDraw();//desapilo la transformacion que hice antes
	}
	else {
		//ELSE el modelo es null ¿cargar un modelo de "ERROR"?

		//si es el nodo raiz se dibuja sus hijos directamente
		for (int i = 0; i < m_childNodes.size(); i++) {
			//si hemos vuelto a la raiz antes de pasar al siguiente hijo volvemos a resetear la matrizActual a la Identidad
			SceneManager::i().m_matrizActual = glm::mat4();
			m_childNodes.at(i)->draw();
		}
		//desactivo el gBuffer que estaba activo pork hemos ido recorriendo el arbol dibujando todos los modelos

	}

}

TEntity * TNode::getEntity() {
	return m_entity;
}

void TNode::setEntity(TEntity * entidad) {
	m_entity = entidad;
}

T_Nodos TNode::getNodeType() {
	return type;
}

T_Nodos TNode::getType() {
	return type;
}

void TNode::setType(T_Nodos tipo) {
	type = tipo;
}

int TNode::getMyNodeEntityID() {
	return myNodeEntityID;
}


