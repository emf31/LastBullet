#pragma once
#include <vector>
#include <list>
#include <cassert>
#include <GraphEdge.h>
#include <NavGraphNode.h>
#include <GraphEnumeration.h>



class SparseGraph {
private:


	bool m_digraph;
	int m_nextNodeIndex;

public:
	std::vector<std::list<GraphEdge>> m_Edges;
	std::vector<NavGraphNode> m_nodes;
	SparseGraph(bool digraph) : m_digraph(digraph), m_nextNodeIndex(0) {};
	~SparseGraph() {};

	NavGraphNode& getNode(int idx);;
	GraphEdge& getEdge(int from, int to);
	int getNextFreeNodeIndex() const { return m_nextNodeIndex; };
	int addNode(NavGraphNode node);
	void removeNode(int node);
	void addEdge(GraphEdge edge);
	void removeEdge(int from, int to);

	void readGraph(const std::string& path);

	void printGrafo() {
		for (std::vector<std::list<GraphEdge>>::iterator curEdgeList = m_Edges.begin(); curEdgeList != m_Edges.end(); ++curEdgeList)
		{
			std::cout << "Nodo " << (*curEdgeList).begin()->From() << std::endl;

			for (std::list<GraphEdge>::iterator curEdge = (*curEdgeList).begin(); curEdge != (*curEdgeList).end(); ++curEdge)
			{
				std::cout << "  " << curEdge->To();
			}

			std::cout << std::endl;
		}


	}


	//numero de nodos
	int numNodes() const { return m_nodes.size(); };

	//numero de nodos activos
	int numActiveNodes() const;;

	// numero total de aristas
	int numEdges();

	bool isDigraph()const { return m_digraph; };
	bool isEmpty()const { return m_nodes.empty(); };

	//devuelve true si el nodo esta presente en el grafo
	bool isNodePresent(int node)const;

	//devuelve true si la arista presente en el grafo
	bool isEdgePresent(int from, int to);

	void clear();



};