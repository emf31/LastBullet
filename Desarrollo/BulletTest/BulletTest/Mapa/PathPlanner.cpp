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

	int NodoMasCercanoAlBot = getNodoMasCercanoABot(vec3ToVec2(m_Bot->getRenderPosition()));

	if (NodoMasCercanoAlBot == -1) {
		return false;
	}


	int NodoMasCercanoAlObjetivo = getNodoMasCercanoAObjetivo(posObjetivo);

	if (NodoMasCercanoAlObjetivo == -1) {
		return false;
	}

	AStarSearch AStar(m_grafo, NodoMasCercanoAlBot, NodoMasCercanoAlObjetivo);

	std::list<int> CaminoDeNodos = AStar.GetPathToTarget();
	if (!CaminoDeNodos.empty()) {
		Map::i().ConvertirNodosAPosiciones(CaminoDeNodos, camino);
		camino.push_back(posObjetivo);
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

int PathPlanner::getNodoMasCercanoABot(Vec2f pos) const
{
	//TODO
	return -1;
}

int PathPlanner::getNodoMasCercanoAObjetivo(Vec2f pos) const
{

	//TODO 
	return -1;
}
