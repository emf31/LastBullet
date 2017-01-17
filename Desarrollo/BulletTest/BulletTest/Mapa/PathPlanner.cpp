#include "PathPlanner.h"
#include <Map.h>
#include <Util.h>
#include <AStarSearch.h>


PathPlanner::PathPlanner(Enemy* bot) : m_grafo(Map::i().getGrafo())
{
	m_Bot = bot;
}


PathPlanner::~PathPlanner()
{
}

bool PathPlanner::CreatePathToPosition(Vec2f posObjetivo, std::list<Vec2f>& camino)
{
	m_posDestino = posObjetivo;
	if (!Map::i().isPathObstructed(vec3ToVec2(m_Bot->getRenderPosition()), posObjetivo, m_Bot->getRadio())) {
		camino.push_back(posObjetivo);
		return true;
	}

	int NodoMasCercanoAlBot = getNodoMasCercanoAPos(vec3ToVec2(m_Bot->getRenderPosition()));

	if (NodoMasCercanoAlBot == -1) {
		return false;
	}


	int NodoMasCercanoAlObjetivo = getNodoMasCercanoAPos(posObjetivo);

	if (NodoMasCercanoAlObjetivo == -1) {
		return false;
	}

	AStarSearch AStar(m_grafo, NodoMasCercanoAlBot, NodoMasCercanoAlObjetivo);

	std::list<int> CaminoDeNodos = AStar.GetPathToTarget();
	if (!CaminoDeNodos.empty()) {
		Map::i().ConvertirNodosAPosiciones(CaminoDeNodos, camino);
		camino.push_back(posObjetivo);

		//antes de salir del metodo suavizamos el camino para que sea mas natural el movimiento
		SuavizarCamino(camino);
		return true;
	}
	else {
		return false;
	}
}

bool PathPlanner::CreatePathToItem()
{
	//TODO
	return false;
}


int PathPlanner::getNodoMasCercanoAPos(Vec2f pos) const
{
	std::list<NavGraphNode> nodosCercanos;
	Map::i().CalcularNodosCercanos(pos, nodosCercanos);
	float menorDist;
	float distAux;
	Vec2f vecLong;
	bool primero = true;
	int NodoMasCercano=-1;
	for (std::list<NavGraphNode>::iterator it= nodosCercanos.begin(); it != nodosCercanos.end(); ++it) {
		if (primero == false) {
			vecLong = (pos - it->getPosition());
			menorDist= vecLong.Magnitude();
			NodoMasCercano = it->Index();
		}
		vecLong = (pos - it->getPosition());
		distAux= vecLong.Magnitude();
		if (menorDist > distAux) {
			menorDist = distAux;
			NodoMasCercano = it->Index();
		}
	}
	
	return NodoMasCercano;
}

void PathPlanner::SuavizarCamino(std::list<Vec2f>& listaCamino)
{
	std::list<Vec2f>::iterator e1(listaCamino.begin()), e2(listaCamino.begin());
	//pasamos 2 nodos siguientes para ver si podemos saltarnos el del medio
	++e2;
	++e2;

	while (e2 != listaCamino.end()) {
		if (Map::i().isPathObstructed(*(e1), *(e2), m_Bot->getRadio())) {
			//el camino esta obstruido necesitamos los 2 nodos
			++e1;
			++e2;
		}
		else {
			//el camino no esta obstruido saltamos el nodo central

			//lo que hace es ponerse en el nodo central, el que se puede eliminar con ++e1,
			//elimina este nodo y e1 pasaria al siguiente nodo, avanzamos e2 2 nodos hacia delante 
			//para volver a repetir el proceso y ver si se puede eliminar el nodo que hay nuevamente
			//entre e1 y e2
			++e1;
			e1 = listaCamino.erase(e1);
			++e2;
			++e2;
		}
	}
}
