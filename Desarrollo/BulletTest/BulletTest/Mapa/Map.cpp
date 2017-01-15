#include "Map.h"
#include <GraphEdge.h>

bool Map::isPathObstructed(Vec2f posIni, Vec2f posFinal, float radio)
{
	//TODO hacer este metodo
	return false;
}

void Map::ConvertirNodosAPosiciones(std::list<int> CaminoDeNodos, std::list<Vec2f> camino)
{
	//TODO
}

Map::Map() : grafo(NULL)
{
}



void Map::inicializar()
{

	//GRAFO
	
	//True, grafo dirigido
	grafo = new SparseGraph(true);
	

	NavGraphNode nodo1(grafo->getNextFreeNodeIndex(), Vec2f(0,30));
	grafo->addNode(nodo1);

	NavGraphNode nodo2(grafo->getNextFreeNodeIndex(), Vec2f(30, 0));
	grafo->addNode(nodo2);

	NavGraphNode nodo3(grafo->getNextFreeNodeIndex(), Vec2f(0, -30));
	grafo->addNode(nodo3);

	NavGraphNode nodo4(grafo->getNextFreeNodeIndex(), Vec2f(-30, 0));
	grafo->addNode(nodo4);

	NavGraphNode nodo5(grafo->getNextFreeNodeIndex(), Vec2f(-30, 0));
	grafo->addNode(nodo5);

	NavGraphNode nodo6(grafo->getNextFreeNodeIndex(), Vec2f(-30, 0));
	grafo->addNode(nodo6);

	GraphEdge edge1(nodo1.Index(), nodo5.Index(), 2.9);
	GraphEdge edge2(nodo1.Index(), nodo6.Index(), 1.f);

	GraphEdge edge3(nodo5.Index(), nodo6.Index(), 3.f);
	GraphEdge edge4(nodo5.Index(), nodo2.Index(), 1.9);

	GraphEdge edge5(nodo6.Index(), nodo4.Index(), 1.1);
	GraphEdge edge6(nodo2.Index(), nodo3.Index(), 3.1);
	GraphEdge edge7(nodo4.Index(), nodo3.Index(), 3.7);

	GraphEdge edge8(nodo3.Index(), nodo5.Index(), 0.8);

	grafo->addEdge(edge1);
	grafo->addEdge(edge2);
	grafo->addEdge(edge3);
	grafo->addEdge(edge4);
	grafo->addEdge(edge5);
	grafo->addEdge(edge6);
	grafo->addEdge(edge7);
	grafo->addEdge(edge8);

	grafo->printGrafo();

	//AStarSearch astar(grafo, 0 , 2);
	//std::list<int> camino = astar.GetPathToTarget();


}

//TODO hacer un borrar contenido

void Map::borrarContenido() {
	delete grafo;
}
