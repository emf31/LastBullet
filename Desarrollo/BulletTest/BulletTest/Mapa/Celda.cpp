#include "Celda.h"
#include <SparseGraph.h>



CellSpacePartition::CellSpacePartition(float width, float height, int celdasX, int celdasY) {
	m_anchoMapa = width;
	m_altoMapa = height;
	m_numCeldasX = celdasX;
	m_numCeldasY = celdasY;

	//dimension de cada celda
	m_anchoCelda = width / celdasX;
	m_altoCelda = height / celdasY;

	//creacion de celdas
	for (int y = 0; y < m_numCeldasY; y++) {
		for (int x = 0; x < m_numCeldasX; x++) {
			float top = y * m_altoCelda;
			float left = x * m_anchoCelda;
			float right = left + m_anchoCelda;
			float bot = top + m_altoCelda;

			//metemos cada celda del mapa al vector de celdas
			m_Celdas.push_back(Celda(top, left, right, bot));
		}
	}
}

int CellSpacePartition::PositionToIndex(Vec2f& pos) {
	//int indice = (int)(m_numCeldasX * pos.x / m_anchoCelda) + ((int)((m_numCeldasY)*pos.y / m_altoCelda)*m_numCeldasX);
	//int indice = (int)(pos.x / m_anchoCelda) + (int)(pos.y / m_altoCelda);
	int x = (int)(pos.x / m_anchoCelda);
	int y = (int)(pos.y / m_altoCelda);
	y = y*m_numCeldasX;
	int indice = x + y;

	if (indice > m_Celdas.size() - 1) {
		indice = m_Celdas.size() - 1;
	}
	return indice;
}

void CellSpacePartition::addNodoACelda(NavGraphNode& nodo) {
	int indice = PositionToIndex(nodo.getPosition());
	m_Celdas[indice].Nodos.push_back(&nodo);
}

void CellSpacePartition::mostrarContenido()
{
	
	
	for (int i = 0; i < m_Celdas.size(); i++) {
		std::cout << "****** LA CELDA " << i << " TIENE LOS NODOS **********" << std::endl;
		std::cout << "Proporciones celda: top: " << m_Celdas[i].Bbox.getTop() << " left: " << m_Celdas[i].Bbox.getLeft() << " bot: " << m_Celdas[i].Bbox.getBot() << " right: " << m_Celdas[i].Bbox.getRight() << std::endl;
		for (std::list<NavGraphNode*>::iterator it = m_Celdas[i].Nodos.begin();it!=m_Celdas[i].Nodos.end();++it)
		{
			std::cout << (*it)->Index() << "x: "<< (*it)->getPosition().x <<" y: "<< (*it)->getPosition().y << std::endl;
		}
		std::cout << "****** FIN CELDA " << i << " **********" << std::endl;
	}
}
