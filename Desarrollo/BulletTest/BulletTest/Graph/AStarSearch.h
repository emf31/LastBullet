#pragma once
#include <SparseGraph.h>
#include <GraphEdge.h>
#include <PriorityQueue.h>
#include <Heuristic.h>

class AStarSearch
{

private:

	SparseGraph& m_Graph;

	std::vector<double> m_GCosts;

	std::vector<double> m_FCosts;

	 std::vector<GraphEdge*> m_ShortestPathTree;
	 std::vector<GraphEdge*> m_SearchFrontier;

	int m_iSource;
	int m_iTarget;

	void Search();

public:

	AStarSearch(SparseGraph &graph, int source, int target);

	//Devolvemos todas las aristas que ha examinado el algoritmo
	std::vector<GraphEdge*> GetSPT() { return m_ShortestPathTree; }

	std::list<int> GetPathToTarget()const;

	double GetCostToTarget()const { return m_GCosts[m_iTarget]; }
};



