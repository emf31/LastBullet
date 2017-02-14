#include <Dijkstra.h>
#include <PriorityQueue.h>

void Dijkstra::Search()
{
	IndexedPriorityQLow<float> pq(m_CostToThisNode, m_grafo.numNodes());
	pq.insert(m_Source);
	while (!pq.empty()) {
		int NextClosestNode = pq.Pop();
		m_ShortestPathTree[NextClosestNode] = m_SearchFrontier[NextClosestNode];
		if (isSatisfied(NextClosestNode)) return;

		for (std::list<GraphEdge>::iterator curEdge = m_grafo.m_Edges[NextClosestNode].begin(); curEdge != m_grafo.m_Edges[NextClosestNode].end(); ++curEdge) {
			float NewCost = m_CostToThisNode[NextClosestNode] + curEdge->Cost();

			if (m_SearchFrontier[curEdge->To()] == 0) {
				m_CostToThisNode[curEdge->To()] = NewCost;
				pq.insert(curEdge->To());
				m_SearchFrontier[curEdge->To()] = &(*curEdge);
			}else if (NewCost < m_CostToThisNode[curEdge->To()] && (m_ShortestPathTree[curEdge->To()] == 0)) {
				m_CostToThisNode[curEdge->To()] = NewCost;
				pq.ChangePriority(curEdge->To());
				m_SearchFrontier[curEdge->To()] = &(*curEdge);
			}
		}
		
	}
}

bool Dijkstra::isSatisfied(int NextClosestNode)
{

	bool satisfied = false;
	NavGraphNode& nodo = m_grafo.getNode(NextClosestNode);

	if (nodo.extraInfo() != NULL && nodo.extraInfo()->getClassName() == m_tipo) {
		satisfied = true;
		m_Target = nodo.Index();
	}
	return satisfied;
}

std::list<int> Dijkstra::getPathToTarget()
{
	std::list<int> path;
	if (m_Target < 0) {
		return path;
	}

	int nodo = m_Target;
	path.push_front(nodo);

	while ((nodo != m_Source) && (m_ShortestPathTree[nodo] != 0)) {
		nodo = m_ShortestPathTree[nodo]->From();
		path.push_front(nodo);
	}
	return path;
}
