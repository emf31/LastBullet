#include <AStarSearch.h>

AStarSearch::AStarSearch(SparseGraph &graph,
	int   source,
	int   target) :m_Graph(graph),
	m_ShortestPathTree(graph.numNodes()),
	m_SearchFrontier(graph.numNodes()),
	m_GCosts(graph.numNodes(), 0.0),
	m_FCosts(graph.numNodes(), 0.0),
	m_iSource(source),
	m_iTarget(target)
{
	Search();
}


//Algoritmo de busqueda A*
void AStarSearch::Search()
{

	//Lista ordenada donde el menor coste F se pone en el principio
	IndexedPriorityQLow<double> pq(m_FCosts, m_Graph.numNodes());

	pq.insert(m_iSource);

	while (!pq.empty())
	{
		int NextClosestNode = pq.Pop();

		m_ShortestPathTree[NextClosestNode] = m_SearchFrontier[NextClosestNode];

		if (NextClosestNode == m_iTarget) return;


		for (std::list<GraphEdge>::iterator curEdge = m_Graph.m_Edges[NextClosestNode].begin(); curEdge != m_Graph.m_Edges[NextClosestNode].end(); ++curEdge)
		{

			double HCost = Heuristic_Euclid::Calculate(m_Graph, m_iTarget, curEdge->To());


			double GCost = m_GCosts[NextClosestNode] + curEdge->Cost();

			if (m_SearchFrontier[curEdge->To()] == NULL)
			{
				m_FCosts[curEdge->To()] = GCost + HCost;
				m_GCosts[curEdge->To()] = GCost;

				pq.insert(curEdge->To());

				m_SearchFrontier[curEdge->To()] = &(*curEdge);
			}

			else if ((GCost < m_GCosts[curEdge->To()]) && (m_ShortestPathTree[curEdge->To()] == NULL))
			{
				m_FCosts[curEdge->To()] = GCost + HCost;
				m_GCosts[curEdge->To()] = GCost;

				pq.ChangePriority(curEdge->To());

				m_SearchFrontier[curEdge->To()] = &(*curEdge);
			}
		}

	}
}


//Devuelve el camino de nodos hasta el objetivo
std::list<int> AStarSearch::GetPathToTarget()const
{
	std::list<int> path;

	if (m_iTarget < 0)  return path;

	int nd = m_iTarget;

	path.push_front(nd);

	while ((nd != m_iSource) && (m_ShortestPathTree[nd] != 0))
	{
		nd = m_ShortestPathTree[nd]->From();

		path.push_front(nd);
	}

	return path;
}