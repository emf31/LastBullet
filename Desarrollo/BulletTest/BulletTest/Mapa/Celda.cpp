#include "Celda.h"
#include <SparseGraph.h>
#include <Map.h>
#include <Util.h>



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
	size_t x = (int)(pos.x / m_anchoCelda);
	size_t y = (int)(pos.y / m_altoCelda);
	y = y*m_numCeldasX;
	std::size_t indice = x + y;

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
	
	
	for (size_t i = 0; i < m_Celdas.size(); i++) {
		std::cout << "****** LA CELDA " << i << " TIENE LOS NODOS **********" << std::endl;
		std::cout << "Proporciones celda: top: " << m_Celdas[i].Bbox.getTop() << " left: " << m_Celdas[i].Bbox.getLeft() << " bot: " << m_Celdas[i].Bbox.getBot() << " right: " << m_Celdas[i].Bbox.getRight() << std::endl;
		for (std::list<NavGraphNode*>::iterator it = m_Celdas[i].Nodos.begin();it!=m_Celdas[i].Nodos.end();++it)
		{
			std::cout << (*it)->Index() << "x: "<< (*it)->getPosition().x <<" y: "<< (*it)->getPosition().y << std::endl;
		}
		std::cout << "****** FIN CELDA " << i << " **********" << std::endl;
	}
}

void CellSpacePartition::CalculaNodoEnCelda(int ind, std::list<NavGraphNode*>& nodosCercanos, Vec2f& posBot)
{
	for (std::list<NavGraphNode*>::iterator it = m_Celdas[ind].Nodos.begin(); it != m_Celdas[ind].Nodos.end(); ++it)
	{
		if (!Map::i().isPathObstructed(posBot, (*it)->getPosition(), 1.2f)) {
			//std::cout << "Añado nodo: " << (*it)->Index() << "a la lista " << std::endl;
			nodosCercanos.push_back((*it));
		}

	}
}

void CellSpacePartition::CalculaNodosEnCeldasVecinas(int ind, std::list<NavGraphNode*>& nodosCercanos, std::vector<int>& celdasVecinas, Vec2f& posBot)
{

	bool esBordeDerecho = false;
	bool esBordeIzquierdo = false;
	bool esBordeArriba = false;
	bool esBordeAbajo = false;

	//con esto lo que conseguimos es saber si la celda esta en un borde izquierdo o un borde derecho
	//ya que nuestro vector es unidimensional pero estamos representando una matriz bidimensional
	if (ind%m_numCeldasX == 0) {
		//la fila de izquierda es multiplo del numCeldasdeX
		esBordeIzquierdo = true;
	}else if(ind + 1 >= m_numCeldasX && (ind + 1) % m_numCeldasX==0){
		//ind+1>= m_numCeldasX && ind+1%m_numCeldasX==0
		//la fila de la derecha sumandole 1 seria multiplo del numCeldasX
		esBordeDerecho = true;
	}

	if (ind - m_numCeldasX < 0) {
		esBordeArriba = true;
	}
	else if (ind + m_numCeldasX > ((m_numCeldasX*m_numCeldasY)-1)) {
		esBordeAbajo = true;
	}

	int arrIzq = ind - m_numCeldasX - 1;
	int arrDer = ind - m_numCeldasX + 1;
	int arriba = ind - m_numCeldasX;
	int izq = ind - 1;
	int der = ind + 1;
	int abajo = ind + m_numCeldasX;
	int abaIzq = ind + m_numCeldasX - 1;
	int abaDer = ind + m_numCeldasX + 1;
	if (esBordeIzquierdo == false) {
		if (esBordeArriba == false) {
			//arriba-izquierda
			CalculaNodoEnCelda(arrIzq, nodosCercanos, posBot);
			celdasVecinas.push_back(arrIzq);
		}

		//izquierda
		CalculaNodoEnCelda(izq, nodosCercanos,  posBot);
		celdasVecinas.push_back(izq);
		if (esBordeAbajo == false) {
			//abajo izquierda
			CalculaNodoEnCelda(abaIzq, nodosCercanos, posBot);
			celdasVecinas.push_back(abaIzq);
		}

	}
	if (esBordeDerecho == false) {
		if (esBordeArriba == false) {
			//arriba-derecha
			CalculaNodoEnCelda(arrDer, nodosCercanos, posBot);
			celdasVecinas.push_back(arrDer);
		}

		//derecha
		CalculaNodoEnCelda(der, nodosCercanos, posBot);
		celdasVecinas.push_back(der);
		if (esBordeAbajo == false) {
			//abajo derecha
			CalculaNodoEnCelda(abaDer, nodosCercanos, posBot);
			celdasVecinas.push_back(abaDer);
		}

	}
	if (esBordeArriba == false) {
		CalculaNodoEnCelda(arriba, nodosCercanos, posBot);
		celdasVecinas.push_back(arriba);
	}
	if (esBordeAbajo == false) {
		CalculaNodoEnCelda(abajo, nodosCercanos, posBot);
		celdasVecinas.push_back(abajo);
	}

}
