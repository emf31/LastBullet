#pragma once
#include <SparseGraph.h>
#include <GraphEdge.h>
#include <PriorityQueue.h>
#include <Heuristic.h>

class AStarSearch
{

private:

	SparseGraph&              m_Graph;

	//indexed into my node. Contains the 'real' accumulative cost to that node
	std::vector<double>             m_GCosts;

	//indexed into by node. Contains the cost from adding m_GCosts[n] to
	//the heuristic cost from n to the target node. This is the vector the
	//iPQ indexes into.
	std::vector<double>             m_FCosts;

	 std::vector<const GraphEdge*>       m_ShortestPathTree;
	 std::vector<const GraphEdge*>       m_SearchFrontier;

	int                            m_iSource;
	int                            m_iTarget;

	//the A* search algorithm
	void Search();

public:

	AStarSearch(SparseGraph &graph,
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

	//returns the vector of edges that the algorithm has examined
	std::vector<const GraphEdge*> GetSPT()const { return m_ShortestPathTree; }

	//returns a vector of node indexes that comprise the shortest path
	//from the source to the target
	std::list<int> GetPathToTarget()const;

	//returns the total cost to the target
	double GetCostToTarget()const { return m_GCosts[m_iTarget]; }
};

//-----------------------------------------------------------------------------
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
		SparseGraph::ConstEdgeIterator ConstEdgeItr(m_Graph, NextClosestNode);

		for (const GraphEdge* pE = ConstEdgeItr.begin(); !ConstEdgeItr.end(); pE = ConstEdgeItr.next())
		{
			//calculate the heuristic cost from this node to the target (H)                       
			double HCost = Heuristic_Euclid::Calculate(m_Graph, m_iTarget, pE->To());

			//calculate the 'real' cost to this node from the source (G)
			double GCost = m_GCosts[NextClosestNode] + pE->Cost();

			//if the node has not been added to the frontier, add it and update
			//the G and F costs
			if (m_SearchFrontier[pE->To()] == NULL)
			{
				m_FCosts[pE->To()] = GCost + HCost;
				m_GCosts[pE->To()] = GCost;

				pq.insert(pE->To());

				m_SearchFrontier[pE->To()] = pE;
			}

			//if this node is already on the frontier but the cost to get here
			//is cheaper than has been found previously, update the node
			//costs and frontier accordingly.
			else if ((GCost < m_GCosts[pE->To()]) && (m_ShortestPathTree[pE->To()] == NULL))
			{
				m_FCosts[pE->To()] = GCost + HCost;
				m_GCosts[pE->To()] = GCost;

				pq.ChangePriority(pE->To());

				m_SearchFrontier[pE->To()] = pE;
			}
		}
	}
}

//-----------------------------------------------------------------------------
std::list<int> AStarSearch::GetPathToTarget()const
{
	std::list<int> path;

	//just return an empty path if no target or no path found
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
