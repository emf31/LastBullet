#include <Enemy.h>
#include <SparseGraph.h>
#include <vector>
#include <Vec2f.h>


#pragma once
class PathPlanner
{
public:
	PathPlanner(Enemy* bot);
	~PathPlanner();

	//encuentra el camino menos costoso hasta la posicion destino (haria una llamada
	//al metodo de buscar camino de Astar)
	bool CreatePathToPosition(Vec2f posObjetivo, std::list<Vec2f>& camino);
	//encuentra el camino menos costoso hasta un item (haria una llamada
	//al metodo de buscar camino de Astar)
	bool CreatePathToItem();
private:
	Enemy* m_Bot;
	SparseGraph& m_grafo;
	Vec2f m_posDestino;

	//este metodo delvolvera el indice del nodo disponible mas cercano a mi posicion actual
	//que es a partir del cual empezara el algoritmo de busqueda

	//estos metodos lo que tienen que hacer es buscar cuales son los nodos que estan en una celda de espacio que se define al rededor del bot, los que esten dentro de esta celda
	//seran los nodos mas cercanos, y de estos nodos mas cercanos hay que calcular su distancia con la posicion del bot y quedarte con el que menos distancia tenga.
	int getNodoMasCercanoABot(Vec2f pos) const;
	int getNodoMasCercanoAObjetivo(Vec2f pos) const;
	
	

	


};

