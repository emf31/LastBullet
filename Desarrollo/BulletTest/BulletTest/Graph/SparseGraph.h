#pragma once
#include "vector"
#include "list"
#include "GraphEdge.h"
#include "NavGraphNode.h"

class GraphEdge {
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
	void removeEdge(int from, int to);

	int numNodes()const;
	int numActiveNodes()const;
	int numEdges()const;
	bool isDigraph()const { return m_digraph; };
	bool isEmpty()const;
	bool isPresent(int node)const;//devuelve true si el nodo esta presente en el grafo
	void clear();


	class EdgeIterator
	{
	private:

		typename std::list<GraphEdge>::iterator curEdge;

		SparseGraph&  G;

		const int NodeIndex;

	public:

		EdgeIterator(SparseGraph& graph, int node) : G(graph), NodeIndex(node)
		{
			/* we don't need to check for an invalid node index since if the node is
			invalid there will be no associated edges
			*/

			curEdge = G.m_ed[NodeIndex].begin();
		}

		EdgeType*  begin()
		{
			curEdge = G.m_Edges[NodeIndex].begin();

			return &(*curEdge);
		}

		EdgeType*  next()
		{
			++curEdge;

			return &(*curEdge);

		}

		//return true if we are at the end of the edge list
		bool end()
		{
			return (curEdge == G.m_Edges[NodeIndex].end());
		}

	};
	friend class EdgeIterator;
};


//non const class used to iterate through all the edges connected to a specific node. 

