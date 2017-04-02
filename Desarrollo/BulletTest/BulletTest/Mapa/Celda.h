#pragma once

#include <BoundingBox.h>
#include <list>
#include <vector>
#include <Vec2f.h>
#include <NavGraphNode.h>


struct Celda {
	std::list<NavGraphNode*> Nodos;

	BoundingBox Bbox;

	Celda(float top, float left, float right, float bot){
		Bbox = BoundingBox(top, left, right, bot);
	}

};

class CellSpacePartition {
private:
	std::vector<Celda> m_Celdas;

	float m_anchoMapa;
	float m_altoMapa;

	int m_numCeldasX;
	int m_numCeldasY;

	float m_anchoCelda;
	float m_altoCelda;

	//en este metodo le pasas tu posicion y te devuelve el indice de la celda en la que estas
	
public:

	CellSpacePartition(float width, float height, int celdasX, int celdasY);

	int PositionToIndex(float posX, float posY);

	void addNodoACelda(NavGraphNode& nodo);

	void mostrarContenido();

	bool CalculaNodoEnCelda(int ind, std::list<NavGraphNode*>& nodosCercanos, std::vector<int>& celdasVecinas, Vec3<float>& posBot);

	void CalculaNodosEnCeldasVecinas(int ind, std::list<NavGraphNode*>& nodosCercanos, std::vector<int>& celdasVecinas, Vec3<float>& posBot);

};
