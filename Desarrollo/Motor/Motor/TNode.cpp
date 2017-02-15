#include "TNode.h"
#include "SceneManager.h"
TNode::TNode(TNode* nodoPadre)
{
	m_parentNode = nodoPadre;
	
}


TNode::~TNode()
{
	delete m_entity;
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

TNode * TNode::getParentNode() {
	return m_parentNode;
}

void TNode::draw() {
	if (type != T_RAIZ) {
		

		/*glm::vec3 cameraRight(view[0][0], view[1][0], view[2][0]);
		glm::vec3 cameraUp(view[0][1], view[1][1], view[2][1]);*/

		/*
		model = glm::scale(model, scale);
		//model = glm::rotate(model,rotation.x, glm::vec3(1,0,0));
		model = glm::translate(model, position);
		
		m_model->beginDraw(projection, view, model);
		for (int i = 0; i < m_childNodes.size(); i++) {
			m_childNodes.at(i)->beginDraw(projection, view);
		}
		m_model->endDraw();
		*/

		//primero se dibuja el nodo actual (la entity) y luego los hijos
		//explicacion: el primer begin draw sera el nodo rotacion, se encarga de multiplicar la matriz actual por su rotacion
		//el segundo nodo es el de escala multiplica la matriz actual que ya estaba rotada y la escala
		//el tercer nodo seria el de traslacion que se encargaria de aplicar una traslacion a la matriz que ya ha sido rotada y escalada
		//el cuarto nodo ya seria el nodo malla que su begin draw se encargaria de dibujar el modelo con la rotacion,escala y posicion de la matriz actual
		if (type ==T_MALLA) {
			//std::cout << "DIBUJO MODELO" << std::endl;
		}
		if (type == T_LUZ) {
			//std::cout << "LUUUUUUUUUZ" << std::endl;
		}
		if (type == T_ROTACION) {
			//std::cout << "ROTOOOOOOOO" << std::endl;
		}
		else if (type == T_ESCALADO) {
			//std::cout << "ESCALOOOOOOO" << std::endl;
		}
		else if (type == T_TRASLACION) {
			//std::cout << "TRASLADOOOOO" << std::endl;
		}
		getEntity()->beginDraw();//apilo la transformacion de la entidad a la matriz correspondiente
		for (int i = 0; i < m_childNodes.size(); i++) {
			m_childNodes.at(i)->draw();
		}
		getEntity()->endDraw();//desapilo la transformacion que hice antes
	}
	else {
		//ELSE el modelo es null �cargar un modelo de "ERROR"?

		//si es el nodo raiz se dibuja sus hijos directamente
		for (int i = 0; i < m_childNodes.size(); i++) {
			//si hemos vuelto a la raiz antes de pasar al siguiente hijo volvemos a resetear la matrizActual a la Identidad
			SceneManager::i().m_matrizActual = glm::mat4();
			m_childNodes.at(i)->draw();
		}
	}

}


