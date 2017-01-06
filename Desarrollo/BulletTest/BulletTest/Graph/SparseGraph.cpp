#include "SparseGraph.h"
#include "GraphEnumeration.h"


//const NavGraphNode& GetNode(int idx) { return m_nodes.at(idx); };

NavGraphNode & SparseGraph::getNode(int idx) { 
	assert((idx < (int)m_Nodes.size()) &&
		(idx >= 0) &&
		"<SparseGraph::GetNode>: invalid index");

	return m_nodes.at(idx);
}

GraphEdge& SparseGraph::getEdge(int from, int to)
{
	assert((from < m_Nodes.size()) &&
		(from >= 0) &&
		m_Nodes[from].Index() != invalid_node_index &&
		"<SparseGraph::GetEdge>: invalid 'from' index");

	assert((to < m_Nodes.size()) &&
		(to >= 0) &&
		m_Nodes[to].Index() != invalid_node_index &&
		"<SparseGraph::GetEdge>: invalid 'to' index");

	std::list<GraphEdge> aux = m_Edges.at(from);
	for (auto i = aux.begin(); i != aux.end(); ++i) {
		if (i->To() == to)
			return *i;
	}
	
	assert(0 && "<SparseGraph::GetEdge>: edge does not exist");
}

int SparseGraph::addNode(NavGraphNode node)
{
	if (node.Index() < (int)m_nodes.size()) {

		//make sure the client is not trying to add a node with the same ID as
		//a currently active node
		assert(m_nodes[node.Index()].Index() == invalid_node_index &&
			"<SparseGraph::AddNode>: Attempting to add a node with a duplicate ID");

		m_nodes.at(node.Index()) = node;
		return m_nextNodeIndex;
	}
	else {
		//make sure the new node has been indexed correctly
		assert(node.Index() == m_iNextNodeIndex && "<SparseGraph::AddNode>:invalid index");

		m_nodes.push_back(node);
		std::list<GraphEdge> edgelist;
		m_Edges.push_back(edgelist);

		return m_nextNodeIndex++;
	}

}

void SparseGraph::removeNode(int node)
{
	assert(node < (int)m_Nodes.size() && "<SparseGraph::RemoveNode>: invalid node index");


	m_nodes[node].setIndex(invalid_node_index);//pones el nodo a index invalido


	if (!m_digraph)
	{
		for (std::list<GraphEdge>::iterator curEdge = m_Edges[node].begin(); curEdge != m_Edges[node].end(); ++curEdge) //recorre todos los nodos en el vector de edges
		{
			for (std::list<GraphEdge>::iterator curE = m_Edges[curEdge->To()].begin();curE != m_Edges[curEdge->To()].end(); ++curE) //vas sacando los nodos de las listas de edges
			{
				if (curE->To() == node)
				{
					curE = m_Edges[curEdge->To()].erase(curE);

					break;
				}
			}
		}

		//finally, clear this node's edges
		m_Edges[node].clear();//por ultimo eliminas la posicion del vector del nodo de edge
	}
	else {

		for (std::vector<std::list<GraphEdge>>::iterator curEdgeList = m_Edges.begin(); curEdgeList != m_Edges.end(); ++curEdgeList)
		{
			for (std::list<GraphEdge>::iterator curEdge = (*curEdgeList).begin(); curEdge != (*curEdgeList).end(); ++curEdge)
			{
				if (m_nodes[curEdge->To()].Index() == invalid_node_index ||
					m_nodes[curEdge->From()].Index() == invalid_node_index)
				{
					curEdge = (*curEdgeList).erase(curEdge);
				}
			}
		}
	}
}

//Anade una arista al grafo, asegurandose de que no sea una arista duplicada,
//ademas si el grafo es no dirigido hay que anadir una arista en el sentido opuesto.
void SparseGraph::addEdge(GraphEdge edge)
{
	//first make sure the from and to nodes exist within the graph 
	assert((edge.From() < m_iNextNodeIndex) && (edge.To() < m_iNextNodeIndex) &&
		"<SparseGraph::AddEdge>: invalid node index");

	//make sure both nodes are active before adding the edge
	if ((m_nodes[edge.To()].Index() != invalid_node_index) &&
		(m_nodes[edge.From()].Index() != invalid_node_index))
	{
		//add the edge, first making sure it is unique
		if (UniqueEdge(edge.From(), edge.To()))
		{
			m_Edges[edge.From()].push_back(edge);
		}

		//if the graph is undirected we must add another connection in the opposite
		//direction
		if (!m_digraph)
		{
			//check to make sure the edge is unique before adding
			if (UniqueEdge(edge.To(), edge.From()))
			{
				GraphEdge NewEdge = edge;

				NewEdge.setTo(edge.From());
				NewEdge.setFrom(edge.To());

				m_Edges[edge.To()].push_back(NewEdge);
			}
		}
	}
}

void SparseGraph::removeEdge(int from, int to)
{
	assert((from < (int)m_Nodes.size()) && (to < (int)m_Nodes.size()) &&
		"<SparseGraph::RemoveEdge>:invalid node index");

	std::list<GraphEdge>::iterator curEdge;

	if (!m_digraph)
	{
		for (curEdge = m_Edges[to].begin();
			curEdge != m_Edges[to].end();
			++curEdge)
		{
			if (curEdge->To() == from) { curEdge = m_Edges[to].erase(curEdge); break; }
		}
	}

	for (curEdge = m_Edges[from].begin();
		curEdge != m_Edges[from].end();
		++curEdge)
	{
		if (curEdge->To() == to) { curEdge = m_Edges[from].erase(curEdge); break; }
	}
}

bool SparseGraph::UniqueEdge(int from, int to) const
{
	for (std::list<GraphEdge>::const_iterator curEdge = m_Edges[from].begin();
		curEdge != m_Edges[from].end();
		++curEdge)
	{
		if (curEdge->To() == to)
		{
			return false;
		}
	}

	return true;
}

int SparseGraph::numActiveNodes() const 
{
	int count = 0;

	for (unsigned int n = 0; n < m_nodes.size(); ++n) if (m_nodes[n].Index() != invalid_node_index) ++count;

	return count;
}

int SparseGraph::numEdges() 
{
	int tot = 0;

	for (std::vector<std::list<GraphEdge>>::iterator curEdge = m_Edges.begin();
		curEdge != m_Edges.end();
		++curEdge)
	{
		tot += curEdge->size();
	}

	return tot;
}

bool SparseGraph::isNodePresent(int node) const
{
	if ((m_nodes[node].Index() == invalid_node_index) || (node >= m_nodes.size()))
	{
		return false;
	}
	else return true;
}

bool SparseGraph::isEdgePresent(int from, int to)
{
	if (isNodePresent(from) && isNodePresent(from))
	{
		for (std::list<GraphEdge>::iterator curEdge = m_Edges[from].begin();
			curEdge != m_Edges[from].end();
			++curEdge)
		{
			if (curEdge->To() == to) return true;
		}

		return false;
	}
	else return false;
}

void SparseGraph::clear()
{
	m_nextNodeIndex = 0; m_nodes.clear(); m_Edges.clear();
}


