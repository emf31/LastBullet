#pragma once
#include "vector"
#include "list"
#include "GraphEdge.h"
#include "NavGraphNode.h"

class SparseGraph {
private:
	std::vector<NavGraphNode> m_nodes;
	std::vector<std::list<GraphEdge>> m_Edges;
	bool m_digraph;
	int m_nextNodeIndex;

public:

	SparseGraph(bool digraph) :m_digraph(digraph),m_nextNodeIndex(0) {};
	//const NavGraphNode& GetNode(int idx) { return m_nodes.at(idx); };
	NavGraphNode& getNode(int idx) { return m_nodes.at(idx); };
	GraphEdge& getEdge(int from,int to);
	int getNextFreeNodeIndex() const { return m_nextNodeIndex; };
	int addNode(NavGraphNode node);
	void removeNode(int node);
	void addEdge(GraphEdge edge);
	void removeNode(int node);

	int numNodes()const;
	int numActiveNodes()const;
	int numEdges()const;
	bool isDigraph()const { return m_digraph; };
	bool isEmpty()const;
	bool isPresent(int node)const;//devuelve true si el nodo esta presente en el grafo
	void clear();



};