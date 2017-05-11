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

	//create an indexed priority queue of nodes. The nodes with the
	//lowest overall F cost (G+H) are positioned at the front.
	IndexedPriorityQLow<double> pq(m_FCosts, m_Graph.numNodes());

	//put the source node on the queue
	pq.insert(m_iSource);

	//while the queue is not empty
	while (!pq.empty())
	{
		//get lowest cost node from the queue
		int NextClosestNode = pq.Pop();

		//move this node from the frontier to the spanning tree
		m_ShortestPathTree[NextClosestNode] = m_SearchFrontier[NextClosestNode];

		//if the target has been found exit
		if (NextClosestNode == m_iTarget) return;

		//now to test all the edges attached to this node
		//SparseGraph::ConstEdgeIterator ConstEdgeItr(m_Graph, NextClosestNode);

		for (std::list<GraphEdge>::iterator curEdge = m_Graph.m_Edges[NextClosestNode].begin(); curEdge != m_Graph.m_Edges[NextClosestNode].end(); ++curEdge)
		{
			//calculate the heuristic cost from this node to the target (H)                       
			double HCost = Heuristic_Euclid::Calculate(m_Graph, m_iTarget, curEdge->To());

			//calculate the 'real' cost to this node from the source (G)
			double GCost = m_GCosts[NextClosestNode] + curEdge->Cost();

			//if the node has not been added to the frontier, add it and update
			//the G and F costs
			if (m_SearchFrontier[curEdge->To()] == NULL)
			{
				m_FCosts[curEdge->To()] = GCost + HCost;
				m_GCosts[curEdge->To()] = GCost;

				pq.insert(curEdge->To());

				m_SearchFrontier[curEdge->To()] = &(*curEdge);
			}

			//if this node is already on the frontier but the cost to get here
			//is cheaper than has been found previously, update the node
			//costs and frontier accordingly.
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