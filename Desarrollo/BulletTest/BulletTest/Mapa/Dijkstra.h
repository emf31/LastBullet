#pragma once
#include <SparseGraph.h>



class Dijkstra {


private:
	SparseGraph& m_grafo;
	std::vector<GraphEdge*> m_ShortestPathTree;
	std::vector<float> m_CostToThisNode;
	std::vector<GraphEdge*> m_SearchFrontier;
	int m_Source;
	std::string m_tipo;
	int m_Target;

	void Search();
	bool isSatisfied(int NextClosestNode);
public:
	//le pasamos el grafo, el nodo del que partimos, y el tipo de nodo al que queremos ir (vida, pistola...)
	Dijkstra(SparseGraph& grafo, int source, const std::string& tipo) : m_grafo(grafo), m_ShortestPathTree(grafo.numNodes()),
		m_SearchFrontier(grafo.numNodes()), m_CostToThisNode(grafo.numNodes()), m_tipo(tipo), m_Source(source) {
		/*try {
			m_grafo.getNode(source);
		}
		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
		}*/

		if ((size_t)source >= 0 && (size_t)source < grafo.m_nodes.size()) {
			Search();
		}


		
	}

	std::vector<GraphEdge*> GetSPT() {
		return m_ShortestPathTree;
	}

	std::list<int> getPathToTarget();

	float getCostToTarget() {
		return m_CostToThisNode[m_Target];
	}

	float getCostToNode(int nodo) {
		return m_CostToThisNode[nodo];
	}
};