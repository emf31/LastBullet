#include "SparseGraph.h"
#include "GraphEnumeration.h"

GraphEdge& SparseGraph::getEdge(int from, int to)
{
	std::list<GraphEdge> aux = m_Edges.at(from);
	for (auto i = aux.begin(); i != aux.end(); ++i) {
		if (i->To() == to)
			return *i;
	}
	//return nullptr;
}

int SparseGraph::addNode(NavGraphNode node)
{
	if (node.Index() < (int)m_nodes.size()) {
		m_nodes.at(node.Index())=node;
		return m_nextNodeIndex;
	}
	else {
		m_nodes.push_back(node);
		std::list<GraphEdge> edgelist;
		m_Edges.push_back(edgelist);
		return m_nextNodeIndex++;
	}

}

void SparseGraph::removeNode(int node)
{
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

		for (int i=0;i<m_Edges.size();i++)
		{
			for (std::list<GraphEdge>::iterator curEdge = m_Edges[i].begin(); curEdge != m_Edges[i].end(); ++curEdge)
			{
				if (m_nodes[curEdge->To()].Index() == invalid_node_index ||
					m_nodes[curEdge->From()].Index() == invalid_node_index)
				{
					curEdge = m_Edges[i].erase(curEdge);
				}
			}
		}
	}
}


