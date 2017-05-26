#include "PathPlanner.h"
#include <Map.h>
#include <Util.h>
#include <AStarSearch.h>
#include <Dijkstra.h>


PathPlanner::PathPlanner(Enemy_Bot* bot) : m_grafo(Map::i().getGrafo())
{
	m_Bot = bot;
}


PathPlanner::~PathPlanner()
{
}

bool PathPlanner::CreatePathToPosition(Vec3<float> posObjetivo, std::list<Vec3<float>>& camino)
{
	m_posDestino = (posObjetivo);
	if (!Map::i().isPathObstructed((m_Bot->getRenderState()->getPosition()), posObjetivo, m_Bot->getRadio())) {
		camino.push_back((posObjetivo));
		return true;
	}

	int NodoMasCercanoAlBot = getNodoMasCercanoAPos((m_Bot->getRenderState()->getPosition()));
	

	if (NodoMasCercanoAlBot == -1) {
		return false;
	}


	int NodoMasCercanoAlObjetivo = getNodoMasCercanoAPos((posObjetivo));
	

	if (NodoMasCercanoAlObjetivo == -1) {
		return false;
	}


	
	AStarSearch AStar(m_grafo, NodoMasCercanoAlBot, NodoMasCercanoAlObjetivo);

	std::list<int> CaminoDeNodos = AStar.GetPathToTarget();
	if (!CaminoDeNodos.empty()) {
		Map::i().ConvertirNodosAPosiciones(CaminoDeNodos, camino);
		camino.push_back(posObjetivo);
#ifdef NAV_INFO
		std::cout << "EL NODO MAS CERCANO AL BOT en pos: " << vec3ToVec2(m_Bot->getRenderState()->getPosition()) << " es: " << m_grafo.getNode(NodoMasCercanoAlBot).Index() << "y su posion es" << m_grafo.getNode(NodoMasCercanoAlBot).getPosition() << std::endl;
		std::cout << "EL NODO MAS CERCANO AL OBJETIVO en pos: " << posObjetivo << " es: " << m_grafo.getNode(NodoMasCercanoAlObjetivo).Index() << "y su posion es" << m_grafo.getNode(NodoMasCercanoAlObjetivo).getPosition() << std::endl;
		std::cout << "-----------------NODO DE PARTIDA:  " << NodoMasCercanoAlBot << std::endl;
		std::cout << "-----------------NODO DE DESTINO:  " << NodoMasCercanoAlObjetivo << std::endl;
		std::cout << "***********************************************" << std::endl;
		std::cout << "LA LISTA DE NODOS A SEGUIR ES: " << std::endl;
		for (std::list<int>::iterator it1 = CaminoDeNodos.begin(); it1 != CaminoDeNodos.end(); ++it1) {
			std::cout << (*it1) << std::endl;
		}
		std::cout << "********************++++++++++++++++++++++++++++++++++++++++++***************************" << std::endl;
		std::cout << "LA LISTA DE POSICIONES A SEGUIR ANTES DE SUAVIZAR ES: " << std::endl;
		for (std::list<Vec2f>::iterator it2 = camino.begin(); it2 != camino.end(); ++it2) {
			std::cout << (*it2) << std::endl;
		}
		std::cout << "********************++++++++++++++++++++++++++++++++++++++++++***************************" << std::endl;
#endif // NAV_INFO

		
		//antes de salir del metodo suavizamos el camino para que sea mas natural el movimiento
		SuavizarCamino(camino);



#ifdef NAV_INFO
		std::cout << "LA LISTA DE POSICIONES A SEGUIR DESPUES DE SUAVIZAR ES: " << std::endl;
		for (std::list<Vec2f>::iterator it2 = camino.begin(); it2 != camino.end(); ++it2) {
			std::cout << (*it2) << std::endl;
		}
		std::cout << "********************++++++++++++++++++++++++++++++++++++++++++***************************" << std::endl;
#endif // NAV_INFO


		return true;
	}
	else {
		return false;
	}
}

float PathPlanner::CreatePathToItem(const std::string& tipo, std::list<Vec3<float>>& camino)
{
	std::list<int> listaNodos;
	int NodoMasCercanoAlBot = getNodoMasCercanoAPos((m_Bot->getRenderState()->getPosition()));

	if (NodoMasCercanoAlBot == -1) {

		throw std::runtime_error("Excepcion del PathPlanner");

	}
	

	Dijkstra dij(m_grafo, NodoMasCercanoAlBot, tipo);
	listaNodos = dij.getPathToTarget();
	listaNodos.push_front(NodoMasCercanoAlBot);

	Map::i().ConvertirNodosAPosiciones(listaNodos, camino);
	SuavizarCamino(camino);


	return dij.getCostToTarget();
		
	
}

bool PathPlanner::CreateRandomPath(std::list<Vec3<float>>& camino)
{

	Vec3<float> TargetPos;

	std::vector<Vec3<float>>& spawns = Map::i().getSpawnPoints();
	
	if (spawns.empty()) {
		return false;
	}

	if (spawns.size() != 1) {
		Vec3<float>& spawn = spawns.at(Randi(0, spawns.size() - 1));
		TargetPos = spawn;
	}
	else {
		TargetPos = spawns[0];
	}

	//Cogemos nodo mas cercano al bot
	int NodoMasCercanoAlBot = getNodoMasCercanoAPos((m_Bot->getRenderState()->getPosition()));
	int NodoMasCercanoAlObjetivo = getNodoMasCercanoAPos(TargetPos);

	if (NodoMasCercanoAlBot == -1 || NodoMasCercanoAlObjetivo == -1) {
		return false;
	}

	AStarSearch AStar(m_grafo, NodoMasCercanoAlBot, NodoMasCercanoAlObjetivo);

	std::list<int> CaminoDeNodos = AStar.GetPathToTarget();
	if (!CaminoDeNodos.empty()) {
		Map::i().ConvertirNodosAPosiciones(CaminoDeNodos, camino);
		if (CaminoDeNodos.size() > 1) {
			//antes de salir del metodo suavizamos el camino para que sea mas natural el movimiento
			SuavizarCamino(camino);
		}
		

		return true;
	}
	
	

	return false;
}


int PathPlanner::getNodoMasCercanoAPos(Vec3<float> pos) const
{
	std::list<NavGraphNode*> nodosCercanos;
	try {
		Map::i().CalcularNodosCercanos(pos, nodosCercanos, (m_Bot->getRenderState()->getPosition()));
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	
	float menorDist;
	float distAux;
	Vec2f vecLong;
	bool primero = true;
	int NodoMasCercano=-1;
	for (std::list<NavGraphNode*>::iterator it= nodosCercanos.begin(); it != nodosCercanos.end(); ++it) {
		if (primero == true ) {
			vecLong = (vec3ToVec2(pos) - (*it)->getPosition());
			menorDist= vecLong.Magnitude();
			NodoMasCercano = (*it)->Index();
			primero = false;
		}
		vecLong = (vec3ToVec2(pos) - (*it)->getPosition());
		distAux= vecLong.Magnitude();
		if (menorDist > distAux) {
			menorDist = distAux;
			NodoMasCercano = (*it)->Index();
		}
	}
	
	return NodoMasCercano;
}

void PathPlanner::SuavizarCamino(std::list<Vec3<float>>& listaCamino)
{
	std::list<Vec3<float>>::iterator e1(listaCamino.begin()), e2(listaCamino.begin());
	/*
	++e2;
	
	if (Map::i().isPathObstructed(vec3ToVec2(m_Bot->getRenderState()->getPosition()), *(e2), m_Bot->getRadio())) {
		//el camino esta obstruido necesitamos los 2 nodos
		++e1;
		++e2;
	}
	else {
		std::cout << "PARA suavizar el camino elimino el nodo con posicion: " << (*e1) << std::endl;
		e1=listaCamino.erase(e1);
	}
	e1 = listaCamino.begin();
	e2 = listaCamino.begin();
	*/

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
			//std::cout << "Para suavizar el camino elimino el nodo con posicion: " << (*e1) << std::endl;
			e1 = listaCamino.erase(e1);
			if (e2 != listaCamino.end()) {
				++e2;
			}
			if (e2 != listaCamino.end()) {
				++e2;
			}
			
		}
	}
}

