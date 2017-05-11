#include "Celda.h"
#include <SparseGraph.h>
#include <Map.h>
#include <Util.h>
#include <GraphicEngine.h>



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

			/*GraphicEngine::i().createNode(Vec3<float>(left, 10, top*-1), Vec3<float>(1, 1, 1), "", "../media/box.obj");
			GraphicEngine::i().createNode(Vec3<float>(left, 10, bot*-1), Vec3<float>(1, 1, 1), "", "../media/box.obj");
			GraphicEngine::i().createNode(Vec3<float>(right, 10, top*-1), Vec3<float>(1, 1, 1), "", "../media/box.obj");
			GraphicEngine::i().createNode(Vec3<float>(right, 10, bot*-1), Vec3<float>(1, 1, 1), "", "../media/box.obj");*/
			//metemos cada celda del mapa al vector de celdas
			m_Celdas.push_back(Celda(top, left, right, bot));
		}
	}
}

int CellSpacePartition::PositionToIndex(float posX, float posY) {
	//int indice = (int)(m_numCeldasX * pos.x / m_anchoCelda) + ((int)((m_numCeldasY)*pos.y / m_altoCelda)*m_numCeldasX);
	//int indice = (int)(pos.x / m_anchoCelda) + (int)(pos.y / m_altoCelda);
	float auxY = -posY;
	size_t x = (int)(posX/ m_anchoCelda);
	size_t y = (int)(auxY / m_altoCelda);
	y = y*m_numCeldasX;
	std::size_t indice = x + y;

	if (indice > m_Celdas.size() - 1) {
		indice = m_Celdas.size() - 1;
	}
	return indice;
}

void CellSpacePartition::addNodoACelda(NavGraphNode& nodo) {
	int indice = PositionToIndex(nodo.getPosition().x,nodo.getPosition().y);
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

bool CellSpacePartition::CalculaNodoEnCelda(int ind, std::list<NavGraphNode*>& nodosCercanos, std::vector<int>& celdasVecinas, Vec3<float>& posBot)
{
	if (ind >= 0 && ind < m_numCeldasX*m_numCeldasY) {

	for (std::list<NavGraphNode*>::iterator it = m_Celdas[ind].Nodos.begin(); it != m_Celdas[ind].Nodos.end(); ++it)
	{
		Vec3<float>position3D = Vec3<float>((*it)->getPosition().x, (*it)->getHeight(), (*it)->getPosition().y);
		if (!Map::i().isPathObstructed(posBot, position3D, 1.2f)) {
			//std::cout << "Añado nodo: " << (*it)->Index() << "a la lista " << std::endl;
			nodosCercanos.push_back((*it));
			celdasVecinas.push_back(ind);
		}

	}
	return true;
	}
	return false;
}

void CellSpacePartition::CalculaNodosEnCeldasVecinas(int ind, std::list<NavGraphNode*>& nodosCercanos, std::vector<int>& celdasVecinas, Vec3<float>& posBot)
{


	int arrIzq = ind - m_numCeldasX - 1;
	int arrDer = ind - m_numCeldasX + 1;
	int arriba = ind - m_numCeldasX;
	int izq = ind - 1;
	int der = ind + 1;
	int abajo = ind + m_numCeldasX;
	int abaIzq = ind + m_numCeldasX - 1;
	int abaDer = ind + m_numCeldasX + 1;


	CalculaNodoEnCelda(arrIzq, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(arrDer, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(arriba, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(izq, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(der, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(abajo, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(abaIzq, nodosCercanos, celdasVecinas, posBot);
	CalculaNodoEnCelda(abaDer, nodosCercanos, celdasVecinas, posBot);


}
