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

	//const NavGraphNode& GetNode(int idx) { return m_nodes.at(idx); };
	NavGraphNode& getNode(int idx);;
	GraphEdge& getEdge(int from, int to);
	int getNextFreeNodeIndex() const { return m_nextNodeIndex; };
	int addNode(NavGraphNode node);
	void removeNode(int node);
	void addEdge(GraphEdge edge);
	void removeEdge(int from, int to);

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

	//returns true if an edge is not already present in the graph. Used
	//when adding edges to make sure no duplicates are created.
	bool  UniqueEdge(int from, int to)const;

	//returns the number of active + inactive nodes present in the graph
	int numNodes() const { return m_nodes.size(); };

	//returns the number of active nodes present in the graph
	int numActiveNodes() const;;

	//returns the total number of edges present in the graph
	int numEdges();

	bool isDigraph()const { return m_digraph; };
	bool isEmpty()const { return m_nodes.empty(); };

	//devuelve true si el nodo esta presente en el grafo
	bool isNodePresent(int node)const;

	//devuelve true si la arista presente en el grafo
	bool isEdgePresent(int from, int to);

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

			curEdge = G.m_Edges[NodeIndex].begin();
		}

		GraphEdge*  begin()
		{
			curEdge = G.m_Edges[NodeIndex].begin();

			return &(*curEdge);
		}

		GraphEdge*  next()
		{
			//if(!end())
			++curEdge;

			return &(*curEdge);

		}

		//return true if we are at the end of the edge list
		bool end()
		{
			//std::cout << G.m_Edges[NodeIndex].size();
			return (curEdge == G.m_Edges[NodeIndex].end());
		}

	};
	//Esto sirve para que la clase EdgeIterator
	//acceda a los private de SparseGraph
	friend class EdgeIterator;

	//const class used to iterate through all the edges connected to a specific node. 
	class ConstEdgeIterator
	{
	private:

		typename std::list<GraphEdge>::const_iterator curEdge;

		const SparseGraph&  G;

		const int   NodeIndex;

	public:

		ConstEdgeIterator(const SparseGraph & graph,
			int                           node) : G(graph),
			NodeIndex(node)
		{
			/* we don't need to check for an invalid node index since if the node is
			invalid there will be no associated edges
			*/

			curEdge = G.m_Edges[NodeIndex].begin();
		}

		const GraphEdge*  begin()
		{
			curEdge = G.m_Edges[NodeIndex].begin();

			return &(*curEdge);
		}

		const GraphEdge*  next()
		{
			++curEdge;

			return &(*curEdge);

		}

		//return true if we are at the end of the edge list
		const GraphEdge* end()
		{
			return &(*G.m_Edges[NodeIndex].end());
		}

		bool operator == (const GraphEdge& rhs) const
		{
			return *curEdge == rhs;
		}

		bool operator != (const GraphEdge& rhs) const
		{
			return *curEdge != rhs;
		}

	};

	friend class ConstEdgeIterator;

	//non const class used to iterate through the nodes in the graph
	class NodeIterator
	{
	private:

		typename std::vector<NavGraphNode>::iterator curNode;

		SparseGraph& G;

		//if a graph node is removed, it is not removed from the 
		//vector of nodes (because that would mean changing all the indices of 
		//all the nodes that have a higher index). This method takes a node
		//iterator as a parameter and assigns the next valid element to it.
		void GetNextValidNode(typename std::vector<NavGraphNode>::iterator& it)
		{
			if (curNode == G.m_nodes.end() || it->Index() != invalid_node_index) return;

			while ((it->Index() == invalid_node_index))
			{
				++it;

				if (curNode == G.m_nodes.end()) break;
			}
		}

	public:

		NodeIterator(SparseGraph &graph) :G(graph)
		{
			curNode = G.m_nodes.begin();
		}


		NavGraphNode* begin()
		{
			curNode = G.m_nodes.begin();

			GetNextValidNode(curNode);

			return &(*curNode);
		}

		NavGraphNode* next()
		{
			++curNode;

			GetNextValidNode(curNode);

			return &(*curNode);
		}

		bool end()
		{
			return (curNode == G.m_nodes.end());
		}
	};


	friend class NodeIterator;
};


//non const class used to iterate through all the edges connected to a specific node. 

